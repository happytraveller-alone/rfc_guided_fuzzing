//----- (00000001800780DC) ----------------------------------------------------
__int64 __fastcall CTls13ExtClient::ParsePreSharedKeyExtension(
        CTls13ExtClient *this,
        unsigned __int8 *a2,
        unsigned __int16 a3,
        __int64 a4)
{
  if ( !a2 || a3 < 2u )
    return 2148074248i64;
  if ( a2[1] | (*a2 << 8) )
  {
    LOBYTE(a4) = 47;
    CSslContext::SetErrorAndFatalAlert(*((_QWORD *)this + 1), 106i64, 2148074278i64, a4);
    return 2148074278i64;
  }
  else
  {
    *(_QWORD *)(*((_QWORD *)this + 8) + 136i64) &= ~0x8000ui64;
    return 0i64;
  }
}
// 18005B470: using guessed type __int64 __fastcall CSslContext::SetErrorAndFatalAlert(_QWORD, _QWORD, _QWORD, _QWORD);

