// File count: 243
// Total lines: 49
-----------------------------------------
void __fastcall CSslContext::GetCertContextInfo(
        CSslContext *this,
        unsigned __int8 **a2,
        unsigned int *a3,
        unsigned __int16 **a4,
        unsigned int *a5,
        unsigned __int16 **a6,
        unsigned int *a7,
        unsigned __int8 **a8,
        unsigned int *a9,
        const unsigned __int8 **a10,
        unsigned int *a11,
        unsigned __int8 **a12,
        unsigned int *a13)
{
  __int64 v17; // rax
  unsigned int v18; // ecx
  unsigned int *v19; // rax
  __int64 v20; // rcx

  v17 = (*(__int64 (__fastcall **)(CSslContext *))(*(_QWORD *)this + 248i64))(this);
  if ( v17 )
  {
    *a4 = *(unsigned __int16 **)(v17 + 400);
    *a5 = *(_DWORD *)(v17 + 408);
    *a6 = *(unsigned __int16 **)(v17 + 416);
    v18 = *(_DWORD *)(v17 + 424);
    v19 = a7;
  }
  else
  {
    v18 = 0;
    *a6 = 0i64;
    *a4 = 0i64;
    *a7 = 0;
    v19 = a5;
  }
  *v19 = v18;
  v20 = *((_QWORD *)this + 11);
  *a3 = *(_DWORD *)(v20 + 32);
  *a2 = *(unsigned __int8 **)(v20 + 24);
  (*(void (__fastcall **)(CSslContext *, unsigned __int8 **, unsigned int *))(*(_QWORD *)this + 272i64))(this, a8, a9);
  (*(void (__fastcall **)(CSslContext *, const unsigned __int8 **, unsigned int *))(*(_QWORD *)this + 280i64))(
    this,
    a10,
    a11);
  (*(void (__fastcall **)(CSslContext *, unsigned __int8 **, unsigned int *))(*(_QWORD *)this + 288i64))(this, a12, a13);
}
