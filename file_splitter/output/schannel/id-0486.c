// File count: 486
// Total lines: 13
-----------------------------------------
void __fastcall DestroyEventEntry(__int64 a1)
{
  void *v1; // rbx
  HANDLE ProcessHeap; // rax

  if ( a1 )
  {
    v1 = *(void **)(a1 + 16);
    ProcessHeap = GetProcessHeap();
    HeapFree(ProcessHeap, 0, v1);
  }
}
