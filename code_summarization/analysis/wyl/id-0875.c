//----- (0000000180047320) ----------------------------------------------------
__int64 __fastcall CSslContext::SetUiInformation(CSslContext *this, void *a2, unsigned int a3)
{
  int v7; // ebx
  int v8; // esi
  char v9[24]; // [rsp+30h] [rbp-48h] BYREF
  __int64 v10; // [rsp+48h] [rbp-30h] BYREF

  v10 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v9) )
    return 1359i64;
  v7 = v9[8] & 0x40;
  if ( a3 == (v7 != 0 ? 4 : 8) )
  {
    v8 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *, void *))(LsaTable + 80))(0i64, a3, &v10, a2);
    if ( v8 >= 0 )
    {
      if ( v7 )
      {
        *((_QWORD *)this + 13) = (unsigned int)v10;
        *((_DWORD *)this + 27) = 0;
      }
      else
      {
        *((_QWORD *)this + 13) = v10;
      }
    }
    else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        11i64,
        &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids,
        (unsigned int)v8);
    }
    return (unsigned int)v8;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_dd5b111c8476393ce65badbe3d423765_Traceguids, a3);
    return 87i64;
  }
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
