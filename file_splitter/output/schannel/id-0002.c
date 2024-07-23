// File count: 2
// Total lines: 6
--------------------------------------------
int __fastcall dynamic_initializer_for__g_SslContextManager__(CSslContextManager *a1)
{
  CSslContextManager::CSslContextManager(a1);
  return atexit(dynamic_atexit_destructor_for__g_SslContextManager__);
}
