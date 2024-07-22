//----- (0000000180028508) ----------------------------------------------------
char _scrt_dllmain_crt_thread_attach()
{
  if ( !_scrt_stub_for_acrt_thread_attach() )
    return 0;
  if ( !_scrt_stub_for_acrt_thread_attach() )
  {
    _scrt_stub_for_acrt_thread_attach();
    return 0;
  }
  return 1;
}

