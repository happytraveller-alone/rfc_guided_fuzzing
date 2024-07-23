//----- (000000018000FF48) ----------------------------------------------------
void __fastcall CCipherMill::GetBaseCipherSizes(CCipherMill *this, char a2, unsigned int *a3, unsigned int *a4)
{
  CMasterCipherInfo *v7; // rax
  unsigned int v8; // r8d
  unsigned int v9; // edx
  unsigned int *v10; // rcx
  unsigned int v11; // eax
  unsigned int v12; // eax

  *a3 = 0;
  *a4 = 0;
  RtlAcquireResourceShared(&Resource, 1u);
  v7 = xmmword_1800925B0;
  if ( a2 )
    v7 = *(&xmmword_1800925B0 + 1);
  if ( v7 )
  {
    v8 = *((_DWORD *)v7 + 2);
    v9 = 0;
    if ( v8 )
    {
      v10 = (unsigned int *)(*(_QWORD *)v7 + 20i64);
      do
      {
        if ( v9 )
        {
          v11 = *a3;
          if ( *a3 >= *v10 )
            v11 = *v10;
        }
        else
        {
          v11 = *v10;
        }
        *a3 = v11;
        v12 = *a4;
        if ( *a4 <= *v10 )
          v12 = *v10;
        ++v9;
        v10 += 216;
        *a4 = v12;
      }
      while ( v9 < v8 );
    }
  }
  RtlReleaseResource(&Resource);
}

