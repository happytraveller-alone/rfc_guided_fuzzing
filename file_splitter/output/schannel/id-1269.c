// File count: 1269
// Total lines: 86
----------------------------------------
__int64 __fastcall CTls13ClientHandshake::ComputeClientHelloSize(
        CTls13ClientHandshake *this,
        __int64 a2,
        int a3,
        __int16 a4,
        unsigned __int16 *a5)
{
  __int64 v5; // r11
  __int16 v7; // cx
  unsigned __int16 *v8; // r10
  __int16 v9; // si
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // cx
  __int64 result; // rax
  unsigned int v13; // ecx

  v5 = *((_QWORD *)this + 1);
  v7 = *(_WORD *)(v5 + 920);
  v8 = *(unsigned __int16 **)(v5 + 912);
  v9 = *(_WORD *)(v5 + 1836);
  *((_WORD *)this + 22) = 0;
  if ( !a2
    || (unsigned int)(a3 - 1) > 0x7FFE
    || (unsigned __int16)(a4 - 1) > 0xFu
    || (unsigned __int16)(v7 - 1) > 0x7FFDu
    || !v8
    || !a5 )
  {
    return 87i64;
  }
  *((_QWORD *)this + 3) = a2;
  *((_WORD *)this + 80) = a3;
  *((_WORD *)this + 63) = a4;
  v10 = *v8;
  if ( *(_DWORD *)(v5 + 68) == 100 )
  {
    v11 = 0;
    if ( v10 )
    {
      while ( v9 != v10 )
      {
        v10 = v8[++v11];
        if ( v11 >= v10 )
          goto LABEL_13;
      }
      *((_WORD *)this + 22) = v10;
    }
LABEL_13:
    v10 = *((_WORD *)this + 22);
  }
  else
  {
    *((_WORD *)this + 22) = v10;
  }
  if ( v10 )
  {
    result = CTls13ClientHandshake::ComputeClientHelloExtensionsSize(this);
    if ( !(_DWORD)result )
    {
      v13 = *(unsigned __int8 *)(*((_QWORD *)this + 1) + 1649i64)
          + 2 * *((unsigned __int16 *)this + 80)
          + *((unsigned __int16 *)this + 20)
          + 45;
      if ( v13 <= 0xFFFF )
      {
        *((_WORD *)this + 84) = v13;
        result = 0i64;
        *a5 = v13;
      }
      else
      {
        return 1359i64;
      }
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 28i64, WPP_922678f99ae534148d3bb024010f1556_Traceguids);
    return 2148074289i64;
  }
  return result;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180082C10: using guessed type _DWORD WPP_922678f99ae534148d3bb024010f1556_Traceguids[4];
