// File count: 133
// Total lines: 68
-----------------------------------------
__int64 __fastcall CSslContext::GenerateHelloMessage(
        CSslContext *this,
        struct _Ssl2_Client_Hello *a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned int a5,
        unsigned __int16 **a6,
        unsigned __int16 *a7)
{
  __int64 v7; // rbx
  unsigned int *v12; // rdx
  unsigned int v13; // r8d
  int v14; // r9d
  __int64 result; // rax
  unsigned __int16 v16; // ax
  int v17; // r8d
  int v18; // ecx
  unsigned int v19; // ebx
  __int64 v20; // rax
  __int64 v21; // rdx
  unsigned int v22; // eax

  v7 = *((_QWORD *)this + 10);
  v12 = *(unsigned int **)(v7 + 184);
  v13 = *(_DWORD *)(v7 + 176);
  v14 = *(_DWORD *)(v7 + 192);
  *((_DWORD *)a2 + 1) = 68;
  result = CCipherMill::BuildCipherSuiteList(
             (__int64)this,
             v12,
             v13,
             v14,
             v7,
             a3,
             (__int64)a2 + 80,
             (_DWORD *)a2 + 1,
             a6,
             a7);
  if ( !(_DWORD)result )
  {
    v16 = ConvertSchannelProtocolToSsl(a3);
    v18 = v16;
    v19 = v17 + 32;
    *((_DWORD *)a2 + 2) = v17;
    if ( !v16 )
      v18 = 768;
    *(_DWORD *)a2 = v18;
    v20 = *((_QWORD *)this + 11);
    if ( v20 && *(_WORD *)(v20 + 238) > (unsigned __int16)v17 )
    {
      *((_DWORD *)a2 + 2) = v19;
      v21 = *((_QWORD *)this + 11);
      v22 = *(unsigned __int16 *)(v21 + 238);
      if ( v22 <= v19 )
      {
        *((_DWORD *)a2 + 2) = v22;
        memcpy_0((char *)a2 + 16, (const void *)(v21 + 240), *(unsigned __int16 *)(v21 + 238));
      }
    }
    result = 0i64;
    *((_OWORD *)a2 + 3) = *(_OWORD *)a4;
    *((_OWORD *)a2 + 4) = *((_OWORD *)a4 + 1);
    *((_DWORD *)a2 + 3) = v19;
  }
  return result;
}
// 18000B01E: variable 'v17' is possibly undefined
