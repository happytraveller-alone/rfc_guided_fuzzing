//----- (000000018005B01C) ----------------------------------------------------
void __fastcall CTls13Context::GetApplicationTrafficSecrets(
        CTls13Context *this,
        unsigned __int64 *a2,
        unsigned __int64 *a3)
{
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // r9

  v3 = 0i64;
  if ( a2 )
  {
    if ( *((_BYTE *)this + 201) )
      v4 = *((_QWORD *)this + 10);
    else
      v4 = 0i64;
    *a2 = v4;
  }
  if ( a3 )
  {
    if ( *((_BYTE *)this + 201) )
      v3 = *((_QWORD *)this + 11);
    *a3 = v3;
  }
}
