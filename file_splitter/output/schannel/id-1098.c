// File count: 1098
// Total lines: 62
----------------------------------------
void __fastcall CSslContextManager::DeleteContextScratch(__int64 a1, __int64 a2, char a3, int a4)
{
  unsigned int v7; // ecx
  unsigned int v8; // eax
  bool v9; // zf
  void *v10; // rax
  void *v11; // rax
  __int64 v12; // rdi
  void (__fastcall *v13)(__int64, __int64); // rbx
  __int64 v14; // rax
  void *v15; // rax

  if ( a2 )
  {
    if ( a4 != 4 )
      goto LABEL_15;
    v7 = (*(unsigned __int16 (__fastcall **)(__int64))(*(_QWORD *)a2 + 64i64))(a2);
    v8 = *(_DWORD *)(a1 + 24);
    if ( v8 <= v7 )
      v8 = v7;
    *(_DWORD *)(a1 + 24) = v8;
    if ( _InterlockedIncrement((volatile signed __int32 *)(a1 + 20)) != 100 || !*(_QWORD *)(a1 + 56) )
      goto LABEL_15;
    v9 = *(_DWORD *)(a1 + 64) == 0;
    *(_DWORD *)(a1 + 32) = *(_DWORD *)(a1 + 24);
    if ( v9 )
    {
      v11 = operator new(0x50ui64);
      if ( !v11 )
      {
LABEL_15:
        if ( a3 )
        {
          v15 = (void *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a2 + 40i64))(a2);
          SPExternalFree(v15);
        }
        else
        {
          v12 = *(_QWORD *)(a1 + 56);
          v13 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v12 + 32i64);
          v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a2 + 40i64))(a2);
          v13(v12, v14);
        }
        return;
      }
      v10 = (void *)CSslLookaside::CSslLookaside((__int64)v11, *(_DWORD *)(a1 + 32), 1);
    }
    else
    {
      v10 = operator new(0x80ui64);
      if ( v10 )
        v10 = (void *)CSslLookasidePreallocate::CSslLookasidePreallocate(
                        (__int64)v10,
                        *(_DWORD *)(a1 + 32),
                        *(_DWORD *)(a1 + 64));
    }
    if ( v10 )
      *(_QWORD *)(a1 + 56) = v10;
    goto LABEL_15;
  }
}
