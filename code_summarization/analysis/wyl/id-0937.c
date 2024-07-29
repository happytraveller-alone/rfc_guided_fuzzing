//----- (000000018004DEF8) ----------------------------------------------------
__int64 __fastcall CSslUserContext::GenerateKeyUpdateRecord(CSslUserContext *this, struct SPBuffer *a2)
{
  __int64 result; // rax
  CCipherMill *v5; // rcx
  int v6; // [rsp+50h] [rbp-28h] BYREF
  __int16 v7; // [rsp+54h] [rbp-24h]

  if ( !a2 )
    return 2148074333i64;
  v6 = 16777240;
  v7 = 5632;
  v5 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
  {
    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 123i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
      v5 = WPP_GLOBAL_Control;
    }
    if ( v5 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
      WPP_SF_D(
        *((_QWORD *)v5 + 2),
        124i64,
        &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids,
        *((unsigned int *)this + 26));
  }
  result = SslEncryptPacket(
             *((_QWORD *)this + 11),
             *((_QWORD *)this + 6),
             &v6,
             6i64,
             *((_QWORD *)a2 + 1),
             *(_DWORD *)a2,
             (char *)a2 + 4,
             *((_QWORD *)this + 13),
             23,
             0);
  if ( !(_DWORD)result )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 125i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
    return UpdateTrafficSecretAndDeriveNewKey(
             *((_QWORD *)this + 11),
             (unsigned __int64 *)this + 56,
             (unsigned __int64 *)this + 6,
             (unsigned __int64 *)this + 13);
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098508: using guessed type __int64 __fastcall SslEncryptPacket(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _DWORD);
