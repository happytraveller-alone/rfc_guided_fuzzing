// File count: 1249
// Total lines: 21
----------------------------------------
void __fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::~CTls13Handshake<CTls13ClientContext,CTls13ExtClient>(
        _QWORD *a1)
{
  void (__fastcall ***v2)(_QWORD, __int64); // rcx
  void *v3; // rcx
  void *v4; // rcx

  *a1 = &CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::`vftable';
  v2 = (void (__fastcall ***)(_QWORD, __int64))a1[2];
  if ( v2 )
    (**v2)(v2, 1i64);
  v3 = (void *)a1[7];
  if ( v3 )
    SPExternalFree(v3);
  v4 = (void *)a1[18];
  if ( v4 )
    SPExternalFree(v4);
}
// 18007FD48: using guessed type void *CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::`vftable';
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
