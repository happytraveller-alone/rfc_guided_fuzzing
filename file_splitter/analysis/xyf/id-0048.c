//----- (0000000180003FB0) ----------------------------------------------------
void __fastcall CSsl3TlsContext::CleanupConnectedState(CSsl3TlsContext *this)
{
  void *v2; // rcx
  __int64 v3; // rdx
  _QWORD *v4; // rbx

  v2 = (void *)*((_QWORD *)this + 112);
  if ( v2 )
  {
    SPExternalFree(v2);
    *((_QWORD *)this + 112) = 0i64;
    *((_DWORD *)this + 222) = 0;
  }
  if ( *((_QWORD *)this + 110) )
  {
    (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 110) = 0i64;
  }
  v3 = *((_QWORD *)this + 114);
  *((_DWORD *)this + 218) = 0;
  if ( v3 )
  {
    (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 114) = 0i64;
    *((_WORD *)this + 460) = 0;
  }
  *(_WORD *)((char *)this + 923) = 0;
  *((_BYTE *)this + 472) = 0;
  v4 = (_QWORD *)*((_QWORD *)this + 58);
  if ( v4 && *v4 )
  {
    if ( v4[3] )
    {
      (*(void (__fastcall **)(_QWORD))(*(_QWORD *)*v4 + 16i64))(*v4);
      v4[3] = 0i64;
      *((_DWORD *)v4 + 4) = 0;
    }
  }
}

