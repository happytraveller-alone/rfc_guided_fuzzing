//----- (0000000180002BF0) ----------------------------------------------------
void __fastcall CSessionCacheClientItem::SetSessionTicket(
        CSessionCacheClientItem *this,
        unsigned __int8 *a2,
        int a3,
        unsigned __int8 *a4,
        char a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        __int16 a9)
{
  void *v11; // rcx
  void *v14; // rcx
  DWORD TickCount; // eax
  int v16; // ebx
  unsigned int v17; // esi
  unsigned int ElapsedTime; // eax
  unsigned int v19; // ecx

  v11 = (void *)*((_QWORD *)this + 53);
  if ( v11 )
    SPExternalFree(v11);
  *((_DWORD *)this + 108) = a3;
  *((_QWORD *)this + 53) = a2;
  if ( (a9 & 0x2000) != 0 )
  {
    v14 = (void *)*((_QWORD *)this + 25);
    if ( v14 )
      SPExternalFree(v14);
    *((_BYTE *)this + 208) = a5;
    *((_DWORD *)this + 53) = a6;
    *((_DWORD *)this + 103) = a7;
    *((_QWORD *)this + 25) = a4;
    TickCount = GetTickCount();
    v16 = 1000 * *((_DWORD *)this + 103);
    v17 = a8;
    *((_DWORD *)this + 104) = TickCount;
    if ( CSslGlobals::m_dwClientLifespan < a8 )
      v17 = CSslGlobals::m_dwClientLifespan;
    ElapsedTime = GetElapsedTime(*((_DWORD *)this + 69));
    v19 = v16 + ElapsedTime;
    if ( v16 + ElapsedTime <= ElapsedTime )
    {
      v19 = v17;
    }
    else if ( v19 >= v17 )
    {
      v19 = v17;
    }
    *((_DWORD *)this + 70) = v19;
  }
}

