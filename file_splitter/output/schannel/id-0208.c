//----- (0000000180011F40) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::GenerateResponseCommon(CSsl3TlsContext *this, struct SPBuffer *a2)
{
  __int64 result; // rax
  __int64 v5; // r8
  int v6; // ecx
  unsigned int v7; // edi
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  CCipherMill *v12; // rcx
  __int64 v13; // rdx

  if ( !*((_QWORD *)this + 11) )
    return 1359i64;
  result = (*(__int64 (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 472i64))(this);
  if ( !(_DWORD)result )
  {
    v6 = *((_DWORD *)this + 17);
    if ( v6 >= 80 && v6 < 96 )
      goto LABEL_5;
    v8 = v6 - 2;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( !v9 )
      {
        v12 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
          goto LABEL_27;
        v13 = 47i64;
        goto LABEL_26;
      }
      v10 = v9 - 2;
      if ( v10 )
      {
        v11 = v10 - 74;
        if ( v11 )
        {
          if ( v11 != 17 )
          {
LABEL_5:
            v7 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, struct SPBuffer *))(*(_QWORD *)this + 424i64))(this, a2);
LABEL_6:
            if ( !v7 )
              return v7;
            if ( (v7 & 0x80000000) == 0 )
            {
              if ( (v7 & 0x1FFF0000) == 589824 )
                return v7;
            }
            else if ( v7 == -2146893032 || v7 == -2146893023 || v7 == -2146892950 || v7 == -2146892949 )
            {
              return v7;
            }
            v12 = WPP_GLOBAL_Control;
LABEL_42:
            if ( v12 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v12 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v12 + 2), 49i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
            *((_DWORD *)this + 17) = 96;
            return v7;
          }
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 45i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
          }
          v7 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, struct SPBuffer *, _QWORD, _QWORD))(*(_QWORD *)this + 392i64))(
                 this,
                 a2,
                 *((unsigned __int8 *)this + 96),
                 *((unsigned __int8 *)this + 97));
          *((_WORD *)this + 48) = 0;
LABEL_19:
          *((_DWORD *)this + 17) = 3;
          goto LABEL_6;
        }
        v12 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
        {
LABEL_27:
          v7 = -2146893033;
          goto LABEL_42;
        }
        v13 = 48i64;
LABEL_26:
        WPP_SF_(*((_QWORD *)v12 + 2), v13, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
        v12 = WPP_GLOBAL_Control;
        goto LABEL_27;
      }
    }
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 46i64, &WPP_906ebfdb0b6e356d5c7c2dbe304d0682_Traceguids);
    LOBYTE(v5) = 1;
    v7 = (*(__int64 (__fastcall **)(CSsl3TlsContext *, struct SPBuffer *, __int64, _QWORD))(*(_QWORD *)this + 392i64))(
           this,
           a2,
           v5,
           0i64);
    if ( (*((_DWORD *)this + 16) & 0x3000) != 0 && *((_DWORD *)this + 17) == 2 )
    {
      *((_DWORD *)this + 17) = 79;
      goto LABEL_6;
    }
    goto LABEL_19;
  }
  return result;
}
// 18003BDFC: variable 'v5' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

