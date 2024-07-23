//----- (000000018000B448) ----------------------------------------------------
__int64 __fastcall CSslSerializeHelper::DeserializeContextWorker(CSslSerializeHelper *this, struct CSslUserContext *a2)
{
  __int64 v2; // rdi
  unsigned int SslProvHandle; // ebp
  int v5; // r9d
  __int128 *v6; // rbx
  __int128 *v7; // rcx
  __int64 v8; // rax
  __int128 *v10; // rdx
  __int64 v11; // rax
  __int128 v12; // xmm0
  __int64 v13; // rax
  __int64 v14; // rdx
  const wchar_t *v15; // r9
  CCipherMill *v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // [rsp+20h] [rbp-18h]

  v2 = *((_QWORD *)this + 1);
  SslProvHandle = 0;
  v5 = *(_DWORD *)v2;
  if ( *(_DWORD *)v2 == 1 )
  {
    v6 = (__int128 *)((char *)a2 + 464);
    while ( 1 )
    {
      v7 = (__int128 *)(v2 + 16);
      if ( v5 > 10 )
      {
        if ( v5 <= 15 )
        {
          switch ( v5 )
          {
            case 15:
              *((_QWORD *)a2 + 51) = v6;
              break;
            case 11:
              *((_QWORD *)a2 + 31) = v6;
              memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
              *((_DWORD *)a2 + 64) = *(_DWORD *)(v2 + 8);
              goto LABEL_24;
            case 12:
              *((_QWORD *)a2 + 49) = v6;
              v10 = v6;
              v11 = 2i64;
              do
              {
                v12 = *v7;
                v7 += 8;
                *v10 = v12;
                v10 += 8;
                *(v10 - 7) = *(v7 - 7);
                *(v10 - 6) = *(v7 - 6);
                *(v10 - 5) = *(v7 - 5);
                *(v10 - 4) = *(v7 - 4);
                *(v10 - 3) = *(v7 - 3);
                *(v10 - 2) = *(v7 - 2);
                *(v10 - 1) = *(v7 - 1);
                --v11;
              }
              while ( v11 );
              *(_QWORD *)v10 = *(_QWORD *)v7;
              goto LABEL_24;
            case 13:
              *((_QWORD *)a2 + 50) = v6;
              break;
            default:
              v13 = *((_QWORD *)a2 + 50);
LABEL_63:
              *(_QWORD *)(v13 + 8) = v6;
              memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
              goto LABEL_24;
          }
          *v6 = *v7;
          goto LABEL_24;
        }
        switch ( v5 )
        {
          case 16:
            v13 = *((_QWORD *)a2 + 51);
            goto LABEL_63;
          case 17:
            *((_QWORD *)a2 + 53) = v6;
            memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
            *((_DWORD *)a2 + 104) = *(_DWORD *)(v2 + 8);
            goto LABEL_24;
          case 18:
            goto LABEL_11;
        }
        if ( v5 > 20 )
        {
LABEL_67:
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            WPP_SF_d(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xFu,
              (__int64)&WPP_3fd35671b5b538c236a2a452323fc10e_Traceguids,
              v5);
          }
          return 2148074244i64;
        }
        if ( !a2 || !*((_QWORD *)a2 + 11) )
          return SslProvHandle;
        v14 = 440i64;
        if ( v5 != 19 )
          v14 = 448i64;
        SslProvHandle = SslImportKey(
                          *((_QWORD *)a2 + 11),
                          (char *)a2 + v14,
                          L"OpaqueKeyBlob",
                          v2 + 16,
                          *(_DWORD *)(v2 + 8),
                          0);
        if ( SslProvHandle )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            v15 = L"read";
            if ( *(_DWORD *)v2 != 19 )
              v15 = L"write";
            LODWORD(v18) = SslProvHandle;
            WPP_SF_SD(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              0xEu,
              (__int64)&WPP_3fd35671b5b538c236a2a452323fc10e_Traceguids,
              v15,
              v18);
          }
          return SslProvHandle;
        }
      }
      else
      {
        if ( v5 == 10 )
        {
          *((_QWORD *)a2 + 29) = v6;
          memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
          *((_DWORD *)a2 + 60) = *(_DWORD *)(v2 + 8);
          goto LABEL_24;
        }
        if ( v5 <= 5 )
        {
          switch ( v5 )
          {
            case 5:
              *((_QWORD *)a2 + 21) = v6;
              memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
              *((_DWORD *)a2 + 44) = *(_DWORD *)(v2 + 8);
              goto LABEL_24;
            case 0:
              return 0i64;
            case 1:
              *((_DWORD *)a2 + 2) = *(_DWORD *)v7;
              *((_QWORD *)a2 + 2) = *(_QWORD *)(v2 + 24);
              *((_DWORD *)a2 + 6) = *(_DWORD *)(v2 + 32);
              *((_BYTE *)a2 + 32) = *(_BYTE *)(v2 + 60);
              *((_DWORD *)a2 + 7) = *(_DWORD *)(v2 + 44);
              *((_QWORD *)a2 + 12) = *(_QWORD *)(v2 + 64);
              *((_QWORD *)a2 + 13) = *(_QWORD *)(v2 + 72);
              *((_DWORD *)a2 + 14) = *(_DWORD *)(v2 + 36);
              *((_DWORD *)a2 + 15) = *(_DWORD *)(v2 + 40);
              *((_DWORD *)a2 + 16) = *(_DWORD *)(v2 + 48);
              *((_DWORD *)a2 + 18) = *(_DWORD *)(v2 + 52);
              *((_DWORD *)a2 + 17) = *(_DWORD *)(v2 + 168);
              *((_DWORD *)a2 + 29) = *(_DWORD *)(v2 + 192);
              *((_QWORD *)a2 + 15) = *(_QWORD *)(v2 + 176);
              *((_QWORD *)a2 + 16) = *(_QWORD *)(v2 + 184);
              *((_WORD *)a2 + 68) = *(_WORD *)(v2 + 196);
              *((_WORD *)a2 + 69) = *(_WORD *)(v2 + 198);
              *((_DWORD *)a2 + 36) = *(_DWORD *)(v2 + 200);
              *((_DWORD *)a2 + 115) = *(_DWORD *)(v2 + 204);
              *((_BYTE *)a2 + 456) = *(_BYTE *)(v2 + 208);
              *((_DWORD *)a2 + 49) = *(_DWORD *)(v2 + 56);
              *((_DWORD *)a2 + 95) = *(_DWORD *)(v2 + 164);
              *((_DWORD *)a2 + 94) = *(_DWORD *)(v2 + 160);
              *((_QWORD *)a2 + 33) = *(_QWORD *)(v2 + 80);
              *((_DWORD *)a2 + 68) = *(_DWORD *)(v2 + 88);
              *((_QWORD *)a2 + 37) = *(_QWORD *)(v2 + 96);
              *((_DWORD *)a2 + 80) = *(_DWORD *)(v2 + 104);
              memcpy_0((char *)a2 + 324, (const void *)(v2 + 108), *(unsigned int *)(v2 + 104));
              goto LABEL_25;
          }
          if ( v5 <= 1 )
            goto LABEL_67;
          if ( v5 > 3 )
          {
            *((_QWORD *)a2 + 19) = v6;
            memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
            *((_DWORD *)a2 + 40) = *(_DWORD *)(v2 + 8);
LABEL_24:
            v6 = (__int128 *)((char *)v6 + ((*(unsigned int *)(v2 + 8) + 7i64) & 0xFFFFFFFFFFFFFFF8ui64));
            goto LABEL_25;
          }
LABEL_11:
          if ( !a2 || !*((_QWORD *)a2 + 11) )
            return SslProvHandle;
          if ( v5 == 2 )
          {
            v8 = 40i64;
          }
          else
          {
            v8 = 432i64;
            if ( v5 == 3 )
              v8 = 48i64;
          }
          SslProvHandle = SslImportKey(
                            *((_QWORD *)a2 + 11),
                            (char *)a2 + v8,
                            L"OpaqueKeyBlob",
                            v2 + 16,
                            *(_DWORD *)(v2 + 8),
                            0);
          if ( SslProvHandle )
          {
            v16 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              v17 = 13i64;
LABEL_74:
              WPP_SF_D(*((_QWORD *)v16 + 2), v17, &WPP_3fd35671b5b538c236a2a452323fc10e_Traceguids, SslProvHandle);
            }
            return SslProvHandle;
          }
          goto LABEL_25;
        }
        switch ( v5 )
        {
          case 6:
            *((_QWORD *)a2 + 23) = v6;
            memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
            *((_DWORD *)a2 + 48) = *(_DWORD *)(v2 + 8);
            goto LABEL_24;
          case 7:
            *((_QWORD *)a2 + 25) = v6;
            memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
            *((_DWORD *)a2 + 52) = *(_DWORD *)(v2 + 8);
            goto LABEL_24;
          case 8:
            *((_QWORD *)a2 + 27) = v6;
            memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
            *((_DWORD *)a2 + 56) = *(_DWORD *)(v2 + 8);
            goto LABEL_24;
        }
        *((_QWORD *)a2 + 10) = v6;
        memcpy_0(v6, (const void *)(v2 + 16), *(unsigned int *)(v2 + 8));
        v6 = (__int128 *)((char *)v6 + ((*(unsigned int *)(v2 + 8) + 7i64) & 0xFFFFFFFFFFFFFFF8ui64));
        SslProvHandle = GetSslProvHandle(*((const unsigned __int16 **)a2 + 10), (unsigned __int64 *)a2 + 11);
        if ( SslProvHandle )
        {
          v16 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            v17 = 12i64;
            goto LABEL_74;
          }
          return SslProvHandle;
        }
      }
LABEL_25:
      v2 += (unsigned int)(*(_DWORD *)(v2 + 4) + 16);
      v5 = *(_DWORD *)v2;
    }
  }
  return 2148074244i64;
}
// 18000B58E: conditional instruction was optimized away because r9d.4==4
// 180035B6A: conditional instruction was optimized away because r9d.4>=13
// 18000B54B: conditional instruction was optimized away because r9d.4==9
// 180035B1E: conditional instruction was optimized away because r9d.4==E
// 180035C1C: variable 'v18' is possibly undefined
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180082320: using guessed type wchar_t aOpaquekeyblob[14];
// 180085368: using guessed type wchar_t aRead[5];
// 180085378: using guessed type wchar_t aWrite[6];
// 1800985A0: using guessed type __int64 __fastcall SslImportKey(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);

