//----- (0000000180026888) ----------------------------------------------------
CSessionCacheTable *__fastcall CSessionCacheTable::CSessionCacheTable(
        CSessionCacheTable *this,
        struct _LIST_ENTRY *a2,
        __int64 a3)
{
  __int64 v4; // rdx
  _QWORD *v5; // rcx

  *(_QWORD *)this = a2;
  *((_DWORD *)this + 2) = a3;
  *((_QWORD *)this + 3) = (char *)this + 16;
  *((_QWORD *)this + 2) = (char *)this + 16;
  *((_QWORD *)this + 5) = (char *)this + 32;
  *((_QWORD *)this + 4) = (char *)this + 32;
  v4 = 0i64;
  if ( (_DWORD)a3 )
  {
    a3 = (unsigned int)a3;
    do
    {
      v5 = (_QWORD *)(v4 + *(_QWORD *)this);
      v5[1] = v5;
      *v5 = v5;
      v4 += 16i64;
      --a3;
    }
    while ( a3 );
  }
  RtlInitializeResource((PRTL_RESOURCE)((char *)this + 48));
  *((_BYTE *)this + 144) = 1;
  return this;
}
