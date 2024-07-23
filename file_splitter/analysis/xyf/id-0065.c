//----- (000000018000503C) ----------------------------------------------------
__int64 __fastcall EccGetEphemKey(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned __int64 *a5,
        unsigned int *a6)
{
  unsigned int v8; // edi
  unsigned int PublicKeyLength; // eax
  unsigned int EphemeralKey; // ebx
  unsigned int v14; // [rsp+88h] [rbp+20h] BYREF

  v8 = 0;
  v14 = 0;
  RtlAcquireResourceShared(&Resource, 1u);
  if ( a4 && qword_1800925C8 )
  {
    PublicKeyLength = CMasterEccCurveInfo::GetPublicKeyLength(qword_1800925C8, a4, &v14);
    v8 = v14;
    EphemeralKey = PublicKeyLength;
  }
  else
  {
    EphemeralKey = 87;
  }
  RtlReleaseResource(&Resource);
  if ( !EphemeralKey )
  {
    EphemeralKey = SslCreateEphemeralKey(a1, a5, a3, a2, a4, v8, 0i64, 0, 0);
    if ( EphemeralKey
      && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        11i64,
        &WPP_3e0ca11e9b65363ec3903422d835754d_Traceguids,
        EphemeralKey);
    }
    if ( a6 )
      *a6 = v8;
  }
  return EphemeralKey;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098548: using guessed type __int64 __fastcall SslCreateEphemeralKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _DWORD, _DWORD);

