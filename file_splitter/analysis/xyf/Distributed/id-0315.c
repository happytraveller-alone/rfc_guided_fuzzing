//----- (0000000180017394) ----------------------------------------------------
__int64 __fastcall Wow64CopyUnicodeString(unsigned int a1, struct _UNICODE_STRING *a2)
{
  unsigned int v3; // edi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  WCHAR *v6; // rax
  unsigned int Length; // edx
  PWSTR Buffer; // rcx
  __int64 v10; // [rsp+50h] [rbp+18h] BYREF

  v10 = 0i64;
  if ( a1 && a2 )
  {
    v3 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64 *, _QWORD))(LsaTable + 80))(0i64, 8i64, &v10, a1);
    if ( !v3 )
    {
      v4 = WORD1(v10);
      if ( !WORD1(v10)
        || !(_WORD)v10
        || !HIDWORD(v10)
        || (v10 & 1) != 0
        || (v10 & 0x10000) != 0
        || (unsigned __int16)v10 > WORD1(v10)
        || WORD1(v10) == 0xFFFF )
      {
LABEL_18:
        v3 = -2146892963;
        goto LABEL_19;
      }
      a2->Length = v10;
      v5 = v4;
      a2->MaximumLength = v4;
      v6 = (WCHAR *)SPExternalAlloc(v4);
      a2->Buffer = v6;
      if ( v6 )
      {
        v3 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, WCHAR *, _QWORD))(LsaTable + 80))(0i64, v5, v6, HIDWORD(v10));
        if ( !v3 )
        {
          Length = a2->Length;
          if ( a2->Buffer[((unsigned __int64)a2->Length >> 1) - 1] )
            return v3;
          if ( Length > 2 )
          {
            a2->Length = Length - 2;
            return v3;
          }
          goto LABEL_18;
        }
      }
      else
      {
        v3 = -2146893056;
      }
    }
LABEL_19:
    Buffer = a2->Buffer;
    if ( Buffer )
    {
      SPExternalFree(Buffer);
      a2->Buffer = 0i64;
    }
    *(_DWORD *)&a2->Length = 0;
    return v3;
  }
  return 3221225485i64;
}
// 180092620: using guessed type __int64 LsaTable;

