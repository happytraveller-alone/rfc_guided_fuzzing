//----- (00000001800441C4) ----------------------------------------------------
__int64 __fastcall SspNtStatusToSecStatus(NTSTATUS a1)
{
  unsigned int v1; // edx
  bool v2; // zf
  signed int v4; // eax

  v1 = a1;
  if ( (a1 & 0x1FFF0000) == 589824 )
    return v1;
  if ( a1 > -1073741428 )
  {
    if ( a1 <= -1073740965 )
    {
      if ( a1 == -1073740965 )
        return (unsigned int)-2146892986;
      if ( a1 > -1073741261 )
      {
        switch ( a1 )
        {
          case -1073741260:
            return (unsigned int)-2146893044;
          case -1073741252:
            return (unsigned int)-2146893039;
          case -1073741063:
            return (unsigned int)-2146893044;
          case -1073741058:
            return (unsigned int)-2146892993;
        }
        v2 = a1 == -1073741024;
      }
      else
      {
        if ( a1 == -1073741261 || a1 == -1073741427 || a1 == -1073741424 || a1 == -1073741422 )
          return (unsigned int)-2146893039;
        if ( a1 == -1073741421 )
          return (unsigned int)-2146893044;
        if ( a1 <= -1073741417 )
          goto LABEL_83;
        if ( a1 <= -1073741413 )
          return v1;
        v2 = a1 == -1073741276;
      }
LABEL_56:
      if ( !v2 )
        goto LABEL_83;
      return (unsigned int)-2146893044;
    }
    if ( a1 > -1073740789 )
    {
      if ( a1 == -1073740781 )
        return v1;
      if ( a1 != -1073740776 )
      {
        switch ( a1 )
        {
          case -1073740755:
            return (unsigned int)-2146892959;
          case -1073740753:
            return (unsigned int)-2146892958;
          case 0:
            return 0;
        }
        goto LABEL_83;
      }
    }
    else
    {
      if ( a1 == -1073740789 )
        return (unsigned int)-2146892969;
      if ( a1 < -1073740928 )
        goto LABEL_83;
      if ( a1 > -1073740927 )
      {
        if ( a1 <= -1073740926 )
          goto LABEL_83;
        if ( a1 > -1073740921 )
        {
          if ( a1 == -1073740920 )
            return (unsigned int)-2146892976;
          if ( a1 != -1073740916 && a1 != -1073740913 )
          {
            v2 = a1 == -1073740792;
            goto LABEL_56;
          }
        }
      }
    }
    return (unsigned int)-2146893044;
  }
  if ( a1 == -1073741428 )
    return v1;
  if ( a1 > -1073741724 )
  {
    if ( a1 > -1073741601 )
    {
      if ( a1 == -1073741595 )
        return (unsigned int)-2146893052;
      if ( a1 != -1073741562 )
      {
        if ( a1 == -1073741517 )
          return (unsigned int)-2146893020;
        if ( a1 == -1073741477 )
          return (unsigned int)-2146893044;
        if ( a1 != -1073741429 )
          goto LABEL_83;
        return (unsigned int)-2146893053;
      }
    }
    else
    {
      if ( a1 == -1073741601 )
        return (unsigned int)-2146893039;
      if ( a1 == -1073741718 )
        return (unsigned int)-2146893044;
      if ( a1 != -1073741717 )
      {
        if ( a1 <= -1073741717 )
          goto LABEL_83;
        if ( a1 <= -1073741710 )
          return (unsigned int)-2146893044;
        if ( a1 != -1073741670 )
        {
          if ( a1 == -1073741637 )
            return (unsigned int)-2146893054;
          if ( a1 != -1073741634 )
            goto LABEL_83;
          return (unsigned int)-2146893039;
        }
        return (unsigned int)-2146893056;
      }
    }
    return (unsigned int)-2146893048;
  }
  if ( a1 == -1073741724 )
    return (unsigned int)-2146893044;
  if ( a1 > -1073741811 )
  {
    if ( a1 != -1073741801 )
    {
      if ( a1 == -1073741789 )
        return (unsigned int)-2146893023;
      if ( a1 != -1073741772 )
      {
        if ( a1 != -1073741730 )
        {
          if ( a1 == -1073741729 )
            return (unsigned int)-2146893043;
          if ( a1 == -1073741727 )
            return (unsigned int)-2146893050;
          goto LABEL_83;
        }
        return (unsigned int)-2146893039;
      }
      return (unsigned int)-2146893053;
    }
    return (unsigned int)-2146893056;
  }
  if ( a1 == -1073741811 || a1 == -2147483635 )
    return (unsigned int)-2146893048;
  if ( a1 == -2146885616 )
    return (unsigned int)-2146893044;
  if ( a1 <= -2146885615 )
    goto LABEL_83;
  if ( a1 <= -2146885613 || a1 == -2146869247 || a1 == -2146762480 )
    return (unsigned int)-2146893044;
  if ( a1 == -1073741816 )
    return (unsigned int)-2146893055;
LABEL_83:
  v4 = RtlNtStatusToDosErrorNoTeb(a1);
  v1 = v4;
  if ( v4 >= 0 || (v4 & 0x1FFF0000) != 589824 )
    return (unsigned int)-2146893052;
  return v1;
}
