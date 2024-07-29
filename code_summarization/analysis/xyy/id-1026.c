//----- (0000000180055D18) ----------------------------------------------------
__int64 __fastcall CCredentialGroup::FindCredential(
        CCredentialGroup *this,
        unsigned __int8 *a2,
        int a3,
        struct CSslCredential **a4)
{
  unsigned int v8; // ebx
  CCredentialGroup *v9; // rdx
  char *v10; // r8
  unsigned __int64 v11; // rcx

  v8 = 1168;
  if ( !a2 || !a3 || !a4 )
    return 87i64;
  RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
  v9 = (CCredentialGroup *)*((_QWORD *)this + 4);
  while ( v9 != (CCredentialGroup *)((char *)this + 32) )
  {
    v10 = (char *)v9 - 8;
    v9 = *(CCredentialGroup **)v9;
    if ( a3 == 20 )
    {
      v11 = *((_QWORD *)v10 + 5) - *(_QWORD *)a2;
      if ( !v11 )
      {
        v11 = *((_QWORD *)v10 + 6) - *((_QWORD *)a2 + 1);
        if ( !v11 )
          v11 = *((unsigned int *)v10 + 14) - (unsigned __int64)*((unsigned int *)a2 + 4);
      }
      if ( !v11 )
      {
        v8 = 0;
        *a4 = (struct CSslCredential *)v10;
        break;
      }
    }
  }
  RtlReleaseResource((PRTL_RESOURCE)((char *)this + 48));
  return v8;
}

