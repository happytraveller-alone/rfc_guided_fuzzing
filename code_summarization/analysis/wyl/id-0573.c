//----- (0000000180028618) ----------------------------------------------------
char __fastcall _scrt_initialize_crt(int a1)
{
  char v1; // al

  v1 = byte_180092001;
  if ( !a1 )
    v1 = 1;
  byte_180092001 = v1;
  _isa_available_init();
  if ( !_scrt_stub_for_acrt_thread_attach() )
    return 0;
  if ( !_scrt_stub_for_acrt_thread_attach() )
  {
    _scrt_stub_for_acrt_uninitialize_critical();
    return 0;
  }
  return 1;
}
// 180092001: using guessed type char byte_180092001;

