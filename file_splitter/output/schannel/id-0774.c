// File count: 774
// Total lines: 19
-----------------------------------------
int snwprintf_s(
        wchar_t *const Buffer,
        const size_t BufferCount,
        const size_t MaxCount,
        const wchar_t *const Format,
        ...)
{
  unsigned __int64 *v8; // rax
  int result; // eax
  va_list va; // [rsp+90h] [rbp+28h] BYREF

  va_start(va, Format);
  v8 = _local_stdio_printf_options();
  result = _stdio_common_vsnwprintf_s(*v8, Buffer, BufferCount, MaxCount, Format, 0i64, va);
  if ( result < 0 )
    return -1;
  return result;
}
