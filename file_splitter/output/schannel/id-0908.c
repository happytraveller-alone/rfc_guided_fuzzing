// File count: 908
// Total lines: 43
-----------------------------------------
__int64 __fastcall SslFilterSids(void *a1, struct _NETLOGON_VALIDATION_SAM_INFO3 *a2)
{
  __int64 v2; // r8
  __int64 v3; // rdx
  int v4; // ebx
  CCipherMill *v5; // rcx
  __int64 v6; // rdx

  if ( a1 )
  {
    v3 = 2i64;
    v2 = 2i64;
  }
  else
  {
    v2 = 0i64;
    v3 = 0i64;
  }
  v4 = LsaIFilterSids(0i64, v3, v2);
  if ( v4 >= 0 )
  {
    v5 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v6 = 18i64;
      goto LABEL_11;
    }
  }
  else
  {
    v5 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      v6 = 17i64;
LABEL_11:
      WPP_SF_D(*((_QWORD *)v5 + 2), v6, &WPP_30aed76c620c331e1998e7b09f72e2d4_Traceguids, (unsigned int)v4);
    }
  }
  return (unsigned int)v4;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098230: using guessed type __int64 __fastcall LsaIFilterSids(_QWORD, _QWORD, _QWORD);
