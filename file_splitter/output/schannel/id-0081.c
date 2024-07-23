// File count: 81
// Total lines: 91
------------------------------------------
__int64 __fastcall CSsl3TlsContext::DigestFinish(CSsl3TlsContext *this, unsigned __int8 *Src, int a3)
{
  int v3; // r14d
  unsigned int v4; // esi
  int v7; // r14d
  __int64 v8; // rdi
  __int64 *v9; // rax
  unsigned int v10; // r15d
  CCipherMill *v11; // rdi
  char Buf1[40]; // [rsp+30h] [rbp-68h] BYREF

  v3 = *((_DWORD *)this + 16);
  v4 = 36;
  if ( (v3 & 0xF3FC0) != 0 )
    v4 = 12;
  if ( a3 == v4 )
  {
    v7 = v3 & 0xA2AA0;
    v8 = 0i64;
    RtlAcquireResourceShared((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64), 1u);
    v9 = (__int64 *)*((_QWORD *)this + 1);
    if ( v9 )
      v8 = *v9;
    v10 = SslComputeFinishedHash(
            v8,
            *(_QWORD *)(*((_QWORD *)this + 11) + 16i64),
            *((_QWORD *)this + 74),
            Buf1,
            v4,
            (unsigned int)(v7 != 0) + 1);
    RtlReleaseResource((PRTL_RESOURCE)(*((_QWORD *)this + 11) + 72i64));
    if ( v10 )
    {
      CSslContext::SetErrorAndFatalAlert((__int64)this, 902, v10, 0x33u);
      return v10;
    }
    else
    {
      v11 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 61i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        v11 = WPP_GLOBAL_Control;
      }
      if ( !memcmp_0(Buf1, Src, v4) )
      {
        if ( v7 )
        {
          if ( v11 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v11 + 7) & 0x800) != 0 )
            WPP_SF_(*((_QWORD *)v11 + 2), 63i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          memcpy_0((char *)this + 420, Src, v4);
          *((_DWORD *)this + 114) = v4;
        }
        else
        {
          if ( v11 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)v11 + 7) & 0x800) != 0 )
            WPP_SF_(*((_QWORD *)v11 + 2), 64i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          memcpy_0((char *)this + 377, Src, v4);
          *((_DWORD *)this + 104) = v4;
        }
        if ( !*((_BYTE *)this + 340) )
        {
          memcpy_0((char *)this + 341, Buf1, v4);
          *((_BYTE *)this + 340) = 1;
          CSsl3TlsContext::SetTokenBindingEKM(this);
        }
        if ( *((_BYTE *)this + 233) )
        {
          if ( (*((_DWORD *)this + 16) & 0xA0000) != 0 )
            CSsl3TlsContext::FreeSavedWriteCipherState(this);
        }
        return 0i64;
      }
      else
      {
        if ( v11 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v11 + 28) & 1) != 0 )
          WPP_SF_(*((_QWORD *)v11 + 2), 62i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        CSslContext::SetErrorAndFatalAlert((__int64)this, 900, -2146893048, 0x33u);
        return 2148074248i64;
      }
    }
  }
  else
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 903, -2146893048, 0x32u);
    return 2148074248i64;
  }
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180098538: using guessed type __int64 __fastcall SslComputeFinishedHash(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD);
