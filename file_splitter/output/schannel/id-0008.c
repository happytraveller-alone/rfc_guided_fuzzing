//----- (000000018000172C) ----------------------------------------------------
__int64 __fastcall TlsParseAlertMessage(unsigned __int8 *a1, int a2, unsigned __int8 *a3, unsigned __int8 *a4)
{
  unsigned int v4; // ebx
  CCipherMill *v8; // rcx
  unsigned int v9; // eax
  int v10; // ecx
  __int64 v12; // rdx
  __int64 v13; // rdx
  __int64 v14; // rdx

  v4 = 0;
  if ( a4 )
    *a4 = 0;
  if ( a2 != 2 || (unsigned __int8)(*a1 - 1) > 1u )
    return 2148074248i64;
  if ( a3 )
  {
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control )
    {
      if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      {
        WPP_SF_L(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x47u,
          (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
          *a1);
        v8 = WPP_GLOBAL_Control;
      }
      if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 1) != 0 )
      {
        WPP_SF_L(*((_QWORD *)v8 + 2), 0x48u, (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids, a1[1]);
        v8 = WPP_GLOBAL_Control;
      }
    }
    v9 = a1[1];
    if ( *a1 == 1 )
    {
      if ( (_BYTE)v9 )
      {
        if ( (_BYTE)v9 == 41 )
        {
          if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
            WPP_SF_(*((_QWORD *)v8 + 2), 73i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
          if ( a4 )
            *a4 = 1;
        }
        else if ( (_BYTE)v9 == 100 )
        {
          if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
            WPP_SF_(*((_QWORD *)v8 + 2), 75i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
          v4 = 590688;
        }
        else if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
        {
          WPP_SF_(*((_QWORD *)v8 + 2), 76i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
        }
      }
      else
      {
        if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
          WPP_SF_(*((_QWORD *)v8 + 2), 74i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
        v4 = 590615;
      }
      v10 = *a3;
      *a3 = v10 + 1;
      if ( (unsigned __int8)(v10 + 1) > 5u )
      {
        if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          *a3 = v10;
          WPP_SF_d(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            0x4Du,
            (__int64)&WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids,
            v10);
        }
        return 590615;
      }
      return v4;
    }
    if ( v9 > 0x2F )
    {
      if ( v9 > 0x46 )
      {
        switch ( v9 )
        {
          case 'G':
            if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v8 + 2), 94i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146893007;
          case 'P':
            if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v8 + 2), 95i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146893052;
          case 'n':
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893018;
            v12 = 96i64;
            goto LABEL_51;
          case 's':
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893018;
            v12 = 97i64;
            goto LABEL_51;
          case 'x':
            if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v8 + 2), 98i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146892953;
        }
      }
      else
      {
        switch ( v9 )
        {
          case 'F':
            if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v8 + 2), 93i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146893054;
          case '0':
            if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v8 + 2), 88i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146893019;
          case '1':
            if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v8 + 2), 89i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146893044;
          case '2':
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893018;
            v12 = 90i64;
            goto LABEL_51;
          case '3':
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893008;
            v13 = 91i64;
            goto LABEL_56;
          case '<':
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893018;
            v12 = 92i64;
            goto LABEL_51;
        }
      }
    }
    else
    {
      if ( v9 == 47 )
      {
        if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
          return (unsigned int)-2146893018;
        v12 = 87i64;
        goto LABEL_51;
      }
      if ( v9 <= 0x28 )
      {
        switch ( v9 )
        {
          case 0x28u:
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893018;
            v12 = 81i64;
            break;
          case 0xAu:
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893018;
            v12 = 78i64;
            break;
          case 0x14u:
            if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
              WPP_SF_(*((_QWORD *)v8 + 2), 79i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146893041;
          case 0x15u:
            if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
              return (unsigned int)-2146893008;
            v13 = 80i64;
LABEL_56:
            WPP_SF_(*((_QWORD *)v8 + 2), v13, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
            return (unsigned int)-2146893008;
          case 0x16u:
            return (unsigned int)-2146893018;
          case 0x1Eu:
            return (unsigned int)-2146893041;
          default:
            goto LABEL_48;
        }
LABEL_51:
        WPP_SF_(*((_QWORD *)v8 + 2), v12, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
        return (unsigned int)-2146893018;
      }
      switch ( v9 )
      {
        case '*':
          if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
            return (unsigned int)-2146893017;
          v14 = 82i64;
          goto LABEL_90;
        case '+':
          if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
            return (unsigned int)-2146893017;
          v14 = 83i64;
          goto LABEL_90;
        case ',':
          if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
            WPP_SF_(*((_QWORD *)v8 + 2), 84i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
          return (unsigned int)-2146885616;
        case '-':
          if ( v8 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v8 + 28) & 4) != 0 )
            WPP_SF_(*((_QWORD *)v8 + 2), 85i64, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
          return (unsigned int)-2146893016;
        case '.':
          if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
            return (unsigned int)-2146893017;
          v14 = 86i64;
LABEL_90:
          WPP_SF_(*((_QWORD *)v8 + 2), v14, &WPP_bf20500307af3a1a22cf0d610b67b788_Traceguids);
          return (unsigned int)-2146893017;
      }
    }
LABEL_48:
    if ( v8 == (CCipherMill *)&WPP_GLOBAL_Control || (*((_BYTE *)v8 + 28) & 4) == 0 )
      return (unsigned int)-2146893018;
    v12 = 99i64;
    goto LABEL_51;
  }
  return 2148074333i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);

