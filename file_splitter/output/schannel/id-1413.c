// File count: 1413
// Total lines: 113
---------------------------------------
__int64 __fastcall CTlsMessageFragment::SaveFragment(
        CTlsMessageFragment *this,
        unsigned __int8 *Src,
        size_t Size,
        int a4,
        unsigned int *a5)
{
  unsigned int v5; // ebp
  int v8; // esi
  unsigned int v9; // esi
  CCipherMill *v10; // r10
  __int64 result; // rax
  __int64 v12; // rcx
  unsigned int v13; // eax
  void *v14; // rcx
  __int64 v15; // rbx
  unsigned int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // r9d
  unsigned int v20; // edx
  unsigned int v21; // ebx
  int v22; // [rsp+20h] [rbp-28h]

  v5 = Size;
  v8 = *((_DWORD *)this + 10) != 0 ? 8 : 0;
  *a5 = 0;
  v9 = v8 + 4;
  if ( !a4 )
    goto LABEL_5;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 8) = v9;
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 71i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
LABEL_5:
    v10 = WPP_GLOBAL_Control;
  }
  if ( *((_DWORD *)this + 9) < v9 )
  {
    if ( v9 > *((_DWORD *)this + 4) )
    {
      result = CTlsMessageFragment::Reallocate(this, v9);
      if ( (_DWORD)result )
        return result;
    }
    v12 = *((unsigned int *)this + 9);
    v13 = v9 - v12;
    if ( v5 < v9 - (unsigned int)v12 )
      v13 = v5;
    v14 = (void *)(*((_QWORD *)this + 3) + v12);
    v15 = v13;
    *a5 = v13;
    memcpy_0(v14, Src, v13);
    Src += v15;
    v16 = v15 + *((_DWORD *)this + 9);
    *((_DWORD *)this + 9) = v16;
    v5 -= v15;
    if ( !v5 )
      return 0i64;
    v17 = *((_DWORD *)this + 10) != 0 ? 12 : 4;
    if ( *((_DWORD *)this + 8) > v17 && v16 >= *((_DWORD *)this + 8) )
      return 0i64;
    if ( v16 >= v17
      && !(*(unsigned __int8 *)(*((_QWORD *)this + 3) + 3i64)
         + (*(unsigned __int8 *)(*((_QWORD *)this + 3) + 1i64) << 16)
         + (*(unsigned __int8 *)(*((_QWORD *)this + 3) + 2i64) << 8)) )
    {
      return 0i64;
    }
    v10 = WPP_GLOBAL_Control;
  }
  v18 = *((_DWORD *)this + 8);
  if ( v18 > v9 )
  {
LABEL_25:
    v21 = *((_DWORD *)this + 8) - *((_DWORD *)this + 9);
    if ( v21 >= v5 )
      v21 = v5;
    if ( v21 )
    {
      memcpy_0((void *)(*((_QWORD *)this + 3) + *((unsigned int *)this + 9)), Src, v21);
      *((_DWORD *)this + 9) += v21;
      *a5 += v21;
    }
    return 0i64;
  }
  v19 = *(unsigned __int8 *)(*((_QWORD *)this + 3) + 3i64)
      + (*(unsigned __int8 *)(*((_QWORD *)this + 3) + 1i64) << 16)
      + (*(unsigned __int8 *)(*((_QWORD *)this + 3) + 2i64) << 8);
  if ( v19 <= *((_DWORD *)this + 2) )
  {
    v20 = v19 + v18;
    *((_DWORD *)this + 8) = v20;
    if ( v20 > *((_DWORD *)this + 4) )
    {
      result = CTlsMessageFragment::Reallocate(this, v20);
      if ( (_DWORD)result )
        return result;
    }
    goto LABEL_25;
  }
  if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 1) != 0 )
  {
    v22 = *((_DWORD *)this + 2);
    WPP_SF_dd(*((_QWORD *)v10 + 2), 0x48u, (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, v19, v22);
  }
  CSslContext::SetErrorAndFatalAlert(*(_QWORD *)this, 12, -2146893018, 0xAu);
  return 2148074278i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
