// File count: 292
// Total lines: 54
-----------------------------------------
__int64 __fastcall DeserializeCertContext(
        const struct _CERT_CONTEXT **ppvContext,
        unsigned __int8 *a2,
        unsigned int a3)
{
  unsigned __int64 v3; // rbx
  __int64 v6; // r8
  unsigned int v7; // edi
  HCERTSTORE v8; // rbp
  unsigned int v9; // ebx
  __int64 v10; // r8
  int v12; // [rsp+40h] [rbp-18h] BYREF
  unsigned __int8 *v13; // [rsp+48h] [rbp-10h]

  v3 = a3;
  if ( a3 >= 4 )
  {
    v6 = *(unsigned int *)a2;
    v12 = v6;
    v13 = a2 + 4;
    if ( (unsigned int)v6 < 0xFFFFFFFA && v3 >= v6 + 4 )
    {
      v7 = 0;
      v8 = CertOpenStore((LPCSTR)6, 1u, 0i64, 4u, &v12);
      if ( v8 )
      {
        v9 = -4 - v12 + v3;
        if ( v9 >= 4 )
        {
          v10 = *(unsigned int *)&a2[v12 + 4];
          if ( (unsigned int)v10 < 0xFFFFFFFA && v9 >= (unsigned __int64)(v10 + 4) )
          {
            if ( CertAddSerializedElementToStore(v8, &a2[v12 + 8], v10, 2u, 0, 2u, 0i64, (const void **)ppvContext) )
            {
LABEL_9:
              CertCloseStore(v8, 0);
              return v7;
            }
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
            {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 46i64, &WPP_66cada2652f531372f2ad4492a08a619_Traceguids);
            }
          }
        }
        v7 = -2146893043;
        goto LABEL_9;
      }
    }
  }
  return 2148074253i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
