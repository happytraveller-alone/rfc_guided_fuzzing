//----- (0000000180072EF8) ----------------------------------------------------
struct DTlsMessage *__fastcall DTlsMsgMgr::FindMsg(DTlsMsgMgr *this, int a2)
{
  __int64 v2; // r8
  __int64 **v3; // rcx
  __int64 *i; // rax

  v2 = 0i64;
  v3 = (__int64 **)((char *)this + 24);
  for ( i = *v3; i != (__int64 *)v3 && i; i = (__int64 *)*i )
  {
    if ( *((_DWORD *)i + 6) == a2 )
      return (struct DTlsMessage *)i;
  }
  return (struct DTlsMessage *)v2;
}

