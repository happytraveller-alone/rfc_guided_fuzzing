//----- (00000001800590F0) ----------------------------------------------------
void __fastcall CSessionCacheTable::~CSessionCacheTable(CSessionCacheTable *this)
{
  char *v1; // rsi
  char *i; // rbx

  v1 = (char *)this + 16;
  for ( i = (char *)*((_QWORD *)this + 2); i != v1; i = *(char **)i )
  {
    if ( i != (char *)304 )
      (*(void (__fastcall **)(_QWORD *, __int64))(*((_QWORD *)i - 38) + 8i64))((_QWORD *)i - 38, 1i64);
  }
  if ( *((_BYTE *)this + 144) )
    RtlDeleteResource((PRTL_RESOURCE)((char *)this + 48));
}

