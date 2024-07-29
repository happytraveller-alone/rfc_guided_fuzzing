//----- (000000018006B1A8) ----------------------------------------------------
__int64 __fastcall CTls13Context::GenerateBinderData(
        CTls13Context *this,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int16 a5,
        unsigned int a6,
        const unsigned __int8 *a7,
        unsigned int a8,
        unsigned __int8 *a9,
        unsigned int a10)
{
  unsigned int v13; // ebx
  unsigned int v14; // r15d
  _QWORD *v15; // rsi
  unsigned int EarlyKey; // ebx
  CCipherMill *v17; // rcx
  __int64 v18; // rdx
  __int64 v20; // [rsp+40h] [rbp-28h] BYREF
  __int64 v21; // [rsp+78h] [rbp+10h] BYREF

  v20 = 0i64;
  v21 = 0i64;
  if ( a2 && a3 && a4 && a5 >= 0x304u && (v13 = a6) != 0 && a9 && (v14 = a10, a10 - 1 <= 0x3F) )
  {
    v15 = (_QWORD *)((char *)this + 104);
    if ( *((_QWORD *)this + 13)
      || (SslExpandPreSharedKey(a2, a3, a7, a8, &v21, 0i64, 0),
          (EarlyKey = SslExtractEarlyKey(a2, v21, v15, a5, v13, 0i64, 0)) == 0) )
    {
      EarlyKey = SslExpandBinderKey(a2, *v15, &v20, 0i64, 2);
      if ( EarlyKey )
      {
        v17 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          v18 = 16i64;
          goto LABEL_13;
        }
      }
      else
      {
        EarlyKey = SslComputeFinishedHash(a2, v20, a4, a9, v14, 0);
        if ( EarlyKey )
        {
          v17 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            v18 = 17i64;
            goto LABEL_13;
          }
        }
      }
    }
    else
    {
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        v18 = 15i64;
LABEL_13:
        WPP_SF_D(*((_QWORD *)v17 + 2), v18, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids, EarlyKey);
      }
    }
  }
  else
  {
    EarlyKey = 87;
  }
  if ( v21 )
    SslFreeObject(v21, 0i64);
  if ( v20 )
    SslFreeObject(v20, 0i64);
  if ( EarlyKey )
    CTls13Context::FreeEarlyKey(this);
  return EarlyKey;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098460: using guessed type __int64 __fastcall SslExpandBinderKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180098470: using guessed type __int64 __fastcall SslExpandPreSharedKey(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 1800984B8: using guessed type __int64 __fastcall SslExtractEarlyKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD);
// 180098538: using guessed type __int64 __fastcall SslComputeFinishedHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

