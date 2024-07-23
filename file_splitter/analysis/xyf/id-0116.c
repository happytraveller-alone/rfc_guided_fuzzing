//----- (00000001800098E4) ----------------------------------------------------
__int64 __fastcall CTlsExtClient::BuildServerNameString(CTlsExtClient *this, const unsigned __int16 *a2)
{
  DWORD LastError; // esi
  __int64 v4; // r12
  __int64 v5; // rax
  size_t v6; // r15
  unsigned __int64 v7; // rdi
  CTlsExtClient **v8; // rbx
  unsigned __int64 v9; // rcx
  __int64 v10; // rcx
  signed __int64 v11; // rcx
  void *v12; // rsp
  void *v13; // rsp
  _BYTE *v14; // r13
  const WCHAR *v15; // rdi
  __int16 v16; // cx
  CTlsExtClient **v17; // rdx
  const WCHAR *v18; // rax
  HLOCAL v19; // rax
  _DWORD *v21; // rax
  __int64 v22; // [rsp+0h] [rbp-40h] BYREF
  CTlsExtClient *v23; // [rsp+40h] [rbp+0h] BYREF
  __int64 v24[5]; // [rsp+48h] [rbp+8h] BYREF

  v23 = this;
  LastError = 0;
  if ( a2 && *a2 )
  {
    if ( IsIpAddress(a2) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_S(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x10u,
          (__int64)&WPP_f49a95b901763c3505884ea2834cd757_Traceguids,
          a2);
    }
    else
    {
      v4 = -1i64;
      v5 = -1i64;
      do
        ++v5;
      while ( a2[v5] );
      v6 = 2 * v5 + 2;
      if ( v6 <= 0x4000 )
      {
        v7 = 3 * v6;
        v8 = 0i64;
        if ( 3 * v6 )
        {
          if ( v7 <= g_ulMaxStackAllocSize )
          {
            v9 = v7 + g_ulAdditionalProbeSize + 8;
            if ( v9 >= v7 )
            {
              if ( (unsigned int)VerifyStackAvailable(v9) )
              {
                v10 = v7 + 23;
                if ( v7 + 23 <= v7 + 8 )
                  v10 = 0xFFFFFFFFFFFFFF0i64;
                v11 = v10 & 0xFFFFFFFFFFFFFFF0ui64;
                v12 = alloca(v11);
                v13 = alloca(v11);
                v8 = &v23;
                if ( &v22 != (__int64 *)-64i64 )
                {
                  LODWORD(v23) = 1801679955;
                  v8 = (CTlsExtClient **)v24;
                  if ( v24 )
                    goto LABEL_15;
                }
              }
            }
          }
        }
        if ( v7 + 8 >= v7 )
        {
          v21 = (_DWORD *)((__int64 (*)(void))g_pfnAllocate)();
          if ( !v21 )
            return 14;
          *v21 = 1885431112;
          v8 = (CTlsExtClient **)(v21 + 2);
        }
        if ( v8 )
        {
LABEL_15:
          v14 = (char *)v8 + v6;
          v15 = (const WCHAR *)v8;
          memcpy_0(v8, a2, v6);
          v16 = *(_WORD *)v8;
          v17 = v8;
          while ( v16 )
          {
            v17 = (CTlsExtClient **)((char *)v17 + 2);
            v18 = (const WCHAR *)v17;
            if ( v16 != 47 )
              v18 = v15;
            v16 = *(_WORD *)v17;
            v15 = v18;
          }
          if ( WideCharToMultiByte(0xFDE9u, 0, v15, -1, (LPSTR)v8 + v6, 2 * v6, 0i64, 0i64) )
          {
            if ( *v14 )
            {
              do
                ++v4;
              while ( v14[v4] );
              v19 = SPExternalAlloc((int)v4 + 1);
              *((_QWORD *)v23 + 5) = v19;
              if ( v19 )
                memcpy_0(v19, (char *)v8 + v6, (unsigned int)(v4 + 1));
              else
                LastError = 14;
            }
          }
          else
          {
            LastError = GetLastError();
          }
          if ( v8 )
          {
            if ( *((_DWORD *)v8 - 2) == 1885431112 )
              ((void (*)(void))g_pfnFree)();
          }
          return LastError;
        }
        return 14;
      }
    }
  }
  return 0i64;
}
// 1800920E0: using guessed type __int64 g_ulMaxStackAllocSize;
// 1800920E8: using guessed type __int64 g_ulAdditionalProbeSize;
// 1800920F0: using guessed type __int64 g_pfnAllocate;
// 1800920F8: using guessed type __int64 g_pfnFree;

