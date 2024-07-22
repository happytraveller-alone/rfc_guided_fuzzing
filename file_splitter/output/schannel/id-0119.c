//----- (0000000180009ED4) ----------------------------------------------------
__int64 __fastcall GetEphemBlobFromKey(
        __int64 a1,
        __int64 a2,
        const unsigned __int16 *a3,
        unsigned int *a4,
        unsigned __int8 **a5)
{
  unsigned int v9; // ebx
  unsigned __int8 *v10; // rax
  unsigned int v11; // edi

  v9 = SslExportKey(a1, a2, a3);
  if ( v9 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_8452d3335a5c3be980705cc51c40b5db_Traceguids, v9);
    return v9;
  }
  else
  {
    v10 = (unsigned __int8 *)SPExternalAlloc(*a4);
    *a5 = v10;
    if ( v10 )
    {
      v11 = SslExportKey(a1, a2, a3);
      if ( v11 )
      {
        SPExternalFree(*a5);
        *a5 = 0i64;
      }
      return v11;
    }
    else
    {
      return 14i64;
    }
  }
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098528: using guessed type __int64 __fastcall SslExportKey(_QWORD, _QWORD, _QWORD);

