//----- (0000000180009470) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::WrapMessage(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  _BYTE *v5; // rbx
  unsigned int v6; // r15d
  unsigned int v10; // ecx
  int v11; // r8d
  __int16 v12; // bp
  __int16 v13; // r10
  unsigned int v14; // r11d
  unsigned int v15; // ecx
  char v16; // al
  int v17; // r14d
  char v18; // cl
  __int64 result; // rax
  unsigned int v20; // r9d
  unsigned int v21; // ecx
  __int64 v22; // rdx
  __int64 *v23; // rax
  __int64 v24; // r10
  unsigned int v25; // eax
  unsigned int v26; // [rsp+50h] [rbp-48h]
  unsigned int v27; // [rsp+A0h] [rbp+8h] BYREF
  unsigned int v28; // [rsp+A8h] [rbp+10h]
  __int16 v29; // [rsp+B8h] [rbp+20h]

  v5 = (_BYTE *)(*(_QWORD *)(a2 + 8) + *(unsigned int *)(a2 + 4));
  v6 = 0;
  v10 = a4;
  v11 = *(_DWORD *)(a1 + 60);
  v12 = *(_WORD *)(a1 + 34);
  v13 = *(_WORD *)(a1 + 32) & 4;
  if ( v13 )
  {
    v20 = *(_DWORD *)(a1 + 52);
    v21 = a4 + *(_DWORD *)(a1 + 48);
    v14 = *(_DWORD *)(a1 + 44);
    v28 = v14;
    if ( v20 )
    {
      if ( (*(_BYTE *)(a1 + 56) & 1) != 0 )
        v20 -= v21 % v20;
      v21 += v20;
    }
    v10 = v14 + v21;
  }
  else
  {
    v14 = 0;
    v28 = 0;
  }
  v15 = v11 + v10;
  v16 = v12;
  v17 = v11;
  v29 = v12;
  v27 = v15;
  if ( v15 > *(_DWORD *)a2 )
    return 122i64;
  if ( !v13 || (v22 = *(_QWORD *)(a1 + 8)) == 0 || !*(_DWORD *)(v22 + 28) )
  {
    v18 = *(_BYTE *)(a1 + 233);
    if ( !v18 )
      ++*(_QWORD *)(a1 + 184);
    goto LABEL_7;
  }
  if ( *(_QWORD *)(a1 + 152) )
  {
LABEL_19:
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_Di(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0xCu,
        (__int64)&WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids,
        a4,
        *(_QWORD *)(a1 + 184));
      v15 = v27;
      v14 = v28;
    }
    v23 = *(__int64 **)(a1 + 8);
    if ( v23 )
      v24 = *v23;
    else
      v24 = 0i64;
    v25 = SslEncryptPacket(v24, *(_QWORD *)(a1 + 152), &v5[v17 + v14], a4, v5, v15, &v27, *(_QWORD *)(a1 + 184), a3, 0);
    v6 = v25;
    if ( v25 )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids, v25);
      v18 = *(_BYTE *)(a1 + 233);
      v6 = -2146893015;
    }
    else
    {
      v18 = *(_BYTE *)(a1 + 233);
      if ( !v18 )
        ++*(_QWORD *)(a1 + 184);
    }
    v16 = v29;
LABEL_7:
    *v5 = a3;
    v5[1] = HIBYTE(v12);
    v5[2] = v16;
    if ( v18 )
    {
      v5[3] = *(_BYTE *)(a1 + 191);
      v5[4] = *(_BYTE *)(a1 + 190);
      v5[5] = *(_BYTE *)(a1 + 189);
      v5[6] = *(_BYTE *)(a1 + 188);
      v5[7] = *(_BYTE *)(a1 + 187);
      v5[8] = *(_BYTE *)(a1 + 186);
      v5[9] = *(_BYTE *)(a1 + 185);
      v5[10] = *(_BYTE *)(a1 + 184);
      v5[11] = (unsigned __int16)(v27 - v17) >> 8;
      v5[12] = v27 - v17;
      *(_QWORD *)(a1 + 184) ^= (*(_QWORD *)(a1 + 184) ^ (*(_QWORD *)(a1 + 184) + 1i64)) & 0xFFFFFFFFFFFFi64;
    }
    else
    {
      v5[3] = (unsigned __int16)(v27 - v17) >> 8;
      v5[4] = v27 - v17;
    }
    *(_DWORD *)(a2 + 4) += v27;
    return v6;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids);
  result = RemotelyGetUserKeys((struct CSslContext *)a1, 2u);
  v26 = result;
  if ( !(_DWORD)result )
  {
    v15 = v27;
    v14 = v28;
    goto LABEL_19;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
  {
    WPP_SF_D(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      11i64,
      &WPP_a921c2bd799c3cf4dae399b64001ae9a_Traceguids,
      (unsigned int)result);
    return v26;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098508: using guessed type __int64 __fastcall SslEncryptPacket(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _DWORD);

