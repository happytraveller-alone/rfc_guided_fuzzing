//----- (00000001800739D4) ----------------------------------------------------
__int64 __fastcall DTlsMsgMgr::insertMsg(DTlsMsgMgr *this, struct DTlsMessage *a2)
{
  char *v2; // r9
  unsigned int v3; // r8d
  char *i; // rcx
  char **v5; // rax

  v2 = (char *)this + 24;
  v3 = 0;
  for ( i = (char *)*((_QWORD *)this + 3); i != v2; i = *(char **)i )
  {
    if ( !i )
      return 1359;
    if ( *((_DWORD *)i + 6) > *((_DWORD *)a2 + 6) )
    {
      **((_QWORD **)i + 1) = a2;
      *(_QWORD *)a2 = i;
      *((_QWORD *)a2 + 1) = *((_QWORD *)i + 1);
      *((_QWORD *)i + 1) = a2;
      return v3;
    }
  }
  v5 = (char **)*((_QWORD *)v2 + 1);
  if ( *v5 != v2 )
    __fastfail(3u);
  *(_QWORD *)a2 = v2;
  *((_QWORD *)a2 + 1) = v5;
  *v5 = (char *)a2;
  *((_QWORD *)v2 + 1) = a2;
  return v3;
}
