//----- (0000000180016390) ----------------------------------------------------
bool __fastcall CSessionCacheClientItem::IsSameTargetName(CSessionCacheClientItem *this, char *a2)
{
  const unsigned __int16 *v2; // rax
  char *v3; // rdx
  int v4; // r8d
  int v5; // ecx

  v2 = (const unsigned __int16 *)*((_QWORD *)this + 46);
  if ( v2 == (const unsigned __int16 *)a2 )
    return 1;
  if ( !v2 || !a2 )
    return 0;
  v3 = (char *)(a2 - (char *)v2);
  do
  {
    v4 = *(unsigned __int16 *)&v3[(_QWORD)v2];
    v5 = *v2 - v4;
    if ( v5 )
      break;
    ++v2;
  }
  while ( v4 );
  return !v5;
}

