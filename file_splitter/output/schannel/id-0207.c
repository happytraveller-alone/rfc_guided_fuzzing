// File count: 207
// Total lines: 992
----------------------------------------
__int64 __fastcall CSsl3TlsContext::TlsProtocolHandlerWorker(
        CSsl3TlsContext *this,
        struct SPBuffer *a2,
        struct SPBuffer *a3)
{
  int v3; // edi
  struct SPBuffer *v5; // r15
  unsigned int v7; // r12d
  __int64 v8; // rax
  __int64 result; // rax
  unsigned int v10; // r8d
  int v11; // edx
  CCipherMill *v12; // rcx
  unsigned __int8 *v13; // r14
  unsigned int v14; // esi
  __int64 v15; // r8
  unsigned int v16; // esi
  int v17; // esi
  int v18; // eax
  unsigned int v19; // esi
  int v20; // ecx
  __int64 v21; // rdx
  unsigned int v22; // r11d
  unsigned __int8 *v23; // rsi
  unsigned int v24; // r15d
  unsigned int v25; // r14d
  __int64 v26; // rdx
  unsigned int v27; // esi
  __int64 v28; // r8
  unsigned int v29; // esi
  int v30; // edx
  __int64 v31; // rax
  __int64 v32; // rcx
  int v33; // esi
  __int64 v34; // r14
  bool v35; // r9
  __int64 v36; // rax
  __int64 v37; // r11
  int v38; // r10d
  __int64 v39; // rcx
  __int64 v40; // r11
  __int64 v41; // rax
  unsigned int v42; // eax
  int v43; // edx
  int v44; // r14d
  int v45; // eax
  unsigned int AppDataStatus; // eax
  CCipherMill *v47; // rcx
  __int64 v48; // rdx
  unsigned __int8 *v49; // rdx
  int v50; // r9d
  int v51; // r15d
  unsigned __int64 v52; // r11
  CCipherMill *v53; // r10
  unsigned int v54; // eax
  bool v55; // zf
  __int64 v56; // rax
  __int64 v57; // rdx
  int v58; // r15d
  int v59; // eax
  __int64 v60; // rax
  __int64 v61; // rdx
  int v62; // r15d
  int v63; // eax
  int v64; // eax
  unsigned int v65; // r15d
  struct DTlsMessage *NextReadyHandshakeMsg; // rax
  unsigned int v67; // ecx
  int v68; // eax
  struct DTlsMessage *v69; // rax
  unsigned int ResponseCommon; // eax
  __int64 v71; // rdx
  CCipherMill *v72; // rcx
  __int64 v73; // rdx
  unsigned int v74; // edi
  unsigned int UserKeys; // eax
  struct kexch *KeyExchangeInfo; // rax
  int v77; // r10d
  _DWORD *v78; // r11
  __int64 v79; // [rsp+20h] [rbp-100h]
  __int64 v80; // [rsp+28h] [rbp-F8h]
  unsigned int v81; // [rsp+A0h] [rbp-80h]
  unsigned int v82; // [rsp+A0h] [rbp-80h]
  int v83; // [rsp+A0h] [rbp-80h]
  unsigned int v84; // [rsp+A4h] [rbp-7Ch]
  DTlsMessage *v85; // [rsp+A8h] [rbp-78h]
  DTlsMessage *v86; // [rsp+A8h] [rbp-78h]
  int v87; // [rsp+B0h] [rbp-70h]
  unsigned int v88; // [rsp+B4h] [rbp-6Ch]
  unsigned __int64 v89; // [rsp+B8h] [rbp-68h]
  unsigned __int8 *v90; // [rsp+C0h] [rbp-60h]
  __int64 v91; // [rsp+C8h] [rbp-58h] BYREF
  __int64 v92; // [rsp+D0h] [rbp-50h]
  int v93; // [rsp+D8h] [rbp-48h]
  int v94; // [rsp+DCh] [rbp-44h]
  unsigned __int64 v95; // [rsp+E0h] [rbp-40h]
  int v96[2]; // [rsp+E8h] [rbp-38h] BYREF
  unsigned __int8 *v97; // [rsp+F0h] [rbp-30h]
  int v98[2]; // [rsp+F8h] [rbp-28h] BYREF
  unsigned __int8 *v99; // [rsp+100h] [rbp-20h]
  int v100[2]; // [rsp+108h] [rbp-18h] BYREF
  unsigned __int8 *v101; // [rsp+110h] [rbp-10h]
  char v102[8]; // [rsp+120h] [rbp+0h] BYREF
  int v103; // [rsp+128h] [rbp+8h]
  int v104; // [rsp+12Ch] [rbp+Ch]
  bool v105; // [rsp+860h] [rbp+740h]
  unsigned int v108; // [rsp+878h] [rbp+758h]

