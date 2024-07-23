//----- (0000000180017510) ----------------------------------------------------
__int64 __fastcall _delayLoadHelper2(__int64 a1, __int64 a2)
{
  return ResolveDelayLoadedAPI(
           &_ImageBase,
           a1,
           _pfnDefaultDliFailureHook2,
           DelayLoadFailureHook,
           a2,
           _ResolveDelayLoadedAPIFlags);
}
// 180000000: using guessed type __int16 _ImageBase;
// 1800807F8: using guessed type __int64 __fastcall ResolveDelayLoadedAPI(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD);
// 180086924: using guessed type int _ResolveDelayLoadedAPIFlags;
// 180086928: using guessed type __int64 _pfnDefaultDliFailureHook2;

