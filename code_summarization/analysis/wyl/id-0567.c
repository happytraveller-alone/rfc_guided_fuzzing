//----- (00000001800284EC) ----------------------------------------------------
bool _scrt_dllmain_before_initialize_c()
{
  return _scrt_initialize_onexit_tables(0) != 0;
}

