//----- (0000000180020C30) ----------------------------------------------------
void __fastcall CTls13ServerHandshake::~CTls13ServerHandshake(CTls13ServerHandshake *this)
{
  void *v2; // rcx
  void *v3; // rcx
  void (__fastcall ***v4)(_QWORD, __int64); // rcx
  void *v5; // rcx
  void *v6; // rcx

  *(_QWORD *)this = &CTls13ServerHandshake::`vftable';
  v2 = (void *)*((_QWORD *)this + 22);
  if ( v2 )
    SPExternalFree(v2);
  v3 = (void *)*((_QWORD *)this + 24);
  if ( v3 )
    LocalFree(v3);
  v4 = (void (__fastcall ***)(_QWORD, __int64))*((_QWORD *)this + 2);
  *(_QWORD *)this = &CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::`vftable';
  if ( v4 )
    (**v4)(v4, 1i64);
  v5 = (void *)*((_QWORD *)this + 7);
  if ( v5 )
    SPExternalFree(v5);
  v6 = (void *)*((_QWORD *)this + 18);
  if ( v6 )
    SPExternalFree(v6);
}
// 18007CB68: using guessed type void *CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::`vftable';
// 18007CB80: using guessed type void *CTls13ServerHandshake::`vftable';
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

