//----- (000000018004A314) ----------------------------------------------------
__int64 __fastcall SslMapExternalCredential(
        void **a1,
        _DWORD *a2,
        void *a3,
        unsigned int a4,
        void **a5,
        unsigned int *a6,
        int *a7)
{
  void **v9; // rdi
  unsigned int v10; // ebx
  struct _CERT_CONTEXT *v11; // rdx
  int v12; // r8d
  unsigned int v13; // ecx
  int v14; // eax
  _DWORD *v15; // rax
  HANDLE v16; // rcx
  void *v18; // [rsp+30h] [rbp-38h]
  HANDLE hObject; // [rsp+80h] [rbp+18h] BYREF
  enum _NT_PRODUCT_TYPE ProductType; // [rsp+88h] [rbp+20h] BYREF

  hObject = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 73i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids);
  v9 = a5;
  if ( a5 )
    *a5 = 0i64;
  if ( a4 < 0x20 || a2[1] != 32 )
  {
    v10 = -1073741811;
    goto LABEL_18;
  }
  if ( RtlGetNtProductType(&ProductType) )
  {
    v11 = (struct _CERT_CONTEXT *)*((_QWORD *)a2 + 2);
    v12 = a2[2];
    v13 = a2[6] | 0x80000000;
    if ( ProductType == NtProductLanManNt )
      v14 = SslLocalMapCredential(0i64, 0i64, v12, 0i64, v13, v11, 0i64, 0i64, 0i64, (unsigned __int64 *)&hObject);
    else
      v14 = SslRemoteMapCredential(0i64, v11, v12, 0i64, v13, v11, v18, 0i64, 0i64, (unsigned __int64 *)&hObject);
    if ( v14 < 0 )
    {
      *a6 = 0;
      v10 = 0;
      *a7 = v14;
      goto LABEL_18;
    }
    v15 = VirtualAlloc(0i64, 0x18ui64, 0x1000u, 4u);
    if ( v15 )
    {
      v15[1] = 24;
      *v15 = 6;
      v16 = hObject;
      v15[4] = 0;
      *((_QWORD *)v15 + 1) = v16;
      *v9 = v15;
      LODWORD(v16) = v15[1];
      hObject = 0i64;
      *a6 = (unsigned int)v16;
      *a7 = 0;
      v10 = 0;
      goto LABEL_20;
    }
  }
  v10 = -1073741801;
LABEL_18:
  if ( hObject )
    CloseHandle(hObject);
LABEL_20:
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 74i64, &WPP_dd7b7bddfdb936bf76d1675dae523069_Traceguids, v10);
  return v10;
}
// 18004A40F: variable 'v18' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

