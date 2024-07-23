//----- (0000000180011740) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::ProcessAppModeInfo(CSsl3TlsContext *this)
{
  unsigned int v2; // ebx
  int v3; // esi
  unsigned int v4; // r9d
  CCipherMill *v6; // rcx
  unsigned __int16 v7; // dx
  unsigned __int64 v8; // rcx
  __int64 v9; // r9
  __int64 v10; // r10
  __int64 v11; // rax
  int v12; // eax
  HLOCAL v13; // rax
  void *Src[2]; // [rsp+30h] [rbp-30h] BYREF
  char v15[32]; // [rsp+40h] [rbp-20h] BYREF
  int v16; // [rsp+80h] [rbp+20h] BYREF
  __int64 v17; // [rsp+88h] [rbp+28h] BYREF

  v17 = 0i64;
  v16 = 0;
  v2 = -1073741595;
  *(_OWORD *)Src = 0i64;
  if ( LsaTable )
  {
    if ( (*(unsigned __int8 (__fastcall **)(char *))(LsaTable + 192))(v15) )
    {
      v3 = v15[8] & 0x40;
      v2 = (*(__int64 (__fastcall **)(int *, _QWORD, __int64 *, void **, _QWORD))(LsaTable + 488))(
             &v16,
             0i64,
             &v17,
             Src,
             0i64);
      if ( v2 )
        goto LABEL_12;
      v4 = (unsigned int)Src[0];
      if ( (!Src[1] || !LODWORD(Src[0])) && v16 != 4 )
        goto LABEL_12;
      switch ( v16 )
      {
        case 1:
          v12 = *((_DWORD *)this + 16) & 0x2000;
          *((_DWORD *)this + 236) = Src[0];
          *((_DWORD *)this + 18) = v12 != 0 ? 101 : 91;
          v13 = SPExternalAlloc(v4);
          *((_QWORD *)this + 117) = v13;
          if ( v13 )
          {
            memcpy_0(v13, Src[1], LODWORD(Src[0]));
            *((_BYTE *)this + 1032) = 1;
            goto LABEL_10;
          }
          break;
        case 4:
          if ( !this )
            v2 = 1359;
          if ( Src[1] )
          {
            if ( LODWORD(Src[0]) == (v3 != 0 ? 28 : 36) )
            {
              v8 = -(__int64)(v3 != 0) & 0xFFFFFFFFFFFFFFFCui64;
              if ( v3 )
              {
                v9 = *((unsigned int *)Src[1] + 5);
                v10 = *(unsigned int *)((char *)Src[1] + v8 + 28);
              }
              else
              {
                v9 = *(_QWORD *)((char *)Src[1] + 20);
                v10 = *(_QWORD *)((char *)Src[1] + v8 + 28);
              }
              v11 = *((_QWORD *)this + 116);
              if ( !v11 )
                v2 = 1359;
              *(_QWORD *)(v11 + 104) = v9;
              *(_QWORD *)(v11 + 112) = v10;
              *((_BYTE *)this + 923) = 0;
              CSsl3TlsClientContext::SetDefCredSearched((__int64)this, 0);
            }
            else
            {
              v2 = 1359;
            }
          }
          else
          {
            CSsl3TlsClientContext::SetActiveClientCred(this, 0i64, 0);
          }
          goto LABEL_10;
        case 7:
          v2 = ParseKeyBuffer(this, (unsigned int)v17, (unsigned __int8 *)Src[1], (unsigned int)Src[0]);
          if ( !v2 )
          {
LABEL_10:
            *((_DWORD *)this + 17) = *((_DWORD *)this + 18);
            *((_DWORD *)this + 18) = 77;
            CleanupAppModeInfo(0i64);
            return v2;
          }
LABEL_12:
          v2 = -1073741595;
          goto LABEL_10;
        case 9:
          *((_BYTE *)this + 472) = *(_BYTE *)Src[1];
          goto LABEL_10;
      }
      v2 = 1359;
      goto LABEL_10;
    }
    v6 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
    {
      v7 = 99;
      goto LABEL_21;
    }
  }
  else
  {
    v6 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 5) != 0 )
    {
      v7 = 98;
LABEL_21:
      WPP_SF_DD(
        *((_QWORD *)v6 + 2),
        v7,
        (__int64)&WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids,
        -1073741595,
        -1073741595);
    }
  }
  return v2;
}
// 180092620: using guessed type __int64 LsaTable;

