//----- (00000001800523F4) ----------------------------------------------------
unsigned __int16 *__fastcall AllocateAndCopyString(wchar_t *Source)
{
  __int64 v1; // rax
  SIZE_T v3; // rbx
  wchar_t *v4; // rax
  wchar_t *v5; // rdi

  v1 = -1i64;
  do
    ++v1;
  while ( Source[v1] );
  v3 = (unsigned int)(2 * v1 + 2);
  v4 = (wchar_t *)LocalAlloc(0x40u, v3);
  v5 = v4;
  if ( v4 )
  {
    wcscpy_s(v4, v3 >> 1, Source);
    return v5;
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
    return 0i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
