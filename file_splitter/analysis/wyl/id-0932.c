//----- (000000018004DC98) ----------------------------------------------------
__int64 __fastcall CSslSerializeHelper::SerializeContext(
        CSslSerializeHelper *this,
        void (__fastcall *a2)(__int64, __int64 *),
        unsigned __int8 **a3,
        unsigned int *a4)
{
  __int64 result; // rax
  __int64 v9; // rax
  __int64 v10; // rcx
  int v11; // eax
  unsigned int v12; // edi

  result = CSslSerializeHelper::SerializeContextWorker(this, a2);
  if ( !(_DWORD)result )
  {
    v9 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)this + 8i64))(
           *(_QWORD *)this,
           *((unsigned int *)this + 6));
    *((_QWORD *)this + 1) = v9;
    v10 = v9;
    if ( v9 )
    {
      v11 = *((_DWORD *)this + 6);
      *((_QWORD *)this + 2) = v10;
      *((_DWORD *)this + 7) = v11;
      v12 = CSslSerializeHelper::SerializeContextWorker(this, a2);
      if ( v12 )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)this + 16i64))(*(_QWORD *)this, *((_QWORD *)this + 1));
        return v12;
      }
      else
      {
        *a3 = (unsigned __int8 *)*((_QWORD *)this + 1);
        *a4 = *((_DWORD *)this + 6);
        return 0i64;
      }
    }
    else
    {
      return 14i64;
    }
  }
  return result;
}
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);