  v3 = 0;
  v5 = a2;
  v87 = 0;
  v94 = *((_DWORD *)a2 + 1);
  v7 = 5;
  if ( *((_BYTE *)this + 233) )
    v7 = 13;
  v8 = *(_QWORD *)this;
  v105 = 0;
  v92 = 0i64;
  v91 = 0i64;
  result = (*(__int64 (__fastcall **)(CSsl3TlsContext *))(v8 + 432))(this);
  v81 = result;
  v10 = result;
  if ( (_DWORD)result )
    return result;
  v11 = *((_DWORD *)this + 17);
  if ( (v11 < 6 || v11 >= 91) && v11 >= 2 )
  {
    switch ( v11 )
    {
      case 2:
      case 4:
      case 5:
      case 91:
      case 93:
      case 95:
      case 96:
      case 98:
      case 99:
      case 100:
      case 101:
      case 102:
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        if ( *((_BYTE *)this + 233) && *((_DWORD *)this + 17) == 91 )
        {
          result = CSsl3TlsContext::GenerateResponseCommon(this, (struct SPBuffer *)&v91);
          if ( !(_DWORD)result && v92 )
            result = CSsl3TlsContext::DtlsGetOutgoingRecord(this, (struct SPBuffer *)&v91, a3);
        }
        else
        {
          result = CSsl3TlsContext::GenerateResponseCommon(this, a3);
        }
        break;
      default:
        goto LABEL_6;
    }
    return result;
  }
LABEL_6:
  if ( v11 == 76 && !*((_BYTE *)this + 555) && *((_QWORD *)v5 + 1) && (*((_DWORD *)this + 16) & 0x50000) != 0 )
  {
    v12 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
      v12 = WPP_GLOBAL_Control;
      v10 = 0;
    }
    if ( *((_BYTE *)this + 266) )
    {
      if ( *((_DWORD *)this + 18) == 77 )
      {
LABEL_136:
        v105 = *((_BYTE *)this + 472) == 0;
        goto LABEL_8;
      }
      *((_DWORD *)this + 18) = *((_DWORD *)this + 17);
    }
    AppDataStatus = RemotelyGetAppDataStatus(this);
    v81 = AppDataStatus;
    v10 = AppDataStatus;
    if ( AppDataStatus == 590610 )
    {
      *((_DWORD *)this + 17) = 77;
      v47 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v48 = 12i64;
        goto LABEL_296;
      }
      return 590610i64;
    }
    if ( AppDataStatus )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 13i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        return v81;
      }
      return v10;
    }
    v12 = WPP_GLOBAL_Control;
    goto LABEL_136;
  }
  v12 = WPP_GLOBAL_Control;
