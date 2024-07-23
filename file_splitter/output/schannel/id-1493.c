// File count: 1493
// Total lines: 68
----------------------------------------
__int64 __fastcall CTls13ExtClient::ParseKeyShareExtension(
        CTls13ExtClient *this,
        unsigned __int8 *a2,
        unsigned __int16 a3)
{
  unsigned __int16 v4; // dx
  __int64 v6; // rcx
  unsigned __int8 *v7; // r9
  unsigned __int16 v8; // r8
  __int16 v9; // r10
  __int16 v10; // r8
  __int16 v11; // ax
  unsigned __int8 *v12; // r9
  __int16 v13; // r10
  __int64 v14; // r10
  __int16 v15; // ax

  if ( a3 < 2u )
    goto LABEL_15;
  v4 = _byteswap_ushort(*(_WORD *)a2);
  if ( a3 != 2 )
  {
    v7 = a2 + 2;
    v8 = a3 - 2;
    if ( v8 >= 2u )
    {
      v9 = *v7;
      v10 = v8 - 2;
      v11 = v7[1];
      v12 = v7 + 2;
      v13 = v11 | (v9 << 8);
      if ( v13 )
      {
        if ( v13 == v10 )
        {
          v14 = *((_QWORD *)this + 8);
          v15 = *(_WORD *)(v14 + 1836);
          if ( !v15 )
          {
            v6 = *((_QWORD *)this + 1);
            if ( **(_WORD **)(v6 + 912) != v4 )
              goto LABEL_16;
LABEL_14:
            *(_WORD *)(v14 + 1838) = v4;
            *(_QWORD *)(v14 + 1840) = v12;
            *(_WORD *)(v14 + 1848) = v10;
            return 0i64;
          }
          if ( v15 == v4 )
            goto LABEL_14;
        }
      }
    }
LABEL_15:
    v6 = *((_QWORD *)this + 1);
    goto LABEL_16;
  }
  if ( *(_DWORD *)(*((_QWORD *)this + 1) + 68i64) == 100 )
  {
    *(_WORD *)(*((_QWORD *)this + 8) + 1836i64) = v4;
    return 0i64;
  }
  v6 = *((_QWORD *)this + 1);
LABEL_16:
  CSslContext::SetErrorAndFatalAlert(v6, 106, -2146893048, 0x32u);
  return 2148074248i64;
}
