// File count: 183
// Total lines: 217
----------------------------------------
__int64 __fastcall GetUserKeysCallback(
        struct CSslUserContext *a1,
        void *(__stdcall *a2)(unsigned int),
        void (__stdcall *a3)(void *),
        char a4,
        struct _SecBuffer *a5)
{
  char v5; // di
  unsigned int v8; // ebx
  __int64 v9; // rdx
  __int64 v10; // rdx
  __int64 v11; // rdx
  __int64 v12; // rdx
  _QWORD *v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rdx
  __int64 v16; // rdx
  __int64 v17; // rdx
  CCipherMill *v19; // rcx
  __int64 v20; // rdx
  void *pvBuffer; // rcx
  CCipherMill *v22; // rcx
  __int64 v23; // rdx
  char v24; // [rsp+B0h] [rbp+58h]

  v5 = a4 & 8;
  a5->pvBuffer = 0i64;
  v8 = 0;
  v24 = a4 & 8;
  if ( *((_DWORD *)a1 + 14) )
  {
    if ( (a4 & 1) != 0 )
    {
      v9 = *((_QWORD *)a1 + 5);
      if ( v9 )
      {
        v8 = SslExportKey(*((_QWORD *)a1 + 11), v9, L"OpaqueKeyBlob");
        if ( v8 )
        {
          v19 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_27;
          }
          v20 = 127i64;
LABEL_26:
          WPP_SF_D(*((_QWORD *)v19 + 2), v20, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v8);
          goto LABEL_27;
        }
      }
    }
    if ( (a4 & 2) != 0 )
    {
      v10 = *((_QWORD *)a1 + 6);
      if ( v10 )
      {
        v8 = SslExportKey(*((_QWORD *)a1 + 11), v10, L"OpaqueKeyBlob");
        if ( v8 )
        {
          v19 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_27;
          }
          v20 = 128i64;
          goto LABEL_26;
        }
      }
    }
    v11 = *((_QWORD *)a1 + 55);
    if ( v11 )
    {
      v8 = SslExportKey(*((_QWORD *)a1 + 11), v11, L"OpaqueKeyBlob");
      if ( v8 )
      {
        v19 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_27;
        v20 = 129i64;
        goto LABEL_26;
      }
    }
    v12 = *((_QWORD *)a1 + 56);
    if ( v12 )
    {
      v8 = SslExportKey(*((_QWORD *)a1 + 11), v12, L"OpaqueKeyBlob");
      if ( v8 )
      {
        v19 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          goto LABEL_27;
        v20 = 130i64;
        goto LABEL_26;
      }
    }
  }
  if ( v5 )
    v13 = SPExternalAlloc(0x3Du);
  else
    v13 = PvExtVirtualAlloc(0x3Du);
  if ( v13 )
  {
    a5->pvBuffer = v13;
    a5->cbBuffer = 61;
    a5->BufferType = 1;
    *v13 = *((_QWORD *)a1 + 12);
    v13[1] = *((_QWORD *)a1 + 13);
    *((_DWORD *)v13 + 4) = *((_DWORD *)a1 + 29);
    *(_QWORD *)((char *)v13 + 20) = *((_QWORD *)a1 + 15);
    *(_QWORD *)((char *)v13 + 28) = *((_QWORD *)a1 + 16);
    *((_WORD *)v13 + 18) = *((_WORD *)a1 + 68);
    *((_WORD *)v13 + 19) = *((_WORD *)a1 + 69);
    *((_DWORD *)v13 + 10) = *((_DWORD *)a1 + 36);
    *((_BYTE *)v13 + 44) = *((_BYTE *)a1 + 456);
    *(_DWORD *)((char *)v13 + 45) = 0;
    *(_DWORD *)((char *)v13 + 49) = 0;
    *(_DWORD *)((char *)v13 + 53) = 0;
    *(_DWORD *)((char *)v13 + 57) = 0;
    if ( *((_DWORD *)a1 + 14) )
    {
      if ( (a4 & 1) != 0 )
      {
        v14 = *((_QWORD *)a1 + 5);
        if ( v14 )
        {
          v8 = SslExportKey(*((_QWORD *)a1 + 11), v14, L"OpaqueKeyBlob");
          if ( v8 )
          {
            v22 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
            {
              goto LABEL_21;
            }
            v23 = 131i64;
            goto LABEL_47;
          }
        }
      }
      if ( (a4 & 2) != 0 )
      {
        v15 = *((_QWORD *)a1 + 6);
        if ( v15 )
        {
          v8 = SslExportKey(*((_QWORD *)a1 + 11), v15, L"OpaqueKeyBlob");
          if ( v8 )
          {
            v22 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
            {
              goto LABEL_21;
            }
            v23 = 132i64;
            goto LABEL_47;
          }
        }
      }
      v16 = *((_QWORD *)a1 + 55);
      if ( v16 )
      {
        v8 = SslExportKey(*((_QWORD *)a1 + 11), v16, L"OpaqueKeyBlob");
        if ( v8 )
        {
          v22 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_21;
          }
          v23 = 133i64;
          goto LABEL_47;
        }
      }
      v17 = *((_QWORD *)a1 + 56);
      if ( v17 )
      {
        v8 = SslExportKey(*((_QWORD *)a1 + 11), v17, L"OpaqueKeyBlob");
        if ( v8 )
        {
          v22 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0 )
          {
            goto LABEL_21;
          }
          v23 = 134i64;
LABEL_47:
          WPP_SF_D(*((_QWORD *)v22 + 2), v23, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids, v8);
LABEL_21:
          v5 = v24;
LABEL_27:
          pvBuffer = a5->pvBuffer;
          if ( pvBuffer )
          {
            if ( v5 )
              SPExternalFree(pvBuffer);
            else
              FreeExtVirtualAlloc(pvBuffer);
            a5->pvBuffer = 0i64;
          }
          *(_QWORD *)&a5->cbBuffer = 0i64;
        }
      }
    }
    return v8;
  }
  return 2148074240i64;
}
// 18000F9D0: conditional instruction was optimized away because ebx.4==0
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180098528: using guessed type __int64 __fastcall SslExportKey(_QWORD, _QWORD, _QWORD);
