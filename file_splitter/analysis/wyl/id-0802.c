//----- (0000000180041EE0) ----------------------------------------------------
__int64 __fastcall CopyClientString(unsigned __int16 *a1, int a2, char a3, struct _UNICODE_STRING *a4)
{
  int v7; // ebx
  WCHAR *v8; // rax
  int v9; // ebx
  unsigned int v10; // esi
  struct _STRING SourceString; // [rsp+30h] [rbp-38h] BYREF

  *(_DWORD *)&a4->Length = 0;
  a4->Buffer = 0i64;
  SourceString.Buffer = 0i64;
  v7 = 0;
  if ( !a1 )
    return (unsigned int)v7;
  if ( a2 )
  {
    v9 = (a3 != 0) + 1;
    v10 = v9 * (a2 + 1);
    if ( v10 > 0xFFFF || v10 - v9 > 0xFFFF )
    {
      v7 = -1073741811;
      goto LABEL_16;
    }
    SourceString.Buffer = (PCHAR)LocalAlloc(0x40u, v10);
    if ( !SourceString.Buffer )
      return (unsigned int)-1073741801;
    SourceString.MaximumLength = v10;
    SourceString.Length = v10 - ((a3 != 0) + 1);
    v7 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, PCHAR, unsigned __int16 *))(LsaTable + 80))(
           0i64,
           v10 - v9,
           SourceString.Buffer,
           a1);
    if ( v7 < 0 )
      goto LABEL_16;
    if ( a3 )
    {
      a4->Buffer = (PWSTR)SourceString.Buffer;
      a4->Length = v10 - ((a3 != 0) + 1);
      a4->MaximumLength = v10;
      goto LABEL_16;
    }
    if ( RtlAnsiStringToUnicodeString(a4, &SourceString, 1u) >= 0 )
      goto LABEL_16;
  }
  else
  {
    v8 = (WCHAR *)LocalAlloc(0x40u, 2ui64);
    a4->Buffer = v8;
    if ( v8 )
    {
      a4->MaximumLength = 2;
      *v8 = 0;
      goto LABEL_16;
    }
  }
  v7 = -1073741801;
LABEL_16:
  if ( SourceString.Buffer && (!a3 || v7 < 0) )
    LocalFree(SourceString.Buffer);
  return (unsigned int)v7;
}
// 180092620: using guessed type __int64 LsaTable;
