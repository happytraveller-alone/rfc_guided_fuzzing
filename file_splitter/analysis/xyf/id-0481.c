//----- (0000000180023120) ----------------------------------------------------
__int64 __fastcall CSslLookaside::Allocate(CSslLookaside *this, __int64 a2)
{
  if ( a2 == *((_DWORD *)this + 9) )
    return (*(__int64 (__fastcall **)(CSslLookaside *))(*(_QWORD *)this + 16i64))(this);
  else
    return 0i64;
}

