//----- (00000001800527F0) ----------------------------------------------------
__int64 __fastcall SpQueryPackageInfo(struct CSslUserContext *a1, void *a2)
{
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rsi
  _WORD *v5; // rax

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 17i64, &WPP_6dc6bfeff2363ebb5c4b35617de21a59_Traceguids);
  v3 = (unsigned int)(2 * lstrlenW(L"Schannel") + 2);
  v4 = (unsigned int)(2 * lstrlenW(L"Schannel Security Package") + 2);
  v5 = LocalAlloc(0x40u, v4 + v3 + 32);
  *(_QWORD *)a2 = v5;
  if ( !v5 )
    return 3221225626i64;
  v5[2] = 1;
  *(_WORD *)(*(_QWORD *)a2 + 6i64) = 14;
  **(_DWORD **)a2 = 4261811;
  *(_DWORD *)(*(_QWORD *)a2 + 8i64) = 24576;
  *(_QWORD *)(*(_QWORD *)a2 + 16i64) = *(_QWORD *)a2 + 32i64;
  *(_QWORD *)(*(_QWORD *)a2 + 24i64) = v3 + *(_QWORD *)(*(_QWORD *)a2 + 16i64);
  wcscpy_s(*(wchar_t **)(*(_QWORD *)a2 + 16i64), v3 >> 1, L"Schannel");
  wcscpy_s(*(wchar_t **)(*(_QWORD *)a2 + 24i64), v4 >> 1, L"Schannel Security Package");
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

