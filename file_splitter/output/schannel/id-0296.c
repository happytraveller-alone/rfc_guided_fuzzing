//----- (0000000180016724) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetFalseStart(CSsl3TlsContext *this, void *a2, int a3)
{
  unsigned int v3; // ebx
  int v6; // [rsp+50h] [rbp+18h] BYREF

  v3 = 0;
  v6 = 0;
  if ( a3 == 4
    && ((*(void (__fastcall **)(_QWORD, __int64, int *, void *))(LsaTable + 80))(0i64, 4i64, &v6, a2), v6 == 1) )
  {
    *((_BYTE *)this + 556) = 1;
  }
  else
  {
    return 87;
  }
  return v3;
}
// 180092620: using guessed type __int64 LsaTable;

