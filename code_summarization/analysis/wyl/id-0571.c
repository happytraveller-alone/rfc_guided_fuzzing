//----- (00000001800285C4) ----------------------------------------------------
int _scrt_dllmain_uninitialize_c()
{
  int result; // eax

  if ( _scrt_is_ucrt_dll_in_use() )
    return execute_onexit_table(&Table);
  result = _scrt_stub_for_is_c_termination_complete();
  if ( !result )
    return o__cexit_0();
  return result;
}
// 180028CAA: using guessed type __int64 o__cexit_0(void);

