//----- (000000018004CEC0) ----------------------------------------------------
void *__stdcall MIDL_user_allocate(size_t size)
{
  if ( (((_DWORD)size + 7) & 0xFFFFFFF8) >= size )
    return (void *)(*(__int64 (__fastcall **)(_QWORD))(LsaTable + 40))(((_DWORD)size + 7) & 0xFFFFFFF8);
  else
    return 0i64;
}
// 180092620: using guessed type __int64 LsaTable;

