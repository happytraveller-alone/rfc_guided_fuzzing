//----- (000000018006FFCC) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::PrepareNextOutgoingRecord(CSsl3TlsContext *this, struct SPBuffer *a2)
{
  unsigned int v4; // ebp
  __int64 v5; // r15
  _QWORD **v6; // rcx
  _QWORD *v7; // rax
  _QWORD *v8; // rdx
  _QWORD *v9; // rdi
  int v10; // r8d
  int v11; // r14d
  unsigned int v12; // r8d
  unsigned int v13; // ecx
  __int64 result; // rax
  char v15; // cl
  __int64 v16; // rax
  unsigned __int64 v17; // r9
  __int64 *v18; // rcx
  __int64 v19; // rax
  __int64 **v20; // rdx

  if ( (*((_BYTE *)this + 32) & 4) != 0 )
    v4 = *((_DWORD *)this + 11);
  else
    v4 = 0;
  v5 = *((unsigned int *)this + 15);
  v6 = (_QWORD **)(*((_QWORD *)this + 72) + 56i64);
  v7 = *v6;
  if ( *v6 == v6 )
    goto LABEL_34;
  if ( (_QWORD **)v7[1] != v6 )
    goto LABEL_33;
  v8 = (_QWORD *)*v7;
  if ( *(_QWORD **)(*v7 + 8i64) != v7 )
    goto LABEL_33;
  *v6 = v8;
  v9 = v7 - 5;
  v8[1] = v6;
  if ( v7 == (_QWORD *)40 )
  {
LABEL_34:
    *(_DWORD *)a2 = 0;
    *((_DWORD *)a2 + 1) = 0;
    return 0i64;
  }
  v10 = *((_DWORD *)v9 + 1) - v5;
  v11 = *(unsigned __int8 *)v9[1];
  if ( (*((_BYTE *)this + 32) & 4) != 0 )
  {
    v12 = *((_DWORD *)this + 12) + v10;
    v13 = *((_DWORD *)this + 13);
    if ( v13 )
    {
      if ( (*((_BYTE *)this + 56) & 1) != 0 )
        v13 -= v12 % v13;
      v12 += v13;
    }
    v10 = *((_DWORD *)this + 11) + v12;
  }
  result = CSsl3TlsContext::AllocateOutputBuffer(this, a2, *((_DWORD *)this + 15) + v10);
  if ( !(_DWORD)result )
  {
    memcpy_0(
      (void *)(v5 + v4 + *((_QWORD *)a2 + 1)),
      (const void *)(v5 + v9[1]),
      (unsigned int)(*((_DWORD *)v9 + 1) - v5));
    *((_DWORD *)a2 + 1) = 0;
    result = CSsl3TlsContext::WrapMessage((__int64)this, (__int64)a2, v11, *((_DWORD *)v9 + 1) - (int)v5);
    if ( !(_DWORD)result )
    {
      if ( v11 == 20 )
      {
        result = CSsl3TlsContext::SaveWriteCipherState(this);
        if ( (_DWORD)result )
          return result;
        *((_WORD *)this + 16) |= 0xCu;
        v15 = *((_BYTE *)this + 233);
        if ( !v15 && *((_QWORD *)this + 19) )
        {
          SslFreeObject(*((_QWORD *)this + 19), 0i64);
          v15 = *((_BYTE *)this + 233);
        }
        v16 = *((_QWORD *)this + 21);
        *((_QWORD *)this + 21) = 0i64;
        *((_QWORD *)this + 19) = v16;
        if ( !v15 )
          *((_QWORD *)this + 23) = 0i64;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 59i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        v17 = (*((_QWORD *)this + 23) + 0x1000000000000i64) & 0xFFFF000000000000ui64;
        *((_QWORD *)this + 23) = v17;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_i(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x49u,
            (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
            HIWORD(v17));
      }
      *((_DWORD *)v9 + 8) = 1;
      v18 = v9 + 5;
      v19 = *((_QWORD *)this + 72) + 72i64;
      v20 = *(__int64 ***)(*((_QWORD *)this + 72) + 80i64);
      if ( *v20 == (__int64 *)v19 )
      {
        *v18 = v19;
        v9[6] = v20;
        *v20 = v18;
        *(_QWORD *)(v19 + 8) = v18;
        if ( *(_QWORD *)(*((_QWORD *)this + 72) + 56i64) != *((_QWORD *)this + 72) + 56i64 )
          return 590692i64;
        *((_QWORD *)this + 113) = GetTickCount64();
        return 0i64;
      }
LABEL_33:
      __fastfail(3u);
    }
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098570: using guessed type __int64 __fastcall SslFreeObject(_QWORD, _QWORD);

