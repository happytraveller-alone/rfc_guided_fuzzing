//----- (0000000180063660) ----------------------------------------------------
__int64 __fastcall CTls13Record::SetMaxFragment(CTls13Record *this, __int16 a2)
{
  if ( *((_QWORD *)this + 6) || (unsigned __int16)(a2 - 1) > 0x3FFFu )
    return 87i64;
  *((_WORD *)this + 40) = a2;
  return 0i64;
}

