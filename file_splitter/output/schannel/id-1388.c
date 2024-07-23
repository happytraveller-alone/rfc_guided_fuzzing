// File count: 1388
// Total lines: 56
----------------------------------------
__int64 __fastcall CTls13Context::ReturnGenericExtensions(CTls13Context *this)
{
  const void *v1; // rdx
  size_t v3; // rdi
  __int64 v4; // rcx
  bool v5; // zf
  unsigned int v6; // edx

  v1 = (const void *)*((_QWORD *)this + 20);
  if ( v1 )
  {
    v3 = *((unsigned int *)this + 38);
    if ( (_DWORD)v3 )
    {
      v4 = *((_QWORD *)this + 18);
      if ( v4 )
      {
        v5 = *(_DWORD *)v4 == 0;
        if ( *(_DWORD *)v4 )
        {
          if ( *(_DWORD *)v4 < (unsigned int)v3 )
          {
            *(_DWORD *)v4 = v3;
            v6 = -2146892950;
            *((_BYTE *)this + 8) = 1;
LABEL_12:
            *((_QWORD *)this + 18) = 0i64;
            *((_QWORD *)this + 16) = 0i64;
            memset((char *)this + 112, 0, 8ui64);
            *((_BYTE *)this + 120) = 0;
            return v6;
          }
          v5 = *(_DWORD *)v4 == 0;
        }
        if ( v5 )
        {
          *(_QWORD *)(v4 + 8) = v1;
          **((_DWORD **)this + 18) = v3;
        }
        else
        {
          memcpy_0(*(void **)(v4 + 8), v1, v3);
          **((_DWORD **)this + 18) = v3;
          SPExternalFree(*((void **)this + 20));
        }
        *((_QWORD *)this + 20) = 0i64;
        v6 = 590614;
        *((_DWORD *)this + 38) = 0;
        *((_BYTE *)this + 136) = 0;
        goto LABEL_12;
      }
    }
  }
  return 0i64;
}
