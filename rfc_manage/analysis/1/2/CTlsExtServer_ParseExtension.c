//----- (000000018001E0C0) ----------------------------------------------------
__int64 __fastcall CTlsExtServer::ParseExtension(__int64 a1, int a2,
                                                 unsigned __int8 *a3,
                                                 unsigned __int16 a4) {
  unsigned __int8 *v4;        // r15
  __int64 v6;                 // r14
  __int16 *v7;                // r8
  __int64 v8;                 // rcx
  __int64 result;             // rax
  __int64 v10;                // r11
  int v11;                    // esi
  int v12;                    // eax
  int v13;                    // r9d
  int v14;                    // ebx
  _WORD *v15;                 // rdi
  unsigned int v16;           // ebx
  unsigned int v17;           // ecx
  __int64 v18;                // r10
  unsigned __int8 v19;        // cl
  void **v20;                 // rax
  __int16 v21;                // dx
  int v22;                    // eax
  __int64 v23;                // rax
  __int16 v24;                // bx
  unsigned int v25;           // esi
  __int16 v26;                // ax
  unsigned __int16 *v27;      // rdi
  _QWORD *v28;                // rcx
  unsigned __int16 v29;       // bx
  __int64 v30;                // rcx
  HLOCAL v31;                 // rax
  __int64 v32;                // rax
  __int64 v33;                // rbp
  __int64 v34;                // rcx
  __int64 v35;                // rcx
  __int64 v36;                // rcx
  __int64 v37;                // rax
  __int64 v38;                // rcx
  __int64 v39;                // rax
  __int64 v40;                // rcx
  size_t v41;                 // rbx
  const void *v42;            // r15
  int v43;                    // r8d
  int v44;                    // ebp
  CCipherMill *v45;           // rcx
  __int64 v46;                // r8
  unsigned __int16 v47;       // dx
  __int64 v48;                // rbx
  unsigned __int8 *v49;       // rbp
  unsigned __int16 v50;       // r12
  unsigned __int8 *v51;       // rcx
  unsigned __int64 v52;       // r13
  __int64 v53;                // rax
  unsigned __int8 *v54;       // rcx
  __int64 v55;                // rax
  unsigned __int8 *v56;       // rcx
  unsigned int v57;           // esi
  unsigned __int64 v58;       // rax
  unsigned __int8 *v59;       // rdi
  SIZE_T v60;                 // rsi
  unsigned __int8 *v61;       // r15
  __int64 v62;                // r12
  unsigned int v63;           // eax
  _WORD *v64;                 // rax
  __int64 v65;                // rax
  __int16 v66;                // ax
  unsigned int v67;           // ecx
  _BYTE *v68;                 // rdi
  unsigned int v69;           // edi
  CCipherMill *v70;           // rcx
  __int64 v71;                // rdx
  CCipherMill *v72;           // rcx
  __int64 v73;                // rdx
  __int64 v74;                // rcx
  __int64 v75;                // r10
  unsigned __int16 v76;       // r8
  unsigned __int16 v77;       // r9
  unsigned __int16 v78;       // cx
  CSsl3TlsServerContext *v79; // rcx
  __int64 v80;                // rbx
  __int64 v81;                // rcx
  __int64 v82;                // rcx
  unsigned __int16 v83;       // dx
  int v84;                    // r9d
  __int64 v85;                // rax
  CCipherMill *v86;           // rbp
  unsigned __int16 v87;       // [rsp+30h] [rbp-98h]
  unsigned int v88;           // [rsp+34h] [rbp-94h]
  char *v89;                  // [rsp+38h] [rbp-90h]
  __int64 v90;                // [rsp+40h] [rbp-88h]
  unsigned __int64 v91;       // [rsp+48h] [rbp-80h]
  unsigned __int8 *v93;       // [rsp+58h] [rbp-70h]
  __int16 v94;                // [rsp+60h] [rbp-68h] BYREF
  __int128 v95[2];            // [rsp+62h] [rbp-66h] BYREF
  unsigned __int16 v96;       // [rsp+82h] [rbp-46h]

  v4 = 0i64;
  v89 = 0i64;
  v6 = a1;
  if (a2 != 65281) {
    if (a2 > 65281) {
    LABEL_220:
      CSchannelTelemetryContext::LogUnknownTlsExtension(
          *(CSchannelTelemetryContext **)(*(_QWORD *)(a1 + 8) + 120i64), a2);
    } else {
      v7 = &_ImageBase;
      switch (a2) {
      case 0:
        v80 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 80i64);
        if (!(unsigned int)CTlsExtServer::ParseServerNameExtension(
                (CSsl3TlsServerContext **)a1, a3, a4) &&
            (*(_DWORD *)(v80 + 156) & 0x100) != 0) {
          *(_QWORD *)(*(_QWORD *)(v6 + 8) + 136i64) |= 0x200000ui64;
        }
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(
            *(_QWORD *)(*(_QWORD *)(v6 + 8) + 120i64), 1, 0);
        return 0i64;
      case 5:
        if (a4 && *a3 == 1) {
          *(_QWORD *)(*(_QWORD *)(a1 + 8) + 136i64) |= 0x20000ui64;
          CSchannelTelemetryContext::LogTlsExtensionTelemetry(
              *(_QWORD *)(*(_QWORD *)(a1 + 8) + 120i64), 1, 5);
        } else if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
                   (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0) {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 56i64,
                  &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
        }
        return 0i64;
      case 6:
        v67 = *a3;
        v68 = a3 + 1;
        if (v67 != a4 - 1)
          return 2148074278i64;
        if (!v67)
          goto LABEL_115;
        while (*v68 != 64) {
          LODWORD(v4) = (_DWORD)v4 + 1;
          ++v68;
          if ((unsigned int)v4 >= v67)
            goto LABEL_115;
        }
        if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
            (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 54i64,
                  &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
        }
        *(_BYTE *)(*(_QWORD *)(v6 + 8) + 922i64) = 1;
      LABEL_115:
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(
            *(_QWORD *)(*(_QWORD *)(v6 + 8) + 120i64), 1, 6);
        return 0i64;
      case 10:
        if (a4 < 2u)
          return (unsigned int)-2146893018;
        v24 = *a3;
        v25 = a4 - 2;
        v26 = a3[1];
        v27 = (unsigned __int16 *)(a3 + 2);
        v28 = *(_QWORD **)(a1 + 8);
        v29 = v26 | (v24 << 8);
        if (v28[114]) {
          (*(void(__fastcall **)(_QWORD *))(*v28 + 16i64))(v28);
          v28 = *(_QWORD **)(v6 + 8);
        }
        v30 = *(_QWORD *)(v28[16] + 24i64);
        if (v30) {
          LOBYTE(v7) = 1;
          v31 = (HLOCAL)(*(__int64(__fastcall **)(__int64, _QWORD, __int16 *))(
              *(_QWORD *)v30 + 48i64))(v30, v29, v7);
        } else if (LsaTable) {
          v31 = (HLOCAL)(*(__int64(__fastcall **)(_QWORD))(LsaTable + 40))(v29);
        } else {
          v31 = LocalAlloc(0x40u, v29);
        }
        *(_QWORD *)(*(_QWORD *)(v6 + 8) + 912i64) = v31;
        v32 = *(_QWORD *)(v6 + 8);
        if (!*(_QWORD *)(v32 + 912))
          return 14;
        if (v29 < 2u || v25 != v29 || (v29 & 1) != 0)
          return (unsigned int)-2146893018;
        if (v25 > 1) {
          v33 = ((v25 - 2) >> 1) + 1;
          do {
            *(_WORD *)(2i64 * (unsigned int)v4 +
                       *(_QWORD *)(*(_QWORD *)(v6 + 8) + 912i64)) =
                _byteswap_ushort(*v27);
            if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
                (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) {
              WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 27i64,
                       &WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
                       *(unsigned __int16 *)(*(_QWORD *)(*(_QWORD *)(v6 + 8) +
                                                         912i64) +
                                             2i64 * (unsigned int)v4));
            }
            LODWORD(v4) = (_DWORD)v4 + 1;
            ++v27;
            --v33;
          } while (v33);
          v32 = *(_QWORD *)(v6 + 8);
        }
        *(_WORD *)(v32 + 920) = v29 >> 1;
        v34 = *(_QWORD *)(*(_QWORD *)(v6 + 8) + 120i64);
        if (v34 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
          *(_DWORD *)(v34 + 72) |= 0x80u;
        return 0i64;
      case 11:
        v35 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 120i64);
        if (v35 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
          *(_DWORD *)(v35 + 72) |= 0x100u;
        return 0i64;
      case 13:
        v10 = *(_QWORD *)(a1 + 8);
        if ((*(_DWORD *)(v10 + 64) & 0x41400) == 0)
          goto LABEL_32;
        v94 = 0;
        memset(v95, 0, sizeof(v95));
        if (*(_BYTE *)(v10 + 925))
          return (unsigned int)-2146893018;
        v11 = a4;
        if (!a3)
          return (unsigned int)-2146893018;
        if (a4 < 2u)
          return (unsigned int)-2146893018;
        v12 = a3[1];
        LOWORD(v13) = 0;
        v14 = *a3;
        v15 = a3 + 2;
        v16 = v12 | (v14 << 8);
        v94 = 0;
        v96 = 0;
        v17 = v16 >> 1;
        if (v16 > v11 - 2 || (v16 & 1) != 0 || v17 - 1 > 0x4F)
          return (unsigned int)-2146893018;
        if (!v17)
          return (unsigned int)-2146893007;
        v18 = v17;
        do {
          v19 = 0;
          v20 = (void **)&unk_18007C390;
          v21 = __ROR2__(*v15, 8);
          while (v21 != *(_WORD *)v20) {
            v20 += 9;
            ++v19;
            if (v20 >= &CSsl3TlsServerContext::vftable)
              goto LABEL_28;
          }
          if (v19 < 0xCu) {
            v22 = (unsigned __int16)v13;
            if (!_bittest(&v22, v19) && (unsigned __int16)v4 < 0x10u) {
              *((_WORD *)v95 + (unsigned __int16)v4) =
                  __ROR2__(*((_WORD *)&unk_18007C390 + 36 * v19), 8);
              LOWORD(v4) = v94 + 1;
              v13 = v96 | (1 << v19);
              ++v94;
              v96 |= 1 << v19;
            }
          }
        LABEL_28:
          ++v15;
          --v18;
        } while (v18);
        if (!(_WORD)v4)
          return (unsigned int)-2146893007;
        if (v11 != v16 + 2)
          return (unsigned int)-2146893018;
        CTlsSignatureSuiteList::SetSignatureSuiteList(
            (CTlsSignatureSuiteList *)(v10 + 510),
            (const struct CTlsSignatureSuiteList *)(v10 + 474));
        CTlsSignatureSuiteList::Restrict(
            (CTlsSignatureSuiteList *)(*(_QWORD *)(v6 + 8) + 510i64),
            (const struct CTlsSignatureSuiteList *)&v94,
            *(_DWORD *)(*(_QWORD *)(v6 + 8) + 64i64));
        *(_BYTE *)(*(_QWORD *)(v6 + 8) + 925i64) = 1;
        v10 = *(_QWORD *)(v6 + 8);
      LABEL_32:
        v23 = *(_QWORD *)(v10 + 120);
        if (v23 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
          *(_DWORD *)(v23 + 72) |= 0x200u;
        return 0i64;
      case 14:
        v75 = *(_QWORD *)(a1 + 32);
        if (!*(_BYTE *)(v75 + 233) || !*(_QWORD *)(v75 + 800))
          return 0i64;
        if (a4 < 5u) {
          v70 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
            v71 = 59i64;
            goto LABEL_194;
          }
          return 2148074278i64;
        }
        v76 = _byteswap_ushort(*(_WORD *)a3);
        v77 = a4 - 2;
        if (v77 < (unsigned __int64)v76 + 1) {
          v70 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
            v71 = 60i64;
            goto LABEL_194;
          }
          return 2148074278i64;
        }
        v78 = a3[v76 + 2];
        if (!(_BYTE)v78)
          goto LABEL_169;
        if ((unsigned __int16)(v77 - v76 - 1) < v78) {
          v70 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
            v71 = 61i64;
            goto LABEL_194;
          }
          return 2148074278i64;
        }
        v4 = &a3[v76 + 3];
      LABEL_169:
        result = CSsl3TlsServerContext::SelectSrtpParameters(
            (CSsl3TlsServerContext *)v75, (unsigned __int16 *const)a3 + 1, v76,
            v4, v78);
        if ((_DWORD)result)
          return result;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(
            *(_QWORD *)(*(_QWORD *)(v6 + 8) + 120i64), 1, 14);
        return 0i64;
      case 16:
        v46 = *(_QWORD *)(a1 + 8);
        if (!*(_QWORD *)(v46 + 784))
          return 0i64;
        if (a4 < 4u) {
          v70 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
            v71 = 57i64;
            goto LABEL_194;
          }
          return 2148074278i64;
        }
        v47 = _byteswap_ushort(*(_WORD *)a3);
        if (v47 != a4 - 2) {
          v70 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
            v71 = 58i64;
            goto LABEL_194;
          }
          return 2148074278i64;
        }
        v48 = *(_QWORD *)(a1 + 32);
        v49 = a3 + 2;
        v90 = v48;
        if (!*(_QWORD *)(v48 + 968)) {
          v87 = 0;
          v50 = 0;
          if (a3 != (unsigned __int8 *)-2i64) {
            if ((unsigned __int16)(v47 - 2) > 0xFFFBu) {
              v72 = WPP_GLOBAL_Control;
              if (WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control ||
                  (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0) {
                return (unsigned int)-2146893018;
              }
              v73 = 74i64;
            LABEL_147:
              WPP_SF_(*((_QWORD *)v72 + 2), v73,
                      &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
              return (unsigned int)-2146893018;
            }
            v51 = a3 + 2;
            v52 = (unsigned __int64)&v49[v47];
            if ((unsigned __int64)v49 < v52) {
              while (1) {
                v53 = *v51;
                if (!(_BYTE)v53)
                  break;
                v54 = &v51[v53];
                if ((unsigned __int64)v54 >= v52)
                  break;
                v51 = v54 + 1;
                if ((unsigned __int64)v51 >= v52)
                  goto LABEL_81;
              }
              v72 = WPP_GLOBAL_Control;
              if (WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control ||
                  (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0) {
                return (unsigned int)-2146893018;
              }
              v73 = 76i64;
              goto LABEL_147;
            }
          LABEL_81:
            v55 = *(_QWORD *)(v48 + 784);
            if (v55) {
              v56 = (unsigned __int8 *)(v55 + 6);
              v88 = 0;
              v57 = 0;
              v58 = v55 + 6 + *(unsigned __int16 *)(v55 + 4);
              v93 = v56;
              v91 = v58;
              while (1) {
                v59 = v56;
                if ((unsigned __int64)v56 < v58) {
                  do {
                    v60 = *v59;
                    v61 = v49;
                    if ((unsigned __int64)v49 < v52) {
                      while (1) {
                        v62 = *v61;
                        if ((_BYTE)v60 == (_BYTE)v62 &&
                            RtlCompareMemory(v59 + 1, v61 + 1, v60) == v60)
                          break;
                        v61 += v62 + 1;
                        if ((unsigned __int64)v61 >= v52)
                          goto LABEL_87;
                      }
                      v66 = v60 + 1;
                      if (*(_QWORD *)(v90 + 968)) {
                        memcpy_0(v89, v59, (unsigned __int16)(v60 + 1));
                        v89 += (unsigned __int16)(v60 + 1);
                      LABEL_87:
                        v50 = v87;
                        goto LABEL_88;
                      }
                      v50 = v66 + v87;
                      v87 += v66;
                    }
                  LABEL_88:
                    v59 += v60 + 1;
                  } while ((unsigned __int64)v59 < v91);
                  v6 = a1;
                  v48 = v90;
                  v57 = v88;
                }
                if (!v50)
                  break;
                if (!*(_QWORD *)(v48 + 968)) {
                  v63 = v50 + 6;
                  if (LsaTable)
                    v64 = (_WORD *)(*(__int64(__fastcall **)(_QWORD))(LsaTable +
                                                                      40))(v63);
                  else
                    v64 = LocalAlloc(0x40u, v63);
                  *(_QWORD *)(v48 + 968) = v64;
                  if (!v64)
                    return 14;
                  v64[2] = v50;
                  v89 = (char *)(*(_QWORD *)(v48 + 968) + 6i64);
                }
                v88 = ++v57;
                if (v57 >= 2) {
                  v46 = *(_QWORD *)(v6 + 8);
                  goto LABEL_98;
                }
                v58 = v91;
                v56 = v93;
              }
              if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
                  (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
                WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 65i64,
                        &WPP_095c39149c3f336b5b94efe855075ae2_Traceguids);
              }
              v69 = -2146892953;
              CSslContext::SetErrorAndFatalAlert(v48, 1208, -2146892953, 0x78u);
              *(_DWORD *)(v48 + 68) = 96;
              *(_WORD *)(v48 + 96) = 30722;
              return v69;
            }
          }
          return 87;
        }
      LABEL_98:
        v65 = *(_QWORD *)(v46 + 120);
        if (v65 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
          *(_DWORD *)(v65 + 72) |= 0x800u;
        break;
      case 23:
        if (CSslGlobals::m_fDisableServerExtendedMS ||
            (*(_DWORD *)(*(_QWORD *)(a1 + 32) + 64i64) & 0x51540) == 0) {
          v74 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 120i64);
          if (v74 &&
              CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
            *(_WORD *)(v74 + 66) |= 0x10u;
        } else {
          *(_QWORD *)(*(_QWORD *)(a1 + 8) + 136i64) |= 0x8000000ui64;
          v8 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 120i64);
          if (v8 &&
              CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
            *(_DWORD *)(v8 + 72) |= 0x1000u;
        }
        return 0i64;
      case 24:
        v79 = *(CSsl3TlsServerContext **)(a1 + 32);
        if (!*((_QWORD *)v79 + 102))
          return 0i64;
        if (a4 < 4u) {
          v70 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
            v71 = 62i64;
            goto LABEL_194;
          }
          return 2148074278i64;
        }
        if ((unsigned __int16)(a4 - 3) < a3[2]) {
          v70 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
            v71 = 63i64;
            goto LABEL_194;
          }
          return 2148074278i64;
        }
        result = CSsl3TlsServerContext::SelectTBParameters(v79, *a3, a3[1],
                                                           a3 + 3, a3[2]);
        if ((_DWORD)result)
          return result;
        CSchannelTelemetryContext::LogTlsExtensionTelemetry(
            *(_QWORD *)(*(_QWORD *)(v6 + 8) + 120i64), 1, 24);
        return 0i64;
      case 35:
        v36 = *(_QWORD *)(a1 + 8);
        v37 = *(_QWORD *)(v36 + 136);
        if ((v37 & 0x800) != 0) {
          if (a4) {
            *(_DWORD *)(v36 + 984) = a4;
            *(_QWORD *)(v36 + 976) = a3;
          } else {
            *(_QWORD *)(v36 + 136) = v37 | 0x400000;
          }
        }
        v38 = *(_QWORD *)(*(_QWORD *)(v6 + 8) + 120i64);
        if (v38 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized)
          *(_DWORD *)(v38 + 72) |= 0x2000u;
        return 0i64;
      default:
        goto LABEL_220;
      }
    }
    return 0i64;
  }
  v39 = *(_QWORD *)(a1 + 8);
  if (!*(_DWORD *)(v39 + 416) || *(_BYTE *)(v39 + 553)) {
    *(_BYTE *)(v39 + 553) = 1;
    v40 = *(_QWORD *)(a1 + 8);
    v41 = *(unsigned int *)(v40 + 416);
    v42 = (const void *)(v40 + 377);
    if (a4) {
      v43 = *a3;
      v44 = a4;
      if (v43 + 1 == a4) {
        if (a4 == 1) {
          v45 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
              (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0) {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 67i64,
                    &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
            v45 = WPP_GLOBAL_Control;
          }
          if ((_DWORD)v41) {
            if (v45 == (CCipherMill *)&WPP_GLOBAL_Control ||
                (*((_BYTE *)v45 + 28) & 1) == 0)
              goto LABEL_203;
            v82 = *((_QWORD *)v45 + 2);
            v83 = 68;
            v84 = v44;
          LABEL_202:
            WPP_SF_DD(v82, v83,
                      (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
                      v84, v41);
          LABEL_203:
            v40 = *(_QWORD *)(v6 + 8);
          LABEL_204:
            CSslContext::SetErrorAndFatalAlert(v40, 1207, -2146892986, 0x28u);
            v85 = *(_QWORD *)(v6 + 8);
            *(_DWORD *)(v85 + 68) = 96;
            *(_WORD *)(v85 + 96) = 10242;
            return 2148074310i64;
          }
        } else {
          if (v43 != (_DWORD)v41) {
            if (WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control ||
                (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0) {
              goto LABEL_204;
            }
            v82 = *((_QWORD *)WPP_GLOBAL_Control + 2);
            v83 = 69;
            v84 = v43;
            goto LABEL_202;
          }
          v86 = WPP_GLOBAL_Control;
          if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control) {
            if ((*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0) {
              WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 70i64,
                      &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
              v86 = WPP_GLOBAL_Control;
            }
            if (v86 != (CCipherMill *)&WPP_GLOBAL_Control &&
                (*((_DWORD *)v86 + 7) & 0x800) != 0) {
              WPP_SF_(*((_QWORD *)v86 + 2), 71i64,
                      &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
              v86 = WPP_GLOBAL_Control;
            }
          }
          if (memcmp_0(a3 + 1, v42, v41)) {
            if (v86 != (CCipherMill *)&WPP_GLOBAL_Control &&
                (*((_BYTE *)v86 + 28) & 1) != 0)
              WPP_SF_(*((_QWORD *)v86 + 2), 72i64,
                      &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
            goto LABEL_203;
          }
          CSchannelTelemetryContext::LogTlsExtensionTelemetry(
              *(_QWORD *)(*(_QWORD *)(v6 + 8) + 120i64), 1, 65281);
        }
        return 0i64;
      }
      if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
          (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x800) != 0) {
        WPP_SF_DD(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x42u,
                  (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
                  v43, a4);
      }
    } else {
      v70 = WPP_GLOBAL_Control;
      if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
          (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
        v71 = 65i64;
      LABEL_194:
        WPP_SF_(*((_QWORD *)v70 + 2), v71,
                &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
      }
    }
    return 2148074278i64;
  }
  if (WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control &&
      (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0) {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 64i64,
            &WPP_f49a95b901763c3505884ea2834cd757_Traceguids);
    v39 = *(_QWORD *)(v6 + 8);
  }
  CSslContext::SetErrorAndFatalAlert(v39, 1207, -2146892986, 0x28u);
  v81 = *(_QWORD *)(v6 + 8);
  result = 2148074310i64;
  *(_DWORD *)(v81 + 68) = 96;
  *(_WORD *)(v81 + 96) = 10242;
  return result;
}
// 180031905: variable 'v7' is possibly undefined
// 180000000: using guessed type __int16 _ImageBase;
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD,
// _QWORD); 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD,
// _QWORD, _QWORD, _QWORD); 18007C6F0: using guessed type void
// *CSsl3TlsServerContext::vftable; 180092620: using guessed type __int64
// LsaTable; 1800927AC: using guessed type bool
// CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized; 1800927B4:
// using guessed type int CSslGlobals::m_fDisableServerExtendedMS;