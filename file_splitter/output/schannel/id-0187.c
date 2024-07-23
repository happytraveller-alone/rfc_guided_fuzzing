// File count: 187
// Total lines: 47
-----------------------------------------
__int64 __fastcall CCredentialGroup::InitializeMinMaxStrengths(
        CCredentialGroup *this,
        unsigned int a2,
        unsigned int a3)
{
  unsigned int *v3; // rdi
  unsigned int *v5; // r14

  v3 = (unsigned int *)((char *)this + 168);
  v5 = (unsigned int *)((char *)this + 164);
  CCipherMill::GetBaseCipherSizes(this, *((_BYTE *)this + 172), (unsigned int *)this + 41, (unsigned int *)this + 42);
  if ( a2 )
  {
    if ( a2 == -1 )
    {
      a2 = 0;
    }
    else if ( a2 > *v3 )
    {
      return 2148074289i64;
    }
  }
  else
  {
    a2 = *v5;
    if ( *v5 < 0x28 )
      a2 = 40;
  }
  *v5 = a2;
  if ( a3 )
  {
    if ( a3 == -1 )
    {
      *v3 = 0;
    }
    else
    {
      if ( a3 < a2 )
        return 2148074289i64;
      *v3 = a3;
    }
  }
  if ( *v3 >= a2 )
    return 0i64;
  return 2148074289i64;
}
