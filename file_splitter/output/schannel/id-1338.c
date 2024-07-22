//----- (000000018006961C) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::ParseEncryptedExtensionsMsg(
        CTls13ClientHandshake *this,
        unsigned __int8 *a2,
        unsigned int a3,
        __int64 a4)
{
  __int64 v5; // rcx
  unsigned int v6; // ebx
  __int64 v8; // r8

  if ( a2 && a3 )
  {
    if ( a3 >= 2 )
    {
      v8 = a3 - 2;
      if ( (_DWORD)v8 == (a2[1] | (*a2 << 8)) )
      {
        v6 = CTlsExt::ParseTlsExtensions(*((_QWORD *)this + 2), a2 + 2, v8, 8i64);
        if ( !v6 )
          return v6;
      }
      else
      {
        v6 = -2146893048;
      }
      v5 = *((_QWORD *)this + 1);
    }
    else
    {
      v5 = *((_QWORD *)this + 1);
      v6 = -2146893048;
    }
    LOBYTE(a4) = 50;
    CSslContext::SetErrorAndFatalAlert(v5, 120i64, v6, a4);
    return v6;
  }
  return 87i64;
}
// 18006964D: variable 'a4' is possibly undefined
// 180006430: using guessed type __int64 __fastcall CTlsExt::ParseTlsExtensions(_QWORD, _QWORD, _QWORD, _QWORD);
// 18005B470: using guessed type __int64 __fastcall CSslContext::SetErrorAndFatalAlert(_QWORD, _QWORD, _QWORD, _QWORD);

