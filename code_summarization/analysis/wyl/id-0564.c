//----- (000000018002844C) ----------------------------------------------------
unsigned __int64 *_scrt_initialize_default_local_stdio_options()
{
  unsigned __int64 *v0; // rax
  unsigned __int64 *result; // rax

  v0 = _local_stdio_printf_options();
  *v0 |= 0x24ui64;
  result = _local_stdio_scanf_options();
  *result |= 2ui64;
  return result;
}
