//----- (000000018006EC1C) ----------------------------------------------------
__int64 __fastcall CTls13Context::SetCcsRecordInfo(CTls13Context *this, struct CTlsRecord::CMessageInfo *a2, char *a3)
{
  char v3; // al

  if ( *((_BYTE *)this + 32) || !*((_BYTE *)this + 201) )
    return 0i64;
  if ( a2 )
  {
    if ( a3 )
    {
      v3 = *a3;
      if ( *a3 != -1 )
      {
        *(_WORD *)a2 = 1;
        *a3 = v3 + 1;
        *(_QWORD *)((char *)a2 + 4) = 20i64;
        return 0i64;
      }
    }
  }
  return 87i64;
}
