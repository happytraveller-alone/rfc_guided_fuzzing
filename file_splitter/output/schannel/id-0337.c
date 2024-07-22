//----- (0000000180017F60) ----------------------------------------------------
void __fastcall CSslUserContext::GetCertContextInfo(
        CSslUserContext *this,
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
  *a2 = (unsigned __int8 *)*((_QWORD *)this + 19);
  *a3 = *((_DWORD *)this + 40);
  *a4 = (unsigned __int16 *)*((_QWORD *)this + 21);
  *a5 = *((_DWORD *)this + 44);
  *a6 = (unsigned __int16 *)*((_QWORD *)this + 23);
  *a7 = *((_DWORD *)this + 48);
  *a8 = (unsigned __int8 *)*((_QWORD *)this + 25);
  *a9 = *((_DWORD *)this + 52);
  *a10 = (const unsigned __int8 *)*((_QWORD *)this + 27);
  *a11 = *((_DWORD *)this + 56);
  *a12 = (unsigned __int8 *)*((_QWORD *)this + 29);
  *a13 = *((_DWORD *)this + 60);
}

