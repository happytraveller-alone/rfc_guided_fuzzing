//----- (0000000180017D1C) ----------------------------------------------------
__int64 McGenEventUnregister_EtwEventUnregister()
{
  __int64 result; // rax

  if ( !MS_Schannel_Provider_Context )
    return 0i64;
  result = EtwEventUnregister();
  MS_Schannel_Provider_Context = 0i64;
  return result;
}
// 180080EA0: using guessed type __int64 EtwEventUnregister(void);

