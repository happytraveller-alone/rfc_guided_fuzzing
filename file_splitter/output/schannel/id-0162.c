//----- (000000018000E778) ----------------------------------------------------
struct CSslUserContext *__fastcall CreateUserContext(size_t Size)
{
  unsigned int v1; // edi
  _DWORD *v2; // rax
  _DWORD *v3; // rbx

  if ( (unsigned int)Size < 0x1D0 )
    return 0i64;
  v1 = Size;
  v2 = LocalAlloc(0x40u, (unsigned int)Size);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  memset_0(v2, 0, v1);
  v3[95] = 0;
  *((_QWORD *)v3 + 49) = 0i64;
  *((_QWORD *)v3 + 50) = 0i64;
  *((_QWORD *)v3 + 51) = 0i64;
  *((_QWORD *)v3 + 54) = 0i64;
  *((_QWORD *)v3 + 55) = 0i64;
  *(_QWORD *)v3 = &CSslUserContext::`vftable';
  *((_QWORD *)v3 + 56) = 0i64;
  v3[36] = -1;
  *((_BYTE *)v3 + 32) = 0;
  *((_BYTE *)v3 + 112) = 0;
  *((_BYTE *)v3 + 140) = 0;
  *((_BYTE *)v3 + 456) = 0;
  v3[115] = 23726566;
  *((_OWORD *)v3 + 26) = 0i64;
  v3[96] = -1;
  return (struct CSslUserContext *)v3;
}
// 18007D058: using guessed type void *CSslUserContext::`vftable';

