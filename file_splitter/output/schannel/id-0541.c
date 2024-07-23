// File count: 541
// Total lines: 15
-----------------------------------------
__int64 __fastcall SslDuplicateString(struct _UNICODE_STRING *a1, struct _UNICODE_STRING *a2)
{
  WCHAR *v4; // rax

  v4 = (WCHAR *)SPExternalAlloc((unsigned int)a2->Length + 2);
  a1->Buffer = v4;
  if ( !v4 )
    return 3221225495i64;
  a1->Length = a2->Length;
  a1->MaximumLength = a2->Length + 2;
  memcpy_0(v4, a2->Buffer, a2->Length);
  a1->Buffer[(unsigned __int64)a1->Length >> 1] = 0;
  return 0i64;
}
