//----- (0000000180016034) ----------------------------------------------------
NTSTATUS __fastcall TlsCloseRegKey(void **a1)
{
  void *v2; // rcx
  NTSTATUS result; // eax

  v2 = *a1;
  if ( v2 )
  {
    result = NtClose(v2);
    *a1 = 0i64;
  }
  return result;
}

