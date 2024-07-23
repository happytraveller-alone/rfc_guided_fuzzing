// File count: 7
// Total lines: 93
-------------------------------------------
__int64 __fastcall I_MapWinTrustErrorAndAlert(int a1, int a2, __int16 a3, char *a4)
{
  char v4; // bl
  CCipherMill *v7; // rcx
  __int64 v8; // rdx

  v4 = 0;
  if ( a1 == -2146885614 )
  {
    if ( (a3 & 0x800) == 0 )
      goto LABEL_32;
    v7 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) == 0 )
      goto LABEL_12;
    v8 = 17i64;
LABEL_26:
    WPP_SF_(*((_QWORD *)v7 + 2), v8, &WPP_145b996ecad4340088f3534b93eceddb_Traceguids);
    goto LABEL_12;
  }
  if ( a1 == -2146885613 )
  {
    if ( (a3 & 0x1000) == 0 )
      goto LABEL_32;
    v7 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) == 0 )
      goto LABEL_12;
    v8 = 18i64;
    goto LABEL_26;
  }
  if ( (a1 & 0x1FFF0000) != 589824 )
  {
    if ( a1 < -2146762495 )
    {
LABEL_35:
      a1 = a2;
      if ( !a2 )
        a1 = -2146893017;
      goto LABEL_37;
    }
    if ( a1 <= -2146762494 )
    {
      a1 = -2146893016;
      v4 = 45;
      goto LABEL_13;
    }
    if ( a1 == -2146762487 )
    {
LABEL_16:
      a1 = -2146893019;
      v4 = 48;
      goto LABEL_13;
    }
    if ( a1 != -2146762484 )
    {
      switch ( a1 )
      {
        case -2146762481:
          a1 = -2146893022;
          break;
        case -2146762480:
          a1 = -2146892983;
          break;
        case -2146762478:
          goto LABEL_16;
        case 0:
LABEL_12:
          a1 = 0;
          goto LABEL_13;
        default:
          goto LABEL_35;
      }
LABEL_32:
      v4 = 43;
      goto LABEL_13;
    }
    a1 = -2146885616;
LABEL_34:
    v4 = 44;
    goto LABEL_13;
  }
  if ( a1 == -2146885616 )
    goto LABEL_34;
  if ( (unsigned int)(a1 + 2146885614) <= 1 )
    goto LABEL_32;
LABEL_37:
  v4 = 46;
LABEL_13:
  if ( a4 )
    *a4 = v4;
  return (unsigned int)a1;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
