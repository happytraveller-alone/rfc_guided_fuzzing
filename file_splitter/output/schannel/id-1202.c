//----- (000000018005F670) ----------------------------------------------------
unsigned int __fastcall CSslCredential::GetEccEphemeralKeyInfo(
        CSslCredential *this,
        unsigned int a2,
        struct CEphemKeyData **a3)
{
  unsigned int v4; // esi
  CSslCredential *v5; // rdi
  struct CEphemKeyData **v6; // r8
  struct _RTL_RESOURCE *v7; // r14
  char *v8; // rbx
  char *i; // rax
  struct CEphemKeyData **v10; // rbp
  _DWORD *v11; // rax
  __int64 v13; // rcx

  v4 = a2;
  v5 = this;
  if ( a2 == *((_DWORD *)this + 35) )
  {
    v6 = (struct CEphemKeyData **)((char *)this + 504);
  }
  else
  {
    *a3 = 0i64;
    v7 = (struct _RTL_RESOURCE *)((char *)this + 552);
    RtlAcquireResourceExclusive((PRTL_RESOURCE)((char *)this + 552), 1u);
    v8 = (char *)v5 + 480;
    for ( i = (char *)*((_QWORD *)v5 + 60); i != v8; i = *(char **)i )
    {
      if ( *((_DWORD *)i + 4) == v4 )
      {
        v10 = (struct CEphemKeyData **)(i + 24);
        if ( i != (char *)-24i64 )
          goto LABEL_14;
        break;
      }
    }
    v11 = LocalAlloc(0x40u, 0x20ui64);
    if ( !v11 )
    {
      RtlReleaseResource(v7);
      return 14;
    }
    v11[4] = v4;
    *((_QWORD *)v11 + 1) = v11;
    *(_QWORD *)v11 = v11;
    v13 = *(_QWORD *)v8;
    if ( *(char **)(*(_QWORD *)v8 + 8i64) != v8 )
      __fastfail(3u);
    *(_QWORD *)v11 = v13;
    v10 = (struct CEphemKeyData **)(v11 + 6);
    *((_QWORD *)v11 + 1) = v8;
    *(_QWORD *)(v13 + 8) = v11;
    *(_QWORD *)v8 = v11;
LABEL_14:
    RtlReleaseResource(v7);
    v6 = v10;
    a2 = v4;
    this = v5;
  }
  return CSslCredential::GetEphemeralKeyInfo(this, a2, v6, a3);
}

