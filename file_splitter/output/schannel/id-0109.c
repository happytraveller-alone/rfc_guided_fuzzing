//----- (0000000180008DE0) ----------------------------------------------------
__int64 __fastcall SpDeleteContext(void *a1)
{
  __int64 v2; // rax
  __int64 v3; // rdx
  __int64 v4; // rcx
  const wchar_t *v5; // rbp
  __int64 v6; // rbx
  int v7; // esi
  unsigned int v8; // eax
  CCipherMill *v9; // rax
  __int64 v10; // rcx
  int v11; // esi
  int v12; // ebp
  int v13; // ebx
  __int64 v14; // rsi
  char v15; // bl
  __int64 v16; // rcx
  __int64 v17; // r8
  const wchar_t *v19; // r9
  unsigned int v20; // ecx
  unsigned int v21; // eax
  __int64 v22; // r14
  void *v23; // rax
  __int64 v24; // rax
  void *v25; // rax
  void (__fastcall *v26)(__int64, __int64); // rbx
  __int64 v27; // rax
  void *v28; // rax
  __int128 v29; // [rsp+40h] [rbp-48h] BYREF
  __int64 v30; // [rsp+50h] [rbp-38h]
  int v31[2]; // [rsp+58h] [rbp-30h] BYREF
  __int64 v32; // [rsp+60h] [rbp-28h]

  v2 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)a1 + 1) + 320i64))(*((_QWORD *)a1 + 1));
  v4 = *((_QWORD *)a1 + 1);
  v5 = (const wchar_t *)v2;
  v6 = *(_QWORD *)(v4 + 80);
  if ( v6 && LsaTable )
  {
    v29 = 0i64;
    v30 = 0i64;
    v7 = 8;
    if ( (*(unsigned __int8 (__fastcall **)(__int128 *))(LsaTable + 192))(&v29) && (BYTE8(v29) & 0x40) != 0 )
      v7 = 4;
    v8 = *(_DWORD *)(v6 + 736);
    if ( v8 > 1 )
    {
      v32 = 0i64;
      v31[1] = 0;
      v31[0] = 2 * v7 * v8;
      v32 = (*(__int64 (**)(void))(LsaTable + 384))();
      if ( v32 )
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, int *, _BYTE))(LsaTable + 496))(5i64, 0i64, 0i64, v31, 0);
    }
  }
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
  {
    v19 = &Class;
    if ( v5 )
      v19 = v5;
    McTemplateU0pz_EtwEventWriteTransfer(v4, v3, (__int64)a1, v19);
  }
  v9 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x34u, (__int64)&WPP_cfd72fb444783f09dc03172c6e6e3628_Traceguids, a1);
    v9 = WPP_GLOBAL_Control;
  }
  v10 = *((_QWORD *)a1 + 1);
  v11 = *(_DWORD *)(v10 + 64);
  v12 = *(_DWORD *)(v10 + 68);
  if ( v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 4) != 0 )
  {
    WPP_SF_q(*((_QWORD *)v9 + 2), 0x12u, (__int64)&WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids, a1);
    v10 = *((_QWORD *)a1 + 1);
  }
  if ( v10 )
  {
    v13 = *(_DWORD *)(v10 + 64);
    (**(void (__fastcall ***)(__int64, _QWORD))v10)(v10, 0i64);
    if ( (v13 & 0x800A2AAA) != 0 )
      SPExternalFree(*((void **)a1 + 1));
    *((_QWORD *)a1 + 1) = 0i64;
  }
  if ( (v11 & 0x51550) != 0 )
  {
    v14 = *((_QWORD *)a1 + 3);
    v15 = *((_BYTE *)a1 + 32);
    if ( !v14 )
    {
LABEL_20:
      *((_QWORD *)a1 + 3) = 0i64;
      (*(void (__fastcall **)(_QWORD, void *))(*(_QWORD *)xmmword_180092DD0 + 32i64))(xmmword_180092DD0, a1);
      goto LABEL_21;
    }
    if ( v12 == 4 )
    {
      v20 = (*(unsigned __int16 (__fastcall **)(__int64))(*(_QWORD *)v14 + 64i64))(v14);
      v21 = qword_180092DB8;
      if ( (unsigned int)qword_180092DB8 <= v20 )
        v21 = v20;
      LODWORD(qword_180092DB8) = v21;
      if ( _InterlockedIncrement((_DWORD *)&qword_180092DB0 + 1) == 100 )
      {
        v22 = *((_QWORD *)&xmmword_180092DD0 + 1);
        if ( !*((_QWORD *)&xmmword_180092DD0 + 1) )
          goto LABEL_44;
        LODWORD(qword_180092DC0) = qword_180092DB8;
        if ( dword_180092DE0 )
        {
          v23 = operator new(0x80ui64);
          if ( v23 )
          {
            v24 = CSslLookasidePreallocate::CSslLookasidePreallocate((__int64)v23, qword_180092DC0, dword_180092DE0);
LABEL_40:
            v22 = *((_QWORD *)&xmmword_180092DD0 + 1);
            if ( v24 )
              v22 = v24;
            *((_QWORD *)&xmmword_180092DD0 + 1) = v22;
            goto LABEL_44;
          }
        }
        else
        {
          v25 = operator new(0x50ui64);
          if ( v25 )
          {
            v24 = CSslLookaside::CSslLookaside((__int64)v25, qword_180092DC0, 1);
            goto LABEL_40;
          }
        }
      }
    }
    v22 = *((_QWORD *)&xmmword_180092DD0 + 1);
LABEL_44:
    if ( v15 )
    {
      v28 = (void *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 40i64))(v14);
      SPExternalFree(v28);
    }
    else
    {
      v26 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v22 + 32i64);
      v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 40i64))(v14);
      v26(v22, v27);
    }
    goto LABEL_20;
  }
  SPExternalFree(a1);
LABEL_21:
  if ( (Microsoft_Windows_Schannel_EventsEnableBits & 1) != 0 )
    McGenEventWrite_EtwEventWriteTransfer(v16, (__int64)&DscStop, v17, 1, (__int64)v31);
  return 0i64;
}
// 18003446B: variable 'v16' is possibly undefined
// 18003446B: variable 'v17' is possibly undefined
// 1800342C5: variable 'v4' is possibly undefined
// 1800342C5: variable 'v3' is possibly undefined
// 180092620: using guessed type __int64 LsaTable;
// 180092DB0: using guessed type __int64 qword_180092DB0;
// 180092DB8: using guessed type __int64 qword_180092DB8;
// 180092DC0: using guessed type __int64 qword_180092DC0;
// 180092DD0: using guessed type __int128 xmmword_180092DD0;
// 180092DE0: using guessed type int dword_180092DE0;
// 180092F00: using guessed type int Microsoft_Windows_Schannel_EventsEnableBits;

