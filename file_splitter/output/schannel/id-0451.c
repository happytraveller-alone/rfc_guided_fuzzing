//----- (00000001800209BC) ----------------------------------------------------
void __fastcall CSslServerKey::Dereference(CSslServerKey *this)
{
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)this + 6, 0xFFFFFFFF) == 1 )
  {
    if ( this )
      (*(void (__fastcall **)(CSslServerKey *, __int64))(*(_QWORD *)this + 8i64))(this, 1i64);
  }
}

