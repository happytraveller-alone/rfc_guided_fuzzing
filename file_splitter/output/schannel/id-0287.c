// File count: 287
// Total lines: 66
-----------------------------------------
NTSTATUS __fastcall TlsOpenRegKey(PCWSTR Source, PCWSTR a2, PHANDLE KeyHandle)
{
  struct _UNICODE_STRING *v6; // rbx
  NTSTATUS result; // eax
  __int64 v8; // rax
  __int64 v9; // rcx
  struct _UNICODE_STRING *Heap; // rax
  struct _UNICODE_STRING *P; // [rsp+20h] [rbp-68h]
  struct _UNICODE_STRING v12; // [rsp+28h] [rbp-60h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+38h] [rbp-50h] BYREF
  unsigned int v14; // [rsp+A8h] [rbp+20h]
  NTSTATUS v15; // [rsp+A8h] [rbp+20h]

  v12 = 0i64;
  v6 = 0i64;
  P = 0i64;
  memset(&ObjectAttributes, 0, sizeof(ObjectAttributes));
  if ( !a2 )
  {
    RtlInitUnicodeString(&v12, Source);
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = 0i64;
    ObjectAttributes.Attributes = 576;
    ObjectAttributes.ObjectName = &v12;
LABEL_3:
    *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0i64;
    result = NtOpenKey(KeyHandle, 0x20019u, &ObjectAttributes);
    goto LABEL_10;
  }
  v8 = -1i64;
  v9 = -1i64;
  do
    ++v9;
  while ( Source[v9] );
  do
    ++v8;
  while ( a2[v8] );
  v14 = 2 * (v8 + v9) + 4;
  Heap = (struct _UNICODE_STRING *)RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, v14 + 16i64);
  v6 = Heap;
  P = Heap;
  if ( Heap )
  {
    Heap->Length = 0;
    Heap->MaximumLength = v14;
    Heap->Buffer = &Heap[1].Length;
    RtlAppendUnicodeToString(Heap, Source);
    RtlAppendUnicodeToString(v6, L"\\");
    RtlAppendUnicodeToString(v6, a2);
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = 0i64;
    ObjectAttributes.Attributes = 576;
    ObjectAttributes.ObjectName = v6;
    goto LABEL_3;
  }
  result = -1073741801;
LABEL_10:
  v15 = result;
  if ( v6 )
  {
    RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, P);
    return v15;
  }
  return result;
}
