//----- (0000000180027C30) ----------------------------------------------------
__int64 initialize_legacy_wide_specifiers()
{
  unsigned __int64 *v0; // rax
  unsigned __int64 *v1; // rax

  v0 = _local_stdio_printf_options();
  *v0 |= 4ui64;
  v1 = _local_stdio_scanf_options();
  *v1 |= 2ui64;
  return 0i64;
}
