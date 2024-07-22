//----- (000000018006F1C4) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::StoreClientShares(
        CTls13ServerContext *this,
        const unsigned __int8 *a2,
        unsigned __int16 a3)
{
  size_t v3; // rdi
  void *v7; // rcx
  HLOCAL v8; // rax

  v3 = a3;
  if ( a3 && !a2 )
    return 87i64;
  v7 = (void *)*((_QWORD *)this + 187);
  if ( v7 )
  {
    SPExternalFree(v7);
    *((_QWORD *)this + 187) = 0i64;
    *((_WORD *)this + 752) = 0;
  }
  if ( (_WORD)v3 )
  {
    if ( *((_DWORD *)this + 17) == 71 && ((unsigned int)v3 < 4 || *((_DWORD *)this + 4) != (a2[1] | (*a2 << 8))) )
      return 2148074278i64;
    v8 = SPExternalAlloc(v3);
    *((_QWORD *)this + 187) = v8;
    if ( !v8 )
      return 14i64;
    memcpy_0(v8, a2, v3);
    *((_WORD *)this + 752) = v3;
  }
  return 0i64;
}

