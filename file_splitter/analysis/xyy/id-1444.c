//----- (0000000180073828) ----------------------------------------------------
_BOOL8 __fastcall DTlsMessage::checkOverlapp(DTlsMessage *this, unsigned int a2, unsigned int a3)
{
  BOOL v3; // r9d
  unsigned int i; // r10d

  v3 = 0;
  for ( i = a2; i <= a3; ++i )
  {
    if ( v3 )
      break;
    v3 = ((*(_BYTE *)(((unsigned __int64)i >> 3) + *((_QWORD *)this + 7)) >> (7 - (i & 7))) & 1) != 0;
  }
  return v3;
}

