//----- (0000000180047EB0) ----------------------------------------------------
__int64 __fastcall SslCrackSingleName(
        unsigned int a1,
        __int64 a2,
        struct _UNICODE_STRING *a3,
        struct _UNICODE_STRING *a4,
        unsigned int a5,
        struct _UNICODE_STRING *a6,
        struct _UNICODE_STRING *a7,
        unsigned int *a8)
{
  int v10; // edi
  USHORT v12; // cx
  WCHAR *v13; // rax
  SIZE_T v14; // rdx
  _WORD *v15; // rax
  _WORD *v16; // rsi
  int v17; // [rsp+54h] [rbp-64h] BYREF
  struct _UNICODE_STRING v18; // [rsp+58h] [rbp-60h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+68h] [rbp-50h] BYREF
  __int128 v20; // [rsp+78h] [rbp-40h] BYREF
  unsigned __int16 v22; // [rsp+C8h] [rbp+10h]

  v10 = 0;
  v20 = 0i64;
  if ( !(unsigned __int8)SampUsingDsData() )
    return 2148074242i64;
  if ( a4 )
  {
    if ( a3 )
    {
      v12 = a4->Length + a3->Length;
      if ( v12 < a3->Length || (unsigned __int16)(v12 + 4) < v12 )
        return 2148074240i64;
    }
  }
  v18.Buffer = (PWSTR)LocalAlloc(0x40u, 0x410ui64);
  v13 = (WCHAR *)LocalAlloc(0x40u, 0x208ui64);
  DestinationString.Buffer = v13;
  if ( v18.Buffer && v13 )
  {
    *(_DWORD *)&v18.Length = 68157440;
    *(_DWORD *)&DestinationString.Length = 34078720;
    a5 = 520;
    v17 = 260;
    if ( a4 )
    {
      v14 = (unsigned __int16)(a4->Length + a3->Length + 4);
      WORD1(v20) = v14;
      v22 = v14 - 2;
      LOWORD(v20) = v14 - 2;
      v15 = LocalAlloc(0x40u, v14);
      v16 = v15;
      *((_QWORD *)&v20 + 1) = v15;
      if ( v15 )
      {
        memcpy_0(v15, a4->Buffer, a4->Length);
        v16[(unsigned __int64)a4->Length >> 1] = 58;
        memcpy_0(&v16[((unsigned __int64)a4->Length >> 1) + 1], a3->Buffer, a3->Length);
        v16[(unsigned __int64)v22 >> 1] = 0;
        a3 = (struct _UNICODE_STRING *)&v20;
      }
      else
      {
        a3 = 0i64;
      }
    }
    else
    {
      v16 = (_WORD *)*((_QWORD *)&v20 + 1);
    }
    if ( a3 )
    {
      if ( IsCrackSingleNamePresent() )
      {
        if ( (unsigned int)CrackSingleName(
                             a1,
                             4i64,
                             a3->Buffer,
                             2i64,
                             &v17,
                             DestinationString.Buffer,
                             &a5,
                             v18.Buffer,
                             a8) )
        {
          v10 = -1073741823;
        }
        else
        {
          v10 = 0;
          RtlInitUnicodeString(&DestinationString, DestinationString.Buffer);
          RtlInitUnicodeString(&v18, v18.Buffer);
          *a6 = v18;
          *a7 = DestinationString;
        }
      }
      else
      {
        v10 = -1073741637;
      }
      if ( v16 )
        LocalFree(v16);
    }
  }
  else
  {
    v10 = -2146893056;
  }
  if ( v10 < 0 )
  {
    if ( v18.Buffer )
      LocalFree(v18.Buffer);
    if ( DestinationString.Buffer )
      LocalFree(DestinationString.Buffer);
  }
  return (unsigned int)v10;
}
// 1800982A0: using guessed type __int64 SampUsingDsData(void);
// 180098400: using guessed type __int64 __fastcall CrackSingleName(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD);
