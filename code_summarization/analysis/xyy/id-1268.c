//----- (0000000180064440) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::ComputeClientHelloExtensionsSize(CTls13ClientHandshake *this)
{
  int v2; // edi
  __int64 result; // rax
  int v4; // eax
  __int64 v5; // rcx
  int v6; // eax
  __int16 v7; // cx
  int v8; // edx
  int v9; // eax
  int v10; // r8d
  __int16 v11; // cx
  int v12; // eax
  int v13; // edi
  CTls13ClientHandshake *v14; // rcx
  int v15; // eax
  int v16; // edi
  unsigned __int16 v17; // ax
  int v18; // edi
  CTls13ClientHandshake *v19; // rcx
  int v20; // eax
  unsigned int v21; // edi
  int v22; // eax

  v2 = 0;
  result = CTls13ClientHandshake::ComputeServerNameExtensionSize(this);
  if ( !(_DWORD)result )
  {
    v4 = *((unsigned __int16 *)this + 81);
    if ( (_WORD)v4 )
      v2 = v4 + 4;
    v5 = *(_QWORD *)(*((_QWORD *)this + 1) + 80i64);
    if ( !v5 )
      return 2148074244i64;
    if ( (*(_DWORD *)(v5 + 160) & 0x700) != 0 )
    {
      result = (**(__int64 (__fastcall ***)(CTls13ClientHandshake *))this)(this);
      if ( (_DWORD)result )
        return result;
      v6 = *((unsigned __int16 *)this + 76);
      if ( (_WORD)v6 )
        v2 += v6 + 4;
    }
    result = CTls13ClientHandshake::ComputeSupportedVersionsExtensionSize(this);
    if ( !(_DWORD)result )
    {
      v7 = *((_WORD *)this + 63);
      v8 = v2 + *((unsigned __int8 *)this + 54);
      if ( (unsigned __int16)(v7 - 1) > 0xFu )
        return 1359i64;
      v9 = (unsigned __int16)(2 * (v7 + 1));
      *((_WORD *)this + 62) = v9;
      v10 = v9 + v8;
      v11 = *(_WORD *)(*((_QWORD *)this + 1) + 920i64);
      if ( (unsigned __int16)(v11 - 1) > 0x7FFDu )
        return 1359i64;
      v12 = (unsigned __int16)(2 * (v11 + 1));
      *((_WORD *)this + 21) = v12;
      v13 = v10 + v12 + 16;
      result = CTls13ClientHandshake::ComputeALPNExtensionSize(this);
      if ( !(_DWORD)result )
      {
        v15 = *((unsigned __int16 *)this + 82);
        if ( (_WORD)v15 )
          v13 += v15 + 4;
        result = CTls13ClientHandshake::ComputeKeyShareExtensionSize(v14);
        if ( !(_DWORD)result )
        {
          v16 = *((unsigned __int16 *)this + 26) + 8 + v13;
          if ( !CSslGlobals::m_fDisableClientExtendedMS )
          {
            v16 += 4;
            *(_BYTE *)(*((_QWORD *)this + 1) + 1344i64) = 1;
          }
          v17 = *((_WORD *)this + 48);
          v18 = v16 + 5;
          if ( v17 )
          {
            if ( v17 > 0xFFFDu )
              return 87i64;
            *((_WORD *)this + 49) = v17 + 2;
          }
          if ( *((_WORD *)this + 49) )
            v18 += *((unsigned __int16 *)this + 49) + 4;
          result = CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::ComputeGenericExtensionsSize((__int64)this, 1);
          if ( !(_DWORD)result )
          {
            v20 = *((unsigned __int16 *)this + 61) + 6;
            *((_WORD *)this + 83) = 2;
            v21 = v20 + v18;
            result = CTls13ClientHandshake::ComputePskExtensionSize(v19);
            if ( !(_DWORD)result )
            {
              v22 = *((unsigned __int16 *)this + 78);
              if ( (_WORD)v22 )
                v21 += v22 + 4;
              if ( v21 <= 0xFFFF )
              {
                *((_WORD *)this + 20) = v21;
                return 0i64;
              }
              return 1359i64;
            }
          }
        }
      }
    }
  }
  return result;
}
// 180064564: variable 'v14' is possibly undefined
// 1800645E2: variable 'v19' is possibly undefined
// 180080FD8: using guessed type __int64 (__fastcall *_guard_xfg_dispatch_icall_fptr)(_QWORD, _QWORD, _QWORD);
// 1800927B8: using guessed type int CSslGlobals::m_fDisableClientExtendedMS;

