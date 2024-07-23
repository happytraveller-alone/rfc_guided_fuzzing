//----- (00000001800165E0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsClientContext::PreparseMessage(CSsl3TlsClientContext *this, struct SPBuffer *a2)
{
  HLOCAL v5; // rax

  if ( *((_DWORD *)this + 17) != 49 )
    return 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40i64, &WPP_2dcc559eea6f3c37d295569df36f7bc3_Traceguids);
  if ( *((_QWORD *)a2 + 1) && *(_DWORD *)a2 )
  {
    v5 = SPExternalAlloc(*(_DWORD *)a2);
    *((_QWORD *)this + 117) = v5;
    if ( v5 )
    {
      memcpy_0(v5, *((const void **)a2 + 1), *(unsigned int *)a2);
      *((_DWORD *)this + 236) = *(_DWORD *)a2;
      *((_DWORD *)this + 17) = 91;
      return 0i64;
    }
    return 14i64;
  }
  else
  {
    CSslContext::SetError((__int64)this, 500, -2146893048);
    return 2148074248i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

