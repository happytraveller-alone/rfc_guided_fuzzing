// File count: 970
// Total lines: 63
-----------------------------------------
__int64 __fastcall CloseClientKeyHandleCallback(__int64 a1, DWORD a2, unsigned int *a3)
{
  int v4; // esi
  NCRYPT_HANDLE *v7; // rbx
  __int64 result; // rax
  CCipherMill *v9; // rcx
  SECURITY_STATUS v10; // eax
  BOOL v11; // eax

  v4 = 0;
  if ( !(unsigned int)SchannelInit(1) )
    return 1359i64;
  if ( !a3 )
    return 1359i64;
  v7 = (NCRYPT_HANDLE *)*((_QWORD *)a3 + 1);
  if ( !v7 )
    return 1359i64;
  if ( *a3 < (unsigned __int64)(16 * a1) )
    return 2148074264i64;
  if ( !a1 )
    goto LABEL_22;
  v9 = WPP_GLOBAL_Control;
  do
  {
    if ( *v7 )
    {
      v10 = NCryptFreeObject(*v7);
      v9 = WPP_GLOBAL_Control;
      v4 = v10;
    }
    if ( v4 < 0 && v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 1) != 0 )
    {
      WPP_SF_q(*((_QWORD *)v9 + 2), 0x30u, (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v7);
      v9 = WPP_GLOBAL_Control;
    }
    if ( v7[1] )
    {
      v11 = CryptReleaseContext(v7[1], a2);
      v9 = WPP_GLOBAL_Control;
      v4 = v11;
    }
    if ( v4 < 0 && v9 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v9 + 28) & 1) != 0 )
    {
      WPP_SF_q(*((_QWORD *)v9 + 2), 0x31u, (__int64)&WPP_e7a188b1921532aa285b79366435dd9d_Traceguids, v7 + 1);
      v9 = WPP_GLOBAL_Control;
    }
    v7 += 2;
    --a1;
  }
  while ( a1 );
  v7 = (NCRYPT_HANDLE *)*((_QWORD *)a3 + 1);
  if ( v7 )
  {
LABEL_22:
    SPExternalFree(v7);
    *((_QWORD *)a3 + 1) = 0i64;
  }
  a3[1] = 0;
  result = (unsigned int)v4;
  *a3 = 0;
  return result;
}
