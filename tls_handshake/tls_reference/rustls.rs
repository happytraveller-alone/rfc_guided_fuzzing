// binder 校验
fn check_binder(
    &self,
    suite: &'static Tls13CipherSuite,
    client_hello: &Message<'_>,
    psk: &[u8],
    binder: &[u8],
) -> bool {
    let binder_plaintext = match &client_hello.payload {
        MessagePayload::Handshake { parsed, .. } => parsed.encoding_for_binder_signing(),
        _ => unreachable!(),
    };

    let handshake_hash = self
        .transcript
        .hash_given(&binder_plaintext);

    let key_schedule = KeyScheduleEarly::new(suite, psk);
    let real_binder =
        key_schedule.resumption_psk_binder_key_and_sign_verify_data(&handshake_hash);

    ConstantTimeEq::ct_eq(real_binder.as_ref(), binder).into()
}

// binder的加密原文获取
/// This implements the horrifying TLS1.3 hack where PSK binders have a
/// data dependency on the message they are contained within.
pub(super) fn fill_in_psk_binder(
    resuming: &persist::Tls13ClientSessionValue,
    transcript: &HandshakeHashBuffer,
    hmp: &mut HandshakeMessagePayload<'_>,
) -> KeyScheduleEarly {
    // We need to know the hash function of the suite we're trying to resume into.
    let suite = resuming.suite();
    let suite_hash = suite.common.hash_provider;

    // The binder is calculated over the clienthello, but doesn't include itself or its
    // length, or the length of its container.
    let binder_plaintext = hmp.encoding_for_binder_signing();
    let handshake_hash = transcript.hash_given(suite_hash, &binder_plaintext);

    // Run a fake key_schedule to simulate what the server will do if it chooses
    // to resume.
    let key_schedule = KeyScheduleEarly::new(suite, resuming.secret());
    let real_binder = key_schedule.resumption_psk_binder_key_and_sign_verify_data(&handshake_hash);

    if let HandshakePayload::ClientHello(ref mut ch) = hmp.payload {
        ch.set_psk_binder(real_binder.as_ref());
    };

    key_schedule
}

// binder的计算
pub(crate) fn resumption_psk_binder_key_and_sign_verify_data(
    &self,
    hs_hash: &hash::Output,
) -> hmac::Tag {
    let resumption_psk_binder_key = self
        .ks
        .derive_for_empty_hash(SecretKind::ResumptionPskBinderKey);
    self.ks
        .sign_verify_data(&resumption_psk_binder_key, hs_hash)
}

/// Derive a secret of given `kind` using the hash of the empty string
/// for the handshake hash.  Useful only for
/// `SecretKind::ResumptionPSKBinderKey` and
/// `SecretKind::DerivedSecret`.
fn derive_for_empty_hash(&self, kind: SecretKind) -> OkmBlock {
    let empty_hash = self
        .suite
        .common
        .hash_provider
        .start()
        .finish();
    self.derive(kind, empty_hash.as_ref())
}
