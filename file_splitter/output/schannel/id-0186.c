// File count: 186
// Total lines: 165
----------------------------------------
char __fastcall BuildUserRequestedAlgList(
        struct CCredentialGroup *a1,
        char a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int **a5,
        unsigned int *a6,
        enum efAlgFlags *a7)
{
  int v7; // ebp
  unsigned int *v8; // r14
  char IsUserSpecifiedCipherAllowed; // di
  __int64 v13; // r15
  unsigned int v14; // r8d
  __int64 v16; // r12
  unsigned int *v17; // rax
  unsigned int v18; // esi
  unsigned int v19; // ecx
  _DWORD *v20; // rax
  CCipherMill *v21; // rcx
  __int64 v22; // r9
  __int64 v23; // rdx
  int v24; // eax
  struct kexch *KeyExchangeInfo; // rax
  struct hsel *HashInfo; // rax
  struct csel *CipherInfo; // rax
  unsigned int v28; // ecx
  struct sigsel *SigInfo; // rax
  unsigned int *v30; // [rsp+A0h] [rbp+8h]

  v7 = 0;
  v8 = 0i64;
  IsUserSpecifiedCipherAllowed = 1;
  if ( a1 )
  {
    v13 = 0i64;
    if ( !a3 )
    {
      v14 = *((_DWORD *)a1 + 49);
      if ( !v14 )
        return IsUserSpecifiedCipherAllowed;
LABEL_4:
      IsUserSpecifiedCipherAllowed = CCipherMill::IsUserSpecifiedCipherAllowed(
                                       *((_DWORD *)a1 + 39) & 0x800,
                                       v8,
                                       v13,
                                       v7,
                                       (*((_DWORD *)a1 + 39) >> 12) & 1,
                                       *((_DWORD *)a1 + 39) & 0x800,
                                       *((_DWORD *)a1 + 42),
                                       *((_DWORD *)a1 + 41),
                                       *((_DWORD *)a1 + 38),
                                       a2,
                                       *((_QWORD *)a1 + 25),
                                       v14);
      if ( !IsUserSpecifiedCipherAllowed && !v8 )
        SPExternalFree(0i64);
      return IsUserSpecifiedCipherAllowed;
    }
    v8 = (unsigned int *)SPExternalAlloc(0x44u);
    if ( v8 )
    {
      v16 = 0i64;
      if ( a4 )
      {
        v17 = a3;
        v30 = a3;
        while ( 1 )
        {
          v18 = *v17;
          v19 = 0;
          v20 = &unk_180085640;
          do
          {
            if ( v18 == *v20 )
              goto LABEL_17;
            ++v19;
            ++v20;
          }
          while ( v19 < 0x11 );
          if ( v19 == 17 )
            break;
LABEL_17:
          v24 = v18 & 0xE000;
          switch ( v24 )
          {
            case 8192:
              SigInfo = GetSigInfo(v18);
              if ( !SigInfo || (*((_DWORD *)a1 + 38) & *(_DWORD *)SigInfo) == 0 )
              {
LABEL_42:
                v21 = WPP_GLOBAL_Control;
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                {
                  v23 = 12i64;
                  v22 = v18;
LABEL_40:
                  WPP_SF_D(*((_QWORD *)v21 + 2), v23, &WPP_f57d92ef57843aa8f0882fb6fd501a9b_Traceguids, v22);
                }
                return 0;
              }
              v7 |= 1u;
              break;
            case 24576:
              CipherInfo = GetCipherInfo(v18);
              if ( !CipherInfo )
                goto LABEL_42;
              if ( *((_DWORD *)CipherInfo + 8) != v18 )
                goto LABEL_42;
              v28 = *((_DWORD *)CipherInfo + 10);
              if ( v28 < *((_DWORD *)a1 + 41)
                || v28 > *((_DWORD *)a1 + 42)
                || (*((_DWORD *)a1 + 38) & *(_DWORD *)CipherInfo) == 0 )
              {
                goto LABEL_42;
              }
              v7 |= 8u;
              break;
            case 32768:
              HashInfo = GetHashInfo(v18);
              if ( !HashInfo || (*((_DWORD *)a1 + 38) & *(_DWORD *)HashInfo) == 0 )
                goto LABEL_42;
              v7 |= 2u;
              break;
            case 40960:
              KeyExchangeInfo = GetKeyExchangeInfo(v18);
              if ( !KeyExchangeInfo || (*((_DWORD *)a1 + 38) & *((_DWORD *)KeyExchangeInfo + 1)) == 0 )
                goto LABEL_42;
              v7 |= 4u;
              break;
            default:
              goto LABEL_42;
          }
          if ( !DoesCredAllowAlgId(v8, v13, v18) )
          {
            v8[v13] = v18;
            v13 = (unsigned int)(v13 + 1);
          }
          v16 = (unsigned int)(v16 + 1);
          v17 = ++v30;
          if ( (unsigned int)v16 >= a4 )
            goto LABEL_39;
        }
        v21 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          v22 = a3[v16];
          v23 = 11i64;
          goto LABEL_40;
        }
        return 0;
      }
LABEL_39:
      *a5 = v8;
      *a6 = v13;
      *(_DWORD *)a7 = v7;
      v14 = *((_DWORD *)a1 + 49);
      goto LABEL_4;
    }
  }
  return 0;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
