//----- (000000018005A36C) ----------------------------------------------------
CTls13ClientContext *__fastcall CTls13ClientContext::CTls13ClientContext(
        CTls13ClientContext *this,
        struct CTlsRecord *a2,
        struct CSessionCacheClientItem *a3,
        int a4,
        unsigned __int16 *a5)
{
  __int64 v7; // r8
  _QWORD *v8; // rcx
  CTls13ClientContext *result; // rax

  CSsl3TlsClientContext::CSsl3TlsClientContext(this, a3, a4, a5);
  CTls13Context::CTls13Context((CTls13ClientContext *)((char *)this + 1368), a2);
  v7 = *((_QWORD *)this + 197);
  *v8 = &CTls13ClientContext::`vftable'{for `CTls13Context'};
  *(_QWORD *)this = &CTls13ClientContext::`vftable'{for `CSsl3TlsClientContext'};
  CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::CTls13Handshake<CTls13ClientContext,CTls13ExtClient>(
    (__int64)this + 1656,
    (__int64)this,
    v7);
  *((_QWORD *)this + 207) = &CTls13ClientHandshake::`vftable';
  *((_QWORD *)this + 227) = 0i64;
  *((_WORD *)this + 912) = 0;
  *((_QWORD *)this + 229) = 0i64;
  *((_QWORD *)this + 230) = 0i64;
  *((_WORD *)this + 924) = 0;
  *((_DWORD *)this + 463) = *((_DWORD *)this + 16);
  result = this;
  *((_BYTE *)this + 1850) = 1;
  return result;
}
// 18005A3B6: variable 'v8' is possibly undefined
// 18007D550: using guessed type void *CTls13ClientHandshake::`vftable';
// 18007FAE0: using guessed type void *CTls13ClientContext::`vftable'{for `CSsl3TlsClientContext'};
// 18007FCF0: using guessed type void *CTls13ClientContext::`vftable'{for `CTls13Context'};