LABEL_8:
  v13 = (unsigned __int8 *)*((_QWORD *)v5 + 1);
  v14 = *((_DWORD *)v5 + 1);
  v90 = v13;
  v88 = v14;
  while ( 1 )
  {
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
    {
      WPP_SF_(*((_QWORD *)v12 + 2), 14i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
      v12 = WPP_GLOBAL_Control;
      v10 = v81;
    }
    if ( v14 < v7 )
      break;
    v15 = *v13;
    v108 = v15;
    if ( (unsigned int)(v15 - 20) > 3 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 10, -2146893048, 0xAu);
      return 2148074248i64;
    }
    v16 = v13[2] | (v13[1] << 8);
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
    {
      WPP_SF_D(*((_QWORD *)v12 + 2), 15i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, v16);
      v12 = WPP_GLOBAL_Control;
      v15 = v108;
    }
    if ( v16 < 0x300 )
    {
      if ( *((_DWORD *)this + 9) >= 0x302u && (*((_DWORD *)this + 16) & 0x800A00AA) != 0 )
      {
        v74 = -2146893018;
        CSslContext::SetError((__int64)this, 11, -2146893018);
      }
      else
      {
        v74 = -2146893048;
        CSslContext::SetErrorAndFatalAlert((__int64)this, 11, -2146893048, 0x46u);
      }
      return v74;
    }
    if ( v13[1] == 0xFE && (v13[2] | (v13[1] << 8)) <= 0xFEFFu )
    {
      v17 = v13[11];
      v18 = v13[12];
    }
    else
    {
      v17 = v13[3];
      v18 = v13[4];
    }
    v19 = v18 | (v17 << 8);
    v84 = v19;
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
    {
      WPP_SF_D(*((_QWORD *)v12 + 2), 16i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, v19);
      v15 = v108;
    }
    v20 = v19 + v7;
    v93 = v19 + v7;
    if ( v19 + v7 > v88 )
    {
      if ( !v87 )
      {
        *((_DWORD *)v5 + 1) = v20;
        CSslContext::SetError((__int64)this, 13, -2146893032);
        return 2148074264i64;
      }
      v10 = v81;
LABEL_104:
      if ( *((_BYTE *)this + 233) && !v10 )
      {
        if ( v92 )
          return (unsigned int)CSsl3TlsContext::DtlsGetOutgoingRecord(this, (struct SPBuffer *)&v91, a3);
      }
      return v10;
    }
    *((_DWORD *)v5 + 1) = v20 + v87;
    v87 += v20;
    if ( *((_BYTE *)this + 233) )
    {
      v49 = 0i64;
      v50 = 0;
      v51 = 0;
      v83 = 0;
      v86 = 0i64;
      v95 = v13[10] | ((v13[9] | ((v13[8] | ((v13[7] | ((v13[6] | ((v13[5] | ((v13[4] | ((unsigned __int64)v13[3] << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) << 8);
      v52 = HIWORD(v95);
      v89 = HIWORD(v95);
      v53 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
      {
        if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LODWORD(v79) = v95;
          WPP_SF_DD(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x11u,
            (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
            v52,
            v79);
          v53 = WPP_GLOBAL_Control;
          v20 = v19 + v7;
          LOBYTE(v15) = v108;
          v49 = 0i64;
          LODWORD(v52) = v89;
          v50 = 0;
        }
        if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
        {
          LODWORD(v80) = **((_DWORD **)this + 28);
          LODWORD(v79) = *((unsigned __int16 *)this + 110);
          WPP_SF_DDD(
            *((_QWORD *)v53 + 2),
            0x12u,
            (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
            *((_DWORD *)this + 48),
            v79,
            v80);
          v53 = WPP_GLOBAL_Control;
          v20 = v19 + v7;
          LOBYTE(v15) = v108;
          v49 = 0i64;
          LODWORD(v52) = v89;
          v50 = 0;
        }
      }
      if ( v105 )
      {
        if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)v53 + 2), 19i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          v53 = WPP_GLOBAL_Control;
          v20 = v19 + v7;
          LOBYTE(v15) = v108;
          v49 = 0i64;
          LODWORD(v52) = v89;
          v50 = 0;
        }
        v54 = *((_DWORD *)this + 48);
        v55 = (_DWORD)v52 == v54;
        if ( (unsigned int)v52 < v54 )
        {
          if ( (_BYTE)v15 == 20 )
          {
            if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v53 + 28) & 4) != 0 )
              {
                v71 = 20i64;
                goto LABEL_272;
              }
              goto LABEL_273;
            }
            goto LABEL_276;
          }
          v55 = (_DWORD)v52 == v54;
        }
        if ( v55 )
        {
          if ( (_BYTE)v15 == 23 )
          {
            if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control )
            {
              if ( (*((_BYTE *)v53 + 28) & 4) != 0 )
              {
                v71 = 21i64;
LABEL_272:
                WPP_SF_(*((_QWORD *)v53 + 2), v71, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
                v53 = WPP_GLOBAL_Control;
              }
LABEL_273:
              if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
                WPP_SF_(*((_QWORD *)v53 + 2), 27i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
            }
LABEL_276:
            LogDtlsRetransmitRequested(
              *(_DWORD *)(*((_QWORD *)this + 10) + 212i64),
              (const unsigned __int16 *)(*((_QWORD *)this + 10) + 216i64));
            DTlsMsgMgr::swapSaveAndOutgoing(*((DTlsMsgMgr **)this + 72));
            v74 = CSsl3TlsContext::RestoreWriteCipherState(this);
            if ( v74 )
            {
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 28i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
                return v74;
              }
            }
            else
            {
              *((_QWORD *)this + 17) &= ~0x40000000ui64;
              *((_BYTE *)this + 265) = 1;
              *((_DWORD *)this + 17) = 4;
              if ( v83 || *((_BYTE *)this + 266) )
                return CSsl3TlsContext::PrepareNextOutgoingRecord(this, a3);
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 29i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              }
              UserKeys = RemotelyGetUserKeys(this, 1u);
              v74 = UserKeys;
              if ( !UserKeys )
                return CSsl3TlsContext::PrepareNextOutgoingRecord(this, a3);
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                WPP_SF_D(
                  *((_QWORD *)WPP_GLOBAL_Control + 2),
                  30i64,
                  &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
                  UserKeys);
                return v74;
              }
            }
            return v74;
          }
          if ( (_BYTE)v15 == 22 && (*((_BYTE *)this + 32) & 2) != 0 )
          {
            v56 = *((_QWORD *)this + 1);
            if ( v56 )
            {
              if ( *(_DWORD *)(v56 + 28) )
              {
                if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
                {
                  WPP_SF_(*((_QWORD *)v53 + 2), 22i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
                  v20 = v19 + v7;
                }
                v96[0] = v20;
                v96[1] = v20;
                v97 = v13;
                if ( (unsigned int)CSsl3TlsContext::UnwrapMessage(this, (struct SPBuffer *)v96) )
                {
                  v47 = WPP_GLOBAL_Control;
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                  {
                    v48 = 23i64;
                    goto LABEL_296;
                  }
                  return 590610i64;
                }
                v50 = 1;
                v83 = 1;
                if ( (*((_BYTE *)this + 32) & 2) != 0 )
                  v57 = *((unsigned int *)this + 11);
                else
                  v57 = 0i64;
                if ( v13[1] == 0xFE && (v13[2] | (v13[1] << 8)) <= 0xFEFFu )
                {
                  v58 = v13[11];
                  v59 = v13[12];
                }
                else
                {
                  v58 = v13[3];
                  v59 = v13[4];
                }
                v51 = v59 | (v58 << 8);
                if ( v19 < (unsigned int)v57 + v51 + v7 )
                {
                  v72 = WPP_GLOBAL_Control;
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                  {
                    v73 = 24i64;
                    goto LABEL_310;
                  }
                  return 2148074278i64;
                }
                v49 = &v13[v7 + v57];
                v86 = (DTlsMessage *)v49;
                if ( !v51 )
                {
                  v72 = WPP_GLOBAL_Control;
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                  {
                    v73 = 25i64;
                    goto LABEL_310;
                  }
                  return 2148074278i64;
                }
                if ( *v49 == 20 )
                {
                  v53 = WPP_GLOBAL_Control;
                  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
                  {
                    if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      v71 = 26i64;
                      goto LABEL_272;
                    }
                    goto LABEL_273;
                  }
                  goto LABEL_276;
                }
                v53 = WPP_GLOBAL_Control;
                v20 = v19 + v7;
                LODWORD(v52) = v89;
              }
            }
          }
        }
      }
      if ( *((_DWORD *)this + 17) == 76 && *((_BYTE *)this + 233) )
      {
        if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)v53 + 2), 31i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          v50 = v83;
          LODWORD(v52) = v89;
        }
        *(_DWORD *)(*((_QWORD *)this + 73) + 36i64) = *(__int16 *)(*(_QWORD *)(*((_QWORD *)this + 73) + 40i64) + 192i64);
        v20 = v19 + v7;
        v53 = WPP_GLOBAL_Control;
        v49 = (unsigned __int8 *)v86;
      }
      if ( (*((_BYTE *)this + 32) & 2) != 0 && (v60 = *((_QWORD *)this + 1)) != 0 && *(_DWORD *)(v60 + 28) )
      {
        if ( !v50 )
        {
          if ( (_DWORD)v52 == *(_DWORD *)(*((_QWORD *)this + 73) + 36i64) )
          {
            if ( (unsigned int)v52 < *((_DWORD *)this + 48) )
            {
              if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
                WPP_SF_(*((_QWORD *)v53 + 2), 32i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              LogDtlsRecordOutOfRecvWindow(
                *(_DWORD *)(*((_QWORD *)this + 10) + 212i64),
                (const unsigned __int16 *)(*((_QWORD *)this + 10) + 216i64));
              return 590610i64;
            }
            if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
            {
              WPP_SF_(*((_QWORD *)v53 + 2), 33i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              v20 = v19 + v7;
            }
            v98[0] = v20;
            v98[1] = v20;
            v99 = v13;
            if ( (unsigned int)CSsl3TlsContext::UnwrapMessage(this, (struct SPBuffer *)v98) )
            {
              v47 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                v48 = 34i64;
LABEL_296:
                WPP_SF_(*((_QWORD *)v47 + 2), v48, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              }
              return 590610i64;
            }
            if ( (*((_BYTE *)this + 32) & 2) != 0 )
              v61 = *((unsigned int *)this + 11);
            else
              v61 = 0i64;
            if ( v13[1] == 0xFE && (v13[2] | (v13[1] << 8)) <= 0xFEFFu )
            {
              v62 = v13[11];
              v63 = v13[12];
            }
            else
            {
              v62 = v13[3];
              v63 = v13[4];
            }
            v51 = v63 | (v62 << 8);
            if ( v19 < (unsigned int)v61 + v51 + v7 )
            {
              v72 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                v73 = 35i64;
                goto LABEL_310;
              }
              return 2148074278i64;
            }
            v49 = &v13[v7 + v61];
            goto LABEL_202;
          }
LABEL_198:
          if ( v53 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v53 + 28) & 4) != 0 )
            WPP_SF_(*((_QWORD *)v53 + 2), 36i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          v51 = v19;
          v49 = &v13[v7];
        }
      }
      else if ( !v50 )
      {
        goto LABEL_198;
      }
LABEL_202:
      DTlsHandshakeQueue::DtlsReorderHandshake(*((_QWORD *)this + 73), v108, (__int64)v49, v51, v95);
      v15 = v108;
      v20 = v93;
    }
    v21 = 0i64;
    v85 = 0i64;
    v22 = v15;
    v82 = v15;
    v23 = 0i64;
    v24 = 0;
    if ( (*((_DWORD *)this + 16) & 0x3000) != 0 && (_BYTE)v15 == 20 )
    {
      v29 = v84;
      v64 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, unsigned __int8 *, _QWORD, _QWORD))(*(_QWORD *)this + 488i64))(
              this,
              v13,
              v7,
              v84);
      v65 = v64;
      if ( v64 )
      {
        if ( v64 == -2146893018 || v64 == -2146893048 )
          CSslContext::SetErrorAndFatalAlert((__int64)this, 904, v64, 0xAu);
        return v65;
      }
      v12 = WPP_GLOBAL_Control;
      v24 = 0;
    }
    else
    {
      if ( *((_BYTE *)this + 233) )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 54i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        NextReadyHandshakeMsg = DTlsHandshakeQueue::GetNextReadyHandshakeMsg(*((DTlsMsgMgr ***)this + 73), v21, v15);
        v85 = NextReadyHandshakeMsg;
        v21 = (__int64)NextReadyHandshakeMsg;
        if ( NextReadyHandshakeMsg )
        {
          v22 = *((_DWORD *)NextReadyHandshakeMsg + 16);
          v23 = (unsigned __int8 *)*((_QWORD *)NextReadyHandshakeMsg + 5);
          v24 = *((_DWORD *)NextReadyHandshakeMsg + 5);
          v82 = v22;
        }
        else
        {
          v22 = v82;
        }
        v12 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 55i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, v22);
          v12 = WPP_GLOBAL_Control;
          v22 = v82;
          v21 = (__int64)v85;
        }
        LODWORD(v15) = v108;
      }
      else
      {
        v24 = v20;
        v23 = v13;
        v12 = WPP_GLOBAL_Control;
      }
      if ( v23 )
      {
        v25 = v24;
        while ( 1 )
        {
          if ( (*((_BYTE *)this + 32) & 2) != 0
            && (v41 = *((_QWORD *)this + 1)) != 0
            && *(_DWORD *)(v41 + 28)
            && (!*((_BYTE *)this + 233) || v21 && *(_DWORD *)(v21 + 68)) )
          {
            v42 = *((_DWORD *)this + 17) - 78;
            v100[0] = v24;
            v100[1] = v24;
            v101 = v23;
            if ( v42 <= 1 && v25 > v7 && *v23 == 22 )
            {
              if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
              {
                WPP_SF_(*((_QWORD *)v12 + 2), 37i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
                LODWORD(v15) = v108;
                v22 = v82;
              }
              v67 = *(unsigned __int16 *)&v23[v25 - 2];
              if ( v67 > v25 - v7 )
                return 2148074248i64;
              if ( *((_BYTE *)this + 233) )
              {
                v23[11] = BYTE1(v67);
                v23[12] = v67;
              }
              else
              {
                v23[3] = BYTE1(v67);
                v23[4] = v67;
              }
            }
            else
            {
              if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
                WPP_SF_(*((_QWORD *)v12 + 2), 38i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              result = CSsl3TlsContext::UnwrapMessage(this, (struct SPBuffer *)v100);
              if ( (_DWORD)result )
              {
                if ( !*((_BYTE *)this + 233) )
                  return result;
                if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
                {
                  WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 39i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
                }
              }
              if ( (*((_DWORD *)this + 16) & 0x3000) != 0 )
              {
                LODWORD(v15) = *v23;
                v108 = v15;
                v22 = v15;
                if ( (_DWORD)v15 == 20 )
                {
                  CSslContext::SetErrorAndFatalAlert((__int64)this, 904, -2146893018, 0xAu);
                  return 2148074278i64;
                }
              }
              else
              {
                LODWORD(v15) = v108;
                v22 = v82;
              }
            }
            if ( (*((_BYTE *)this + 32) & 2) != 0 )
              v43 = *((_DWORD *)this + 11);
            else
              v43 = 0;
            if ( v23[1] == 0xFE && (v23[2] | (v23[1] << 8)) <= 0xFEFFu )
            {
              v44 = v23[11];
              v45 = v23[12];
            }
            else
            {
              v44 = v23[3];
              v45 = v23[4];
            }
            v25 = v45 | (v44 << 8);
            if ( v24 < v43 + v25 + v7 )
            {
              v72 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
              {
                v73 = 40i64;
LABEL_310:
                WPP_SF_(*((_QWORD *)v72 + 2), v73, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              }
              return 2148074278i64;
            }
            v23 += v7 + v43;
          }
          else if ( !*((_BYTE *)this + 233) || v22 == 20 )
          {
            v23 += v7;
            v25 -= v7;
          }
          if ( (((_DWORD)v15 - 20) & 0xFFFFFFFC) == 0 && (_DWORD)v15 != 21 )
            *((_BYTE *)this + 473) = 0;
          v27 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, _QWORD, unsigned __int8 *, _QWORD))(*(_QWORD *)this
                                                                                                + 464i64))(
                  this,
                  v22,
                  v23,
                  v25);
          if ( v27 )
            break;
          if ( v85 )
            DTlsMessage::`scalar deleting destructor'(v85);
          v23 = 0i64;
          v24 = 0;
          v82 = v108;
          if ( (*((_DWORD *)this + 16) & 0x3000) != 0 && v108 == 20 )
          {
            v68 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, _QWORD, _QWORD, _QWORD))(*(_QWORD *)this + 488i64))(
                    this,
                    0i64,
                    0i64,
                    0i64);
            v27 = v68;
            if ( !v68 )
            {
LABEL_42:
              v12 = WPP_GLOBAL_Control;
LABEL_44:
              v13 = v90;
              goto LABEL_45;
            }
            if ( v68 == -2146893018 || v68 == -2146893048 )
            {
              CSslContext::SetErrorAndFatalAlert((__int64)this, 904, v68, 0xAu);
              return v27;
            }
            return v27;
          }
          if ( !*((_BYTE *)this + 233) )
            goto LABEL_42;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 54i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          }
          v69 = DTlsHandshakeQueue::GetNextReadyHandshakeMsg(*((DTlsMsgMgr ***)this + 73), v26, v28);
          v85 = v69;
          v21 = (__int64)v69;
          if ( v69 )
          {
            v22 = *((_DWORD *)v69 + 16);
            v23 = (unsigned __int8 *)*((_QWORD *)v69 + 5);
            v24 = *((_DWORD *)v69 + 5);
            v82 = v22;
          }
          else
          {
            v22 = v108;
          }
          v12 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 55i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, v22);
            v12 = WPP_GLOBAL_Control;
            v22 = v82;
            v21 = (__int64)v85;
          }
          v25 = v24;
          if ( !v23 )
            goto LABEL_44;
          LODWORD(v15) = v108;
        }
        if ( (*((_DWORD *)this + 34) & 0x40000) != 0 )
        {
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 41i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          }
          *((_DWORD *)a2 + 1) = v94;
        }
        else if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
               && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
        {
          WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 42i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, v27);
        }
        return v27;
      }
LABEL_45:
      v29 = v84;
    }
    if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
    {
      WPP_SF_d(*((_QWORD *)v12 + 2), 0x2Bu, (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids, v24);
      v12 = WPP_GLOBAL_Control;
    }
    v30 = *((_DWORD *)this + 17);
    v13 += v29 + v7;
    v14 = v88 - (v29 + v7);
    v90 = v13;
    v88 = v14;
    if ( (unsigned int)(v30 - 91) <= 0xB )
    {
      if ( !*((_BYTE *)this + 233) )
        return CSsl3TlsContext::GenerateResponseCommon(this, a3);
      ResponseCommon = CSsl3TlsContext::GenerateResponseCommon(this, (struct SPBuffer *)&v91);
      v30 = *((_DWORD *)this + 17);
      v10 = ResponseCommon;
      v12 = WPP_GLOBAL_Control;
    }
    else
    {
      v10 = 0;
    }
    v81 = v10;
    if ( v30 == 4 || v30 == 79 || !v14 )
      goto LABEL_104;
    v5 = a2;
  }
  if ( v87 )
    goto LABEL_104;
  *((_DWORD *)v5 + 1) = v7;
  v31 = *((_QWORD *)this + 16);
  if ( !*(_WORD *)(v31 + 34) )
  {
    *(_WORD *)(v31 + 34) = 13;
    *(_DWORD *)(v31 + 36) = -2146893032;
  }
  memset_0(v102, 0, 0x6E8ui64);
  v32 = *((_QWORD *)this + 1);
  if ( v32 )
    v3 = *(_DWORD *)(v32 + 28);
  v33 = *((unsigned __int16 *)this + 17);
  v34 = *((_QWORD *)this + 17);
  v35 = CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
  v104 = *((_DWORD *)this + 4);
  v103 = v3;
  if ( v32 )
  {
    v36 = *((_QWORD *)this + 11);
    if ( v36 )
    {
      v37 = *((_QWORD *)this + 15);
      v38 = *(_DWORD *)(v32 + 32);
      if ( v37 )
      {
        if ( CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
        {
          *(_DWORD *)(v37 + 48) = *(_DWORD *)(v36 + 8);
          if ( v38 == 43522 || v38 == 41984 )
          {
            KeyExchangeInfo = GetKeyExchangeInfo(v38);
            if ( KeyExchangeInfo )
            {
              v78[13] = *((_DWORD *)KeyExchangeInfo + 8);
              v78[14] = *((_DWORD *)KeyExchangeInfo + 10);
              if ( v77 == 43522 )
                v78[15] = *((_DWORD *)KeyExchangeInfo + 12);
            }
          }
        }
      }
    }
  }
  v39 = *((_QWORD *)this + 15);
  v40 = v39;
  if ( v39 && v35 )
  {
    *(_DWORD *)(v39 + 36) = v104;
    *(_DWORD *)(v39 + 104) = -2146893032;
    *(_DWORD *)(v39 + 112) = 13;
    *(_DWORD *)(v39 + 32) = v3;
    *(_DWORD *)(v39 + 40) = v33;
    *(_QWORD *)(v39 + 128) = v34;
    v40 = *((_QWORD *)this + 15);
  }
  if ( v40
    && v35
    && WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_SSSdiiDDDDDddiDDd(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      *(unsigned __int16 *)(v40 + 66),
      *(unsigned __int16 *)(v40 + 64),
      L"Error",
      (const wchar_t *)(v40 + 152),
      (const wchar_t *)(v40 + 664),
      *(_DWORD *)(v40 + 24),
      *(_QWORD *)(v40 + 120),
      *(_QWORD *)(v40 + 128),
      *(_DWORD *)(v40 + 32),
      *(_DWORD *)(v40 + 36),
      *(_DWORD *)(v40 + 40),
      *(_DWORD *)(v40 + 44),
      *(_DWORD *)(v40 + 48),
      *(_WORD *)(v40 + 64),
      *(_WORD *)(v40 + 66),
      *(_QWORD *)(v40 + 96),
      *(_DWORD *)(v40 + 104),
      *(unsigned __int8 *)(v40 + 108),
      *(_DWORD *)(v40 + 112));
  }
  return 2148074264i64;
}
// 18003B4F3: conditional instruction was optimized away because rsi.8!=0
// 180011D98: variable 'v35' is possibly undefined
// 18003B056: variable 'v79' is possibly undefined
// 18003B0B2: variable 'v80' is possibly undefined
// 18003B464: variable 'v21' is possibly undefined
// 18003B464: variable 'v15' is possibly undefined
// 18003B6C0: variable 'v26' is possibly undefined
// 18003B6C0: variable 'v28' is possibly undefined
// 18003BB51: variable 'v78' is possibly undefined
// 18003BB63: variable 'v77' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;
// 1800119B0: using guessed type char var_730[8];
