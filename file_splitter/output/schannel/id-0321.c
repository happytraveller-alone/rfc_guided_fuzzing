//----- (0000000180017BBC) ----------------------------------------------------
__int64 McGenEventRegister_EtwEventRegister()
{
  __int64 result; // rax

  result = 0i64;
  if ( !MS_Schannel_Provider_Context )
    return EtwEventRegister(
             &MS_Schannel_Provider,
             McGenControlCallbackV2,
             &MS_Schannel_Provider_Context,
             &MS_Schannel_Provider_Context);
  return result;
}
// 180080EA8: using guessed type __int64 __fastcall EtwEventRegister(_QWORD, _QWORD, _QWORD, _QWORD);

