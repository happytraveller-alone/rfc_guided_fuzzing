//----- (000000018006B3EC) ----------------------------------------------------
__int64 __fastcall CTls13Context::GenerateCcsRecord(CTls13Context *this)
{
  __int64 result; // rax

  if ( !*((_BYTE *)this + 32) && *((_BYTE *)this + 201) )
  {
    result = CTls13ChangeCipherSpec::GenerateMessage((CTls13Context *)((char *)this + 16));
    if ( (_DWORD)result )
      return result;
    *((_BYTE *)this + 32) = 1;
  }
  return 0i64;
}

