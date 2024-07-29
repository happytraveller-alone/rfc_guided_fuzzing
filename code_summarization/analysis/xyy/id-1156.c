//----- (000000018005D0A0) ----------------------------------------------------
__int64 __fastcall CSessionCacheServerItem::Deserialize(
        CSessionCacheServerItem *this,
        CCredentialGroup **a2,
        unsigned __int8 *a3,
        unsigned int a4)
{
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rdx
  unsigned int v11; // r9d
  unsigned int Credential; // ebx
  __int64 v13; // rcx
  int v14; // r8d
  unsigned __int8 *v15; // rdx
  CCredentialGroup *v16; // rcx
  unsigned __int64 v17; // [rsp+48h] [rbp+10h] BYREF

  v17 = 0i64;
  if ( !a2 || !a3 || a4 < 0x28 || *(_DWORD *)a3 )
    return 87i64;
  GetSystemTimeAsFileTime((LPFILETIME)&v17);
  v8 = v17 / 0x2710;
  v9 = *((_QWORD *)a3 + 3) / 0x2710ui64;
  v17 = v8;
  if ( v9 > CSslGlobals::m_dwSessionTicketTimeSkew + v8 )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_3f0b3b553bfa392717596024a0f8b3a2_Traceguids);
    return 1398i64;
  }
  if ( v8 <= CSslGlobals::m_dwSessionTicketTimeSkew + v9 + CSslGlobals::m_dwSessionTicketLifespan )
  {
    RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 72), 1u);
    if ( *((_DWORD *)a3 + 1) == 32 )
    {
      v11 = *((_DWORD *)a3 + 2);
      if ( v11 + 32 <= a4 )
      {
        Credential = CSessionCacheItem::Deserialize(this, (struct CSslContext *)a2, a3 + 32, v11);
        if ( Credential )
        {
LABEL_28:
          RtlReleaseResource((PRTL_RESOURCE)((char *)this + 72));
          return Credential;
        }
        v13 = *((unsigned int *)a3 + 3);
        if ( (_DWORD)v13 == *((_DWORD *)a3 + 2) + *((_DWORD *)a3 + 1) )
        {
          v14 = *((_DWORD *)a3 + 4);
          if ( v14 + (int)v13 <= a4 )
          {
            v15 = &a3[v13];
            if ( *((_QWORD *)this + 42) )
            {
              Credential = 1359;
              goto LABEL_28;
            }
            if ( !v14 )
            {
              Credential = 0;
              goto LABEL_28;
            }
            if ( v15 )
            {
              v16 = a2[10];
              if ( v16 )
              {
                Credential = CCredentialGroup::FindCredential(v16, v15, v14, (struct CSslCredential **)this + 42);
                goto LABEL_28;
              }
            }
          }
        }
      }
    }
    Credential = 87;
    goto LABEL_28;
  }
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_3f0b3b553bfa392717596024a0f8b3a2_Traceguids);
  return 1460i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

