// File count: 1476
// Total lines: 99
----------------------------------------
__int64 __fastcall CTls13Record::EncryptRecord(CTls13Record *this)
{
  __int64 v2; // rcx
  unsigned __int64 v3; // rax
  _BYTE *v4; // r8
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 v7; // r10
  unsigned __int16 v9; // di
  unsigned __int16 v10; // si
  unsigned __int16 v11; // bp
  __int64 v12; // rax
  _QWORD *v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // rcx
  unsigned __int16 v16; // dx
  unsigned int v17; // [rsp+80h] [rbp+8h] BYREF
  __int64 v18; // [rsp+88h] [rbp+10h] BYREF
  __int64 v19; // [rsp+90h] [rbp+18h] BYREF

  if ( !*((_BYTE *)this + 88) )
    return 87i64;
  v2 = *((_QWORD *)this + 6);
  if ( !v2 )
    return 87i64;
  if ( !*(_QWORD *)(v2 + 8) )
    return 87i64;
  v3 = *((_QWORD *)this + 7);
  if ( !v3 )
    return 87i64;
  v4 = (_BYTE *)*((_QWORD *)this + 8);
  if ( (unsigned __int64)v4 < v3
    || *((unsigned __int16 *)this + 45) + 5i64 < (__int64)&v4[-v3]
    || (__int64)&v4[-v3] <= 5
    || (unsigned int)(*(_DWORD *)(v2 + 4) + 16) > *(_DWORD *)v2 )
  {
    return 87i64;
  }
  *v4 = *((_BYTE *)this + 84);
  v5 = *((_QWORD *)this + 6);
  ++*((_QWORD *)this + 8);
  ++*(_DWORD *)(v5 + 4);
  v6 = *((_QWORD *)this + 1);
  v19 = 0i64;
  v18 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *, __int64 *))(*(_QWORD *)v6 + 40i64))(v6, &v19, &v18);
  v7 = v18;
  if ( !v18 )
    return 1359i64;
  v9 = *((_WORD *)this + 32) - *((_WORD *)this + 28);
  v10 = v9 - 5;
  v17 = 0;
  v11 = v9 + 16;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_Di(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      0xAu,
      (__int64)&WPP_d7eb59dbd27e3a6dc714b07612d3a39e_Traceguids,
      v10,
      *(_QWORD *)(*((_QWORD *)this + 1) + 184i64));
    v7 = v18;
  }
  v12 = *((_QWORD *)this + 1);
  v13 = *(_QWORD **)(v12 + 8);
  if ( v13 )
    v13 = (_QWORD *)*v13;
  v14 = SslEncryptPacket(
          v13,
          v7,
          *((_QWORD *)this + 7) + 5i64,
          v10,
          *((_QWORD *)this + 7),
          v11,
          &v17,
          *(_QWORD *)(v12 + 184),
          23,
          0);
  if ( v14 || v17 > v11 || v17 < v9 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_d7eb59dbd27e3a6dc714b07612d3a39e_Traceguids, v14);
    return 2148074281i64;
  }
  else
  {
    v15 = *((_QWORD *)this + 6);
    v16 = v17 - v9;
    *((_QWORD *)this + 8) += (unsigned __int16)(v17 - v9);
    *((_QWORD *)this + 7) = *((_QWORD *)this + 8);
    *(_DWORD *)(v15 + 4) += v16;
    ++*(_QWORD *)(*((_QWORD *)this + 1) + 184i64);
    return 0i64;
  }
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 180098508: using guessed type __int64 __fastcall SslEncryptPacket(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _DWORD);
