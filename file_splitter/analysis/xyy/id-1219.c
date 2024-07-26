//----- (0000000180061214) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::ParseDistinguishedNameList(
        CSsl3TlsClientContext *this,
        unsigned __int8 *a2,
        unsigned int a3)
{
  unsigned int v6; // ebp
  int v7; // eax
  unsigned int v8; // esi
  __int16 v9; // r14
  unsigned __int8 *v10; // rax
  unsigned __int8 *v11; // rsi
  unsigned int v12; // ebx
  void *v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // [rsp+50h] [rbp+18h] BYREF

  if ( a3 < 2 )
    return 2148074278i64;
  if ( !a2 )
    return 2148074244i64;
  v6 = a3 - 2;
  if ( a3 - 2 < (a2[1] | (*a2 << 8)) )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 400, -2146893018, 0x32u);
    return 2148074278i64;
  }
  v15 = 0;
  v7 = FormatIssuerList(a2 + 2, v6, 0i64, &v15);
  v8 = v7;
  if ( v7 )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 401, v7, 0x2Fu);
    return v8;
  }
  else
  {
    v9 = v15;
    v10 = (unsigned __int8 *)SPExternalAlloc(v15 + 2);
    v11 = v10;
    if ( v10 )
    {
      v10[1] = v9;
      *v10 = HIBYTE(v9);
      v12 = FormatIssuerList(a2 + 2, v6, v10 + 2, &v15);
      if ( v12 )
      {
        SPExternalFree(v11);
        return v12;
      }
      else
      {
        v13 = (void *)*((_QWORD *)this + 112);
        if ( v13 )
          SPExternalFree(v13);
        v14 = v15 + 2;
        *((_QWORD *)this + 112) = v11;
        *((_DWORD *)this + 222) = v14;
        return 0i64;
      }
    }
    else
    {
      return 2148074240i64;
    }
  }
}

