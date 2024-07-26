//----- (0000000180027C80) ----------------------------------------------------
__int64 initialize_msvcrt_compatibility()
{
  unsigned __int64 *v0; // rax
  unsigned __int64 *v1; // rax

  v0 = _local_stdio_printf_options();
  *v0 |= 0x18ui64;
  v1 = _local_stdio_scanf_options();
  *v1 |= 4ui64;
  return 0i64;
}

