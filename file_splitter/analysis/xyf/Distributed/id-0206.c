//----- (0000000180011860) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SslProtocolHandler(CSsl3TlsContext *this, struct SPBuffer *a2, struct SPBuffer *a3)
{
  unsigned int v6; // ebp
  char v7; // al
  unsigned int v8; // eax
  unsigned int v9; // ecx
  __int64 result; // rax
  __int64 v11; // rcx
  unsigned int v12; // edx
  DTlsMsgMgr *v13; // rcx
  CSsl3TlsContext *v14; // rcx
  int v15; // edx
  int v16; // eax
  unsigned int v17; // eax
  int v18; // [rsp+20h] [rbp-18h] BYREF
  int v19; // [rsp+24h] [rbp-14h]
  __int64 v20; // [rsp+28h] [rbp-10h]

  v6 = 0;
  if ( *((_DWORD *)this + 17) == 77 && (unsigned int)CSsl3TlsContext::ProcessAppModeInfo(this) )
    return 3221225701i64;
  v7 = *((_BYTE *)this + 266);
  if ( !v7 && (*((_DWORD *)this + 16) & 0x3000) == 0 )
    goto LABEL_50;
  v11 = *((_QWORD *)this + 17);
  if ( (v11 & 0x40000000) == 0 && !*((_BYTE *)this + 265) )
    goto LABEL_50;
  v12 = 0;
  if ( !*((_QWORD *)this + 19) )
    v12 = 2;
  if ( !*((_QWORD *)this + 18) )
    v12 |= 1u;
  if ( !v12 )
    goto LABEL_50;
  *((_QWORD *)this + 17) = v11 & 0xFFFFFFFFBFFFFFFFui64;
  if ( v7 )
  {
    *((_DWORD *)this + 18) = *((_DWORD *)this + 17);
    *((_DWORD *)this + 17) = 77;
    return RemotelyGetUserKeys(this, v12);
  }
  result = RemotelyGetUserKeys(this, v12);
  if ( !(_DWORD)result )
  {
LABEL_50:
    if ( *((_BYTE *)this + 233) )
    {
      v13 = (DTlsMsgMgr *)*((_QWORD *)this + 72);
      if ( *((DTlsMsgMgr **)v13 + 7) != (DTlsMsgMgr *)((char *)v13 + 56) )
        return CSsl3TlsContext::PrepareNextOutgoingRecord(this, a3);
      if ( *((_DWORD *)this + 17) != 4 && !*(_DWORD *)a2 && !*((_DWORD *)a2 + 1) && !*((_QWORD *)a2 + 1) )
      {
        result = DTlsMsgMgr::swapSaveAndOutgoing(v13);
        if ( !(_DWORD)result )
        {
          LogDtlsRetransmitRequested(
            *(_DWORD *)(*((_QWORD *)this + 10) + 212i64),
            (const unsigned __int16 *)(*((_QWORD *)this + 10) + 216i64));
          result = CSsl3TlsContext::RestoreWriteCipherState(this);
          if ( !(_DWORD)result )
            return CSsl3TlsContext::PrepareNextOutgoingRecord(v14, a3);
        }
        return result;
      }
    }
    if ( (*(unsigned __int8 (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 384i64))(this) )
    {
      if ( (*((_DWORD *)this + 34) & 0x1000i64) != 0 )
      {
        v15 = *((_DWORD *)a2 + 1);
        do
        {
          v20 = *((_QWORD *)a2 + 1) + v6;
          v16 = *(_DWORD *)a2 - v6;
          v19 = v15 - v6;
          v18 = v16;
          v17 = CSsl3TlsContext::TlsProtocolHandlerWorker(this, (struct SPBuffer *)&v18, a3);
          v6 += v19;
          v9 = v17;
          if ( *((_DWORD *)this + 17) == 4 )
            break;
          if ( v17 )
            break;
          v15 = *((_DWORD *)a2 + 1);
        }
        while ( v15 != v6 );
        *((_DWORD *)a2 + 1) = v6;
LABEL_9:
        if ( *((_DWORD *)this + 16) == 4096
          && *((_DWORD *)this + 17) == 4
          && (*((_DWORD *)this + 34) & 0x100i64) != 0
          && !*((_BYTE *)this + 552)
          && !v9 )
        {
          v9 = (*(__int64 (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 472i64))(this);
          if ( v9 == 590614 && *((_DWORD *)this + 17) == 4 )
            return 0;
        }
        return v9;
      }
      v8 = CSsl3TlsContext::TlsProtocolHandlerWorker(this, a2, a3);
    }
    else
    {
      v8 = CSsl3TlsContext::TlsNulRecordHandlerWorker(this, a2, a3);
    }
    v9 = v8;
    goto LABEL_9;
  }
  return result;
}
// 18003AC8B: variable 'v14' is possibly undefined

