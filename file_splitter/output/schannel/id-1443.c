// File count: 1443
// Total lines: 45
----------------------------------------
__int64 __fastcall DTlsMessage::checkComplete(DTlsMessage *this)
{
  unsigned int v1; // r8d
  _DWORD *v2; // r11
  int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // r10d
  unsigned int v6; // ecx
  unsigned int v7; // r9d

  v1 = 0;
  v2 = (_DWORD *)*((_QWORD *)this + 7);
  v3 = 0;
  v4 = *((_DWORD *)this + 4);
  v5 = v4 & 0x1F;
  v6 = v4 >> 5;
  if ( v6 )
  {
    while ( *v2 == -1 )
    {
      ++v2;
      if ( ++v3 >= v6 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v7 = 0;
    if ( v5 )
    {
      while ( ((*((_BYTE *)v2 + ((unsigned __int64)v7 >> 3)) >> (7 - (v7 & 7))) & 1) != 0 )
      {
        if ( ++v7 >= v5 )
          return 1;
      }
    }
    else
    {
      return 1;
    }
  }
  return v1;
}
