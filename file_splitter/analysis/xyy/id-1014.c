//----- (0000000180054F60) ----------------------------------------------------
ULONG __fastcall McGenEventWrite_EventWriteTransfer(
        __int64 a1,
        const EVENT_DESCRIPTOR *a2,
        __int64 a3,
        __int64 a4,
        PEVENT_DATA_DESCRIPTOR UserData)
{
  unsigned __int16 *v5; // r8
  ULONG v6; // eax
  ULONG v7; // r8d

  v5 = (unsigned __int16 *)qword_180091388;
  v6 = 0;
  if ( qword_180091388 )
  {
    UserData->Ptr = qword_180091388;
    v6 = 2;
    v7 = *v5;
  }
  else
  {
    UserData->Ptr = 0i64;
    v7 = 0;
  }
  UserData->Size = v7;
  UserData->Reserved = v6;
  return EventWriteTransfer(MS_Schannel_Provider_Context, a2, 0i64, 0i64, 1u, UserData);
}
// 180091388: using guessed type __int64 qword_180091388;

