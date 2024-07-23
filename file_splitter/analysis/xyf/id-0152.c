//----- (000000018000D31C) ----------------------------------------------------
__int64 __fastcall ConvertSchannelProtocolToSsl(int a1)
{
  __int64 result; // rax

  if ( (a1 & 0x3FFC) != 0 && (a1 & 0xF0000) != 0 )
    return 0i64;
  if ( (a1 & 0xC0000) != 0 )
    return 65277i64;
  if ( (a1 & 0x30000) != 0 )
    return 65279i64;
  if ( (a1 & 0x3000) != 0 )
    return 772i64;
  if ( (a1 & 0xC00) != 0 )
    return 771i64;
  result = 768i64;
  if ( (a1 & 0x300) != 0 )
    return 770i64;
  if ( (a1 & 0xC0) != 0 )
    return 769i64;
  if ( (a1 & 0x30) == 0 )
  {
    if ( (a1 & 0xC) != 0 )
      return 2i64;
    return 0i64;
  }
  return result;
}

