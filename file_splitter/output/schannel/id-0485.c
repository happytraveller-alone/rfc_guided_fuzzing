// File count: 485
// Total lines: 33
-----------------------------------------
void __fastcall FlushEventEntryList(REGHANDLE RegHandle, PCEVENT_DESCRIPTOR EventDescriptor)
{
  PCEVENT_DESCRIPTOR v2; // rdi
  int v4; // edx
  __int64 v5; // rcx
  const EVENT_DESCRIPTOR *Keyword; // rbx

  if ( EventDescriptor )
  {
    v2 = EventDescriptor;
    do
    {
      v4 = 2;
      if ( (unsigned int)BYTE5(v2[2].Keyword) + 2 > 2 )
      {
        v5 = 32i64;
        do
        {
          v5 += 16i64;
          ++v4;
          *(_BYTE *)(v5 + *(_QWORD *)&v2[1].Id - 3) = 0;
        }
        while ( v4 < BYTE5(v2[2].Keyword) + 2 );
      }
      EventWriteTransfer_0(RegHandle, v2, 0i64, 0i64, BYTE4(v2[2].Keyword), *(PEVENT_DATA_DESCRIPTOR *)&v2[1].Id);
      Keyword = (const EVENT_DESCRIPTOR *)v2[1].Keyword;
      DestroyEventEntry((__int64)v2);
      v2 = Keyword;
    }
    while ( Keyword );
  }
}
