// File count: 158
// Total lines: 25
-----------------------------------------
__int64 __fastcall CSslSerializeHelper::SerializeDataBlob(__int64 a1, int a2, const void *a3, unsigned int a4)
{
  unsigned int v4; // edi
  _DWORD *v7; // rcx

  v4 = (a4 + 23) & 0xFFFFFFF8;
  if ( !*(_QWORD *)(a1 + 8) )
  {
    *(_DWORD *)(a1 + 24) += v4;
    return 0i64;
  }
  if ( *(_DWORD *)(a1 + 28) >= v4 )
  {
    v7 = *(_DWORD **)(a1 + 16);
    *v7 = a2;
    v7[1] = v4 - 16;
    v7[2] = a4;
    memcpy_0((void *)(*(_QWORD *)(a1 + 16) + 16i64), a3, a4);
    *(_QWORD *)(a1 + 16) += v4;
    *(_DWORD *)(a1 + 28) -= v4;
    return 0i64;
  }
  return 1359i64;
}
