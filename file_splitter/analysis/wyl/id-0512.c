//----- (0000000180025E40) ----------------------------------------------------
__int64 __fastcall SpGetExtendedInformation(int a1, __int64 *a2)
{
  __int64 v3; // rax
  __int64 v4; // rbx
  const WCHAR *v5; // rdi
  UINT SystemWow64DirectoryW; // eax
  unsigned int v7; // edi
  __int64 result; // rax
  __int64 v9; // rax

  if ( a1 != 2 )
  {
    if ( a1 != 4 )
    {
      v7 = -2146893054;
      v4 = 0i64;
      goto LABEL_8;
    }
    v3 = (*(__int64 (__fastcall **)(__int64))(LsaTable + 40))(576i64);
    v4 = v3;
    if ( !v3 )
    {
      v7 = -1073741670;
      goto LABEL_8;
    }
    v5 = (const WCHAR *)(v3 + 56);
    SystemWow64DirectoryW = GetSystemWow64DirectoryW((LPWSTR)(v3 + 56), 0x104u);
    if ( SystemWow64DirectoryW )
    {
      if ( (unsigned __int64)(SystemWow64DirectoryW + 1) + 12 < 0x104 )
      {
        _o_wcscat_s(v5, 260i64, L"\\");
        _o_wcscat_s(v5, 260i64, L"schannel.dll");
        *(_DWORD *)v4 = 4;
        RtlInitUnicodeString((PUNICODE_STRING)(v4 + 8), v5);
        goto LABEL_7;
      }
      v7 = -1073741670;
    }
    else
    {
      v7 = -2146893054;
    }
    (*(void (__fastcall **)(__int64))(LsaTable + 48))(v4);
    goto LABEL_8;
  }
  v9 = (*(__int64 (__fastcall **)(__int64))(LsaTable + 40))(104i64);
  v4 = v9;
  if ( !v9 )
  {
    v7 = -2146893056;
    goto LABEL_8;
  }
  *(_DWORD *)v9 = 2;
  *(_DWORD *)(v9 + 8) = 12;
  *(_OWORD *)(v9 + 12) = xmmword_180083D20;
  *(_OWORD *)(v9 + 28) = xmmword_180083D30;
  *(_OWORD *)(v9 + 44) = xmmword_180083D40;
LABEL_7:
  v7 = 0;
LABEL_8:
  result = v7;
  *a2 = v4;
  return result;
}
// 180080C68: using guessed type __int64 __fastcall _o_wcscat_s(_QWORD, _QWORD, _QWORD);
// 180083D20: using guessed type __int128 xmmword_180083D20;
// 180083D30: using guessed type __int128 xmmword_180083D30;
// 180083D40: using guessed type __int128 xmmword_180083D40;
// 180092620: using guessed type __int64 LsaTable;
