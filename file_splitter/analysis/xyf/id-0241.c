//----- (0000000180014090) ----------------------------------------------------
__int64 __fastcall CSslContext::PopulateSerialContextState(CSslContext *this, struct _SSL_PACKED_CONTEXT *a2)
{
  int v4; // r14d
  __int64 v5; // rax
  int v6; // ecx
  int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // ebp
  CCipherMill *v10; // rcx
  int v11; // edx
  __int64 v12; // rax
  int v13; // ecx
  __int64 result; // rax
  unsigned int v15; // esi
  __int64 v16; // rdx
  unsigned int v17; // eax
  int *v18; // rax
  unsigned int v19; // r9d

  *(_DWORD *)a2 = *((_DWORD *)this + 17);
  v4 = 0;
  *((_QWORD *)a2 + 1) = *((_QWORD *)this + 17);
  *((_DWORD *)a2 + 4) = *((_DWORD *)this + 16);
  *((_BYTE *)a2 + 44) = (*(__int64 (__fastcall **)(CSslContext *))(*(_QWORD *)this + 360i64))(this);
  *((_QWORD *)a2 + 10) = *((_QWORD *)this + 16);
  if ( (*((_BYTE *)this + 32) & 8) != 0 && (v5 = *((_QWORD *)this + 1)) != 0 )
    v6 = *(_DWORD *)(v5 + 28);
  else
    v6 = 0;
  *((_DWORD *)a2 + 5) = v6;
  *((_DWORD *)a2 + 7) = *(_DWORD *)(*((_QWORD *)this + 11) + 8i64);
  *((_DWORD *)a2 + 6) = *((_DWORD *)this + 4);
  if ( (*((_BYTE *)this + 32) & 8) != 0 )
    v7 = *((_DWORD *)this + 11);
  else
    v7 = 0;
  *((_DWORD *)a2 + 8) = v7;
  *((_DWORD *)a2 + 38) = *((_DWORD *)this + 15);
  v8 = *((_DWORD *)this + 11);
  v9 = *((_DWORD *)this + 13);
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_D(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      11i64,
      &WPP_c955f13c15ab3d9e41a0e2d56db0bfe4_Traceguids,
      *((unsigned int *)this + 16));
    v10 = WPP_GLOBAL_Control;
  }
  if ( CSslGlobals::m_bSendAuxRecord != 2
    && (CSslGlobals::m_bSendAuxRecord == 1 || (*(_DWORD *)(*((_QWORD *)this + 10) + 156i64) & 0x400) != 0) )
  {
    v11 = *((_DWORD *)this + 16);
    if ( (unsigned int)(v11 - 3) <= 0x2FE && ((v11 - 65277) & 0xFFFFFFFD) != 0 && (*((_BYTE *)this + 56) & 1) != 0 )
    {
      v19 = *((_DWORD *)this + 12);
      if ( v9 )
        v19 += v9 - v19 % v9;
      v8 = v19 + *((_DWORD *)this + 11) + *((_DWORD *)this + 15) - 1;
    }
  }
  if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v10 + 2), 12i64, &WPP_c955f13c15ab3d9e41a0e2d56db0bfe4_Traceguids, v8);
  *((_DWORD *)a2 + 9) = v8;
  v12 = (*(__int64 (__fastcall **)(CSslContext *))(*(_QWORD *)this + 248i64))(this);
  if ( v12 )
    v13 = *(_DWORD *)(v12 + 428);
  else
    v13 = 0;
  *((_DWORD *)a2 + 10) = v13;
  result = (*(__int64 (__fastcall **)(CSslContext *, char *, char *))(*(_QWORD *)this + 64i64))(
             this,
             (char *)a2 + 144,
             (char *)a2 + 148);
  v15 = result;
  if ( (int)result >= 0 )
  {
    *((_QWORD *)a2 + 6) = *((_QWORD *)this + 22);
    *((_QWORD *)a2 + 7) = *((_QWORD *)this + 23);
    *((_DWORD *)a2 + 22) = 32;
    v16 = *((_QWORD *)this + 11);
    v17 = *(unsigned __int16 *)(v16 + 238);
    if ( v17 <= 0x20 )
    {
      *((_DWORD *)a2 + 22) = v17;
      memcpy_0((char *)a2 + 92, (const void *)(v16 + 240), *(unsigned __int16 *)(v16 + 238));
    }
    *((_DWORD *)a2 + 44) = *((_DWORD *)this + 48);
    *((_QWORD *)a2 + 20) = *((_QWORD *)this + 25);
    *((_QWORD *)a2 + 21) = *((_QWORD *)this + 26);
    *((_WORD *)a2 + 90) = *((_WORD *)this + 108);
    *((_WORD *)a2 + 91) = *((_WORD *)this + 109);
    v18 = (int *)*((_QWORD *)this + 28);
    if ( v18 )
      v4 = *v18;
    *((_DWORD *)a2 + 46) = v4;
    *((_DWORD *)a2 + 47) = CSslGlobals::m_dwMaxEncryptedRecords;
    *((_BYTE *)a2 + 192) = (*(__int64 (__fastcall **)(CSslContext *))(*(_QWORD *)this + 176i64))(this);
    return v15;
  }
  return result;
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 1800927BC: using guessed type unsigned int CSslGlobals::m_bSendAuxRecord;

