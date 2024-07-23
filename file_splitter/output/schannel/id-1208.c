// File count: 1208
// Total lines: 13
----------------------------------------
void __fastcall CSslCredential::RemoteCloseKeyHandle(CSslCredential *this, __int64 a2, int a3)
{
  __int64 v3; // rdx

  v3 = *((_QWORD *)this + 14);
  if ( v3 || *((_QWORD *)this + 13) && *((_BYTE *)this + 78) )
  {
    RemotelyCloseClientKeyHandle(*((_QWORD *)this + 13), v3, a3);
    *((_QWORD *)this + 13) = 0i64;
    *((_QWORD *)this + 14) = 0i64;
  }
}
