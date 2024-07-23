// File count: 240
// Total lines: 137
----------------------------------------
__int64 __fastcall CSsl3TlsContext::SetApplicationProtocols(CSsl3TlsContext *this, struct _SecBuffer *const a2)
{
  unsigned __int16 *v2; // rsi
  unsigned int *pvBuffer; // rdi
  __int64 v5; // rax
  unsigned int *v6; // rbx
  CCipherMill *v7; // r10
  unsigned __int8 *v8; // rax
  __int64 v9; // rdx
  unsigned __int8 *v10; // rdx
  __int64 v11; // rcx
  unsigned __int8 *v12; // rax
  void *v13; // rbx
  __int64 v14; // rdi
  void *v15; // rax
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 v19; // rdx
  CCipherMill *v20; // rcx

  v2 = 0i64;
  if ( a2 )
  {
    if ( a2->BufferType == 18 && a2->cbBuffer >= 0xC && (pvBuffer = (unsigned int *)a2->pvBuffer) != 0i64 )
    {
      v5 = *pvBuffer;
      if ( (unsigned int)v5 >= 8 && (unsigned int)v5 < 0xFFFFFFFC && a2->cbBuffer >= (unsigned int)(v5 + 4) )
      {
        v6 = pvBuffer + 1;
        if ( (v5 & 0xFFFFFFFFFFFFFFF8ui64) != 0 )
        {
          v7 = WPP_GLOBAL_Control;
          while ( 1 )
          {
            if ( *v6 == 2 )
            {
              if ( v2 )
              {
                if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 1) != 0 )
                {
                  v18 = *((_QWORD *)v7 + 2);
                  v19 = 79i64;
                  goto LABEL_47;
                }
                return 2148074278i64;
              }
              v8 = (unsigned __int8 *)v6 + 6;
              v2 = (unsigned __int16 *)v6;
              if ( v6 == (unsigned int *)-6i64 )
                return 87i64;
              v9 = *((unsigned __int16 *)v6 + 2);
              if ( (unsigned __int16)(v9 - 2) > 0xFFFBu )
              {
                if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 1) != 0 )
                {
                  v17 = 74i64;
                  goto LABEL_32;
                }
                return 2148074278i64;
              }
              v10 = &v8[v9];
              if ( v8 < v10 )
              {
                while ( 1 )
                {
                  v11 = *v8;
                  if ( !(_BYTE)v11 )
                    break;
                  v12 = &v8[v11];
                  if ( v12 >= v10 )
                    break;
                  v8 = v12 + 1;
                  if ( v8 >= v10 )
                    goto LABEL_18;
                }
                if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 1) != 0 )
                {
                  v17 = 76i64;
LABEL_32:
                  WPP_SF_(*((_QWORD *)v7 + 2), v17, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
                  return 2148074278i64;
                }
                return 2148074278i64;
              }
            }
            else if ( v7 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v7 + 28) & 4) != 0 )
            {
              WPP_SF_d(*((_QWORD *)v7 + 2), 0x50u, (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, *v6);
              v7 = WPP_GLOBAL_Control;
            }
LABEL_18:
            v6 += 2 * (((unsigned __int64)*((unsigned __int16 *)v6 + 2) + 13) >> 3);
            if ( ((char *)v6 - (char *)pvBuffer - 4) >> 3 >= (unsigned __int64)*pvBuffer >> 3 )
              goto LABEL_19;
          }
        }
        goto LABEL_19;
      }
      v20 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v19 = 78i64;
    }
    else
    {
      v20 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
        return 2148074278i64;
      v19 = 77i64;
    }
    v18 = *((_QWORD *)v20 + 2);
LABEL_47:
    WPP_SF_(v18, v19, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    return 2148074278i64;
  }
LABEL_19:
  v13 = 0i64;
  if ( v2 )
  {
    v14 = v2[2];
    v15 = (void *)(*(__int64 (__fastcall **)(CSsl3TlsContext *, __int64))(*(_QWORD *)this + 8i64))(this, v14 + 6);
    v13 = v15;
    if ( !v15 )
      return 14i64;
    memcpy_0(v15, v2, v14 + 6);
  }
  (*(void (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 16i64))(this, *((_QWORD *)this + 98));
  *((_QWORD *)this + 98) = v13;
  if ( *((_QWORD *)this + 99) )
  {
    (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
    *((_QWORD *)this + 99) = 0i64;
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
