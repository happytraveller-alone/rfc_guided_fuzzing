// File count: 299
// Total lines: 9
------------------------------------------
void __fastcall CSslCredential::ReleaseEphemeralKeyData(CSslCredential *this, struct CEphemKeyData *a2)
{
  if ( a2 )
  {
    if ( _InterlockedExchangeAdd((volatile signed __int32 *)a2 + 7, 0xFFFFFFFF) == 1 )
      (*(void (__fastcall **)(struct CEphemKeyData *, __int64))(*(_QWORD *)a2 + 8i64))(a2, 1i64);
  }
}
