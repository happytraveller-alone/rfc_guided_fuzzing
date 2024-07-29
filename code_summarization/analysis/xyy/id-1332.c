//----- (000000018006880C) ----------------------------------------------------
unsigned __int64 __fastcall CTls13Context::GetFinishedMessageKey(CTls13Context *this, char a2)
{
  if ( *((_BYTE *)this + 233) )
    return *((_QWORD *)this + 10);
  if ( a2 )
    return *((_QWORD *)this + 7);
  return *((_QWORD *)this + 8);
}

