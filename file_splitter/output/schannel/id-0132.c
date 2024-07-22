//----- (000000018000AE3C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::GenerateSsl3TlsClientHello(CSsl3TlsClientContext *this, struct SPBuffer *a2)
{
  CSsl3TlsClientContext *v3; // rbx
  ULONG Random; // eax
  __int64 v5; // rdx
  unsigned int v6; // r8d
  __int64 result; // rax
  int v8; // ecx
  __int64 v9; // rax
  unsigned int v10; // [rsp+20h] [rbp-1B8h]
  __int128 v11; // [rsp+40h] [rbp-198h] BYREF
  char v12[352]; // [rsp+50h] [rbp-188h] BYREF

  v3 = this;
  v11 = 0i64;
  if ( !*((_DWORD *)this + 327) || *((_DWORD *)this + 17) == 4 )
  {
    Random = CSsl3TlsContext::TlsGenerateRandom(this);
    this = (CSsl3TlsClientContext *)Random;
    if ( Random )
    {
LABEL_12:
      if ( *((_BYTE *)v3 + 233) )
      {
        if ( (_DWORD)this )
          return (unsigned int)this;
        v9 = *((_QWORD *)&v11 + 1);
        if ( !*((_QWORD *)&v11 + 1) )
          return (unsigned int)this;
        if ( !*((_DWORD *)v3 + 327) || *((_DWORD *)v3 + 17) == 4 )
        {
          LODWORD(this) = CSsl3TlsContext::DtlsGetOutgoingRecord(v3, (struct SPBuffer *)&v11, a2);
          return (unsigned int)this;
        }
      }
      else
      {
        v9 = *((_QWORD *)&v11 + 1);
      }
      *((_QWORD *)a2 + 1) = v9;
      *(_QWORD *)a2 = v11;
      return (unsigned int)this;
    }
  }
  if ( (*((_DWORD *)v3 + 16) & 0x80800) == 0 )
  {
LABEL_8:
    if ( *((_BYTE *)v3 + 233) )
      v8 = *((_DWORD *)v3 + 16);
    else
      v8 = 2720;
    LODWORD(this) = CSslContext::GenerateHelloMessage(
                      v3,
                      (struct _Ssl2_Client_Hello *)v12,
                      (unsigned int)v8 & *(_DWORD *)(*((_QWORD *)v3 + 10) + 152i64),
                      (unsigned __int8 *)v3 + 272,
                      v10,
                      (unsigned __int16 **)v3 + 114,
                      (unsigned __int16 *)v3 + 460);
    if ( !(_DWORD)this )
      LODWORD(this) = CSsl3TlsClientContext::PackClientHello(
                        v3,
                        (struct _Ssl2_Client_Hello *)v12,
                        (struct SPBuffer *)&v11);
    goto LABEL_12;
  }
  CCipherMill::GetSignatureSuiteList(this, (CSsl3TlsClientContext *)((char *)v3 + 474));
  v5 = *((_QWORD *)v3 + 10);
  v6 = *(_DWORD *)(v5 + 196);
  if ( !v6 )
    goto LABEL_7;
  result = CTlsSignatureSuiteList::Blacklist(
             (CSsl3TlsClientContext *)((char *)v3 + 474),
             *(struct _TLS_PARAMETERS **)(v5 + 200),
             v6);
  if ( (_DWORD)result )
    return result;
  if ( *((_WORD *)v3 + 237) )
  {
LABEL_7:
    *((_BYTE *)v3 + 925) = 1;
    goto LABEL_8;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_13477250810f3961702f89c94d47ffd6_Traceguids);
  return 2148074289i64;
}
// 18000AF1E: variable 'v10' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

