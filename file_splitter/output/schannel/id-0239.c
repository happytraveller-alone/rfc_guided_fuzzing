// File count: 239
// Total lines: 55
-----------------------------------------
__int64 __fastcall CSslContext::GetProviderInfo(CSslContext *this, unsigned __int16 *const a2, unsigned __int64 *a3)
{
  unsigned __int64 *v3; // rax
  unsigned int v4; // esi
  unsigned __int64 v6; // rdx
  __int64 *v7; // rax
  __int64 v8; // rdi
  unsigned int v9; // ebp
  unsigned __int16 *v10; // rdx
  __int64 v11; // rax

  v3 = (unsigned __int64 *)*((_QWORD *)this + 1);
  v4 = 0;
  if ( v3 )
    v6 = *v3;
  else
    v6 = 0i64;
  *a3 = v6;
  v7 = (__int64 *)*((_QWORD *)this + 1);
  if ( v7 )
    v8 = *v7;
  else
    v8 = 0i64;
  RtlAcquireResourceShared(&Resource, 1u);
  v9 = 0;
  if ( qword_180092498 )
  {
    while ( qword_1800924A0[v9] != v8 )
    {
      if ( ++v9 >= qword_180092498 )
        goto LABEL_13;
    }
    v10 = *(unsigned __int16 **)(qword_180092490 + 16i64 * v9);
    v11 = 256i64;
    while ( v11 != -2147483390 && *v10 )
    {
      *a2++ = *v10++;
      if ( !--v11 )
      {
        --a2;
        break;
      }
    }
    *a2 = 0;
  }
LABEL_13:
  RtlReleaseResource(&Resource);
  if ( v9 == qword_180092498 )
    return 1168;
  return v4;
}
// 180013E81: conditional instruction was optimized away because rax.8 is in (1..FFFFFFFF80000101|>=FFFFFFFF80000103u)
// 180092490: using guessed type __int64 qword_180092490;
// 1800924A0: using guessed type unsigned __int64 qword_1800924A0[32];
