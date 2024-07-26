//----- (00000001800647B0) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeEncryptedExtensionsMsgSize(
        CTls13ServerHandshake *this,
        unsigned __int16 *a2)
{
  __int64 result; // rax
  unsigned int v5; // eax

  if ( !a2 )
    return 87i64;
  result = CTls13ServerHandshake::ComputeEncryptedExtensionsSize(this);
  if ( !(_DWORD)result )
  {
    v5 = *((unsigned __int16 *)this + 82) + 6;
    if ( v5 <= 0xFFFF )
    {
      *((_WORD *)this + 81) = v5;
      *a2 = v5;
      return 0i64;
    }
    else
    {
      return 1359i64;
    }
  }
  return result;
}

