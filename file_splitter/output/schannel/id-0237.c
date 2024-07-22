//----- (0000000180013C60) ----------------------------------------------------
__int64 __fastcall CCipherMill::GetEccCurveType(CCipherMill *this, char *a2, unsigned int *a3)
{
  unsigned int EccCurveType; // ebx
  int v7; // r15d
  __int64 v8; // rsi
  unsigned int v9; // edi
  __int64 v10; // rbp
  __int128 i; // [rsp+20h] [rbp-38h] BYREF
  __int64 v12; // [rsp+30h] [rbp-28h]

  *a3 = 0;
  RtlAcquireResourceShared(&Resource, 1u);
  if ( a2 && qword_1800925C8 )
  {
    EccCurveType = CMasterEccCurveInfo::GetEccCurveType(qword_1800925C8, a2, a3);
    if ( EccCurveType )
    {
      v7 = 0;
      v8 = 0i64;
      v12 = 0i64;
      for ( i = 0i64; (unsigned int)v8 < qword_180092498; v8 = (unsigned int)(v8 + 1) )
      {
        if ( !(unsigned int)SslEnumEccCurves(qword_1800924A0[v8], (char *)&i + 8, &i, 0i64) )
        {
          v9 = 0;
          if ( DWORD2(i) )
          {
            while ( 1 )
            {
              v10 = i + 780i64 * v9;
              if ( !(unsigned int)o__stricmp_0(v10 + 510, a2) )
                break;
              if ( ++v9 >= DWORD2(i) )
                goto LABEL_13;
            }
            EccCurveType = 0;
            *a3 = *(_DWORD *)(v10 + 772);
            v7 = 1;
          }
        }
LABEL_13:
        if ( (_QWORD)i )
        {
          SslFreeBuffer();
          *(_QWORD *)&i = 0i64;
        }
        if ( v7 )
          break;
      }
    }
  }
  else
  {
    EccCurveType = 87;
  }
  RtlReleaseResource(&Resource);
  return EccCurveType;
}
// 180028D24: using guessed type __int64 __fastcall o__stricmp_0(_QWORD, _QWORD);
// 1800924A0: using guessed type unsigned __int64 qword_1800924A0[32];
// 180098458: using guessed type __int64 __fastcall SslEnumEccCurves(_QWORD, _QWORD, _QWORD, _QWORD);
// 180098480: using guessed type __int64 SslFreeBuffer(void);

