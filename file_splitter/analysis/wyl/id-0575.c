//----- (00000001800286FC) ----------------------------------------------------
bool __fastcall _scrt_is_nonwritable_in_current_image(__int64 a1)
{
  unsigned __int64 v1; // r8
  _DWORD *v2; // rdx
  _DWORD *v3; // r9
  unsigned __int64 v4; // rcx

  if ( _ImageBase != 23117
    || *(_DWORD *)((char *)&_ImageBase + (int)off_18000003C) != 17744
    || *(__int16 *)((char *)&word_180000018 + (int)off_18000003C) != 523 )
  {
    return 0;
  }
  v1 = a1 - (_QWORD)&_ImageBase;
  v2 = (_DWORD *)((char *)&word_180000018
                + (int)off_18000003C
                + *(unsigned __int16 *)((char *)&word_180000014 + (int)off_18000003C));
  v3 = &v2[10 * *(unsigned __int16 *)((char *)&word_180000006 + (int)off_18000003C)];
  while ( v2 != v3 )
  {
    v4 = (unsigned int)v2[3];
    if ( v1 >= v4 && v1 < (unsigned int)(v4 + v2[2]) )
      return v2 && v2[9] >= 0;
    v2 += 10;
  }
  v2 = 0i64;
  return v2 && v2[9] >= 0;
}
// 180000000: using guessed type __int16 _ImageBase;
// 180000006: using guessed type __int16;
// 180000014: using guessed type __int16;
// 180000018: using guessed type __int16;
// 18000003C: using guessed type void *__ptr32 off_18000003C;

