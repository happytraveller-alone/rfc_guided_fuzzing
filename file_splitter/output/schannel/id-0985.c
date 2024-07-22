//----- (0000000180052918) ----------------------------------------------------
__int64 __fastcall SpQueryProtoInfo(struct CSslUserContext *a1, _DWORD *a2)
{
  _DWORD *v4; // rcx
  __int64 v5; // rax
  __int64 v7; // rbx
  SIZE_T v8; // rsi
  wchar_t *v9; // rax

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 18i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
  v4 = &unk_18007FD60;
  v5 = 0i64;
  while ( *((_DWORD *)a1 + 6) != *v4 )
  {
    v5 = (unsigned int)(v5 + 1);
    v4 += 6;
    if ( (unsigned int)v5 >= 0xC )
      return 2148074242i64;
  }
  v7 = 3 * v5;
  v8 = (unsigned int)(2 * lstrlenW(*((LPCWSTR *)&unk_18007FD60 + 3 * v5 + 1)) + 2);
  v9 = (wchar_t *)LocalAlloc(0x40u, v8);
  *(_QWORD *)a2 = v9;
  if ( !v9 )
    return 2148074240i64;
  wcscpy_s(v9, v8 >> 1, *((const wchar_t **)&unk_18007FD60 + v7 + 1));
  a2[2] = *((_DWORD *)&unk_18007FD60 + 2 * v7 + 4);
  a2[3] = *((_DWORD *)&unk_18007FD60 + 2 * v7 + 5);
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

