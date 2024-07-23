// File count: 189
// Total lines: 53
-----------------------------------------
void __fastcall CCredentialGroup::InitializeFlags(CCredentialGroup *this, int a2)
{
  int v2; // eax

  if ( (a2 & 2) != 0 )
    *((_DWORD *)this + 39) |= 1u;
  if ( (a2 & 4) != 0 )
    *((_DWORD *)this + 39) |= 2u;
  if ( (a2 & 8) != 0 )
    *((_DWORD *)this + 39) |= 4u;
  if ( (a2 & 0x4000000) != 0 )
    *((_DWORD *)this + 39) |= 0x4000u;
  if ( (a2 & 0x10) != 0 )
    *((_DWORD *)this + 39) |= 8u;
  if ( (a2 & 0x20) != 0 )
    *((_DWORD *)this + 39) &= ~4u;
  if ( (a2 & 0x40) != 0 )
    *((_DWORD *)this + 39) &= ~8u;
  if ( (a2 & 0x80u) != 0 )
    *((_DWORD *)this + 39) |= 0x20u;
  if ( (a2 & 0x40000) != 0 )
    *((_DWORD *)this + 39) |= 0x80u;
  if ( (a2 & 0x80000) != 0 )
  {
    v2 = *((_DWORD *)this + 39) | 0x100;
    *((_DWORD *)this + 39) = v2;
    if ( (a2 & 0x100000) == 0 )
      *((_DWORD *)this + 39) = v2 | 0x200;
  }
  if ( (a2 & 0x200000) != 0 )
    *((_DWORD *)this + 39) |= 0x400u;
  if ( (a2 & 0x400000) != 0 )
    *((_DWORD *)this + 39) |= 0x800u;
  if ( (a2 & 0x800000) != 0 )
    *((_DWORD *)this + 39) |= 0x1000u;
  if ( (a2 & 0x2000000) != 0 )
    *((_DWORD *)this + 39) |= 0x2000u;
  if ( (a2 & 0x8000) != 0 )
    *((_DWORD *)this + 40) |= 0x2000u;
  if ( (a2 & 0x100) != 0 )
    *((_DWORD *)this + 40) |= 0x100u;
  if ( (a2 & 0x200) != 0 )
    *((_DWORD *)this + 40) |= 0x200u;
  if ( (a2 & 0x400) != 0 )
    *((_DWORD *)this + 40) |= 0x400u;
  if ( (a2 & 0x800) != 0 )
    *((_DWORD *)this + 40) |= 0x800u;
  if ( (a2 & 0x1000) != 0 )
    *((_DWORD *)this + 40) |= 0x1000u;
  if ( (a2 & 0x4000) != 0 )
    *((_DWORD *)this + 40) |= 0x4000u;
}
