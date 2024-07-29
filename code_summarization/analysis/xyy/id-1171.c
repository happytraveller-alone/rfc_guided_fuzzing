//----- (000000018005DB58) ----------------------------------------------------
void __fastcall SPAddIssuerToCache(unsigned __int8 *a1, unsigned int a2)
{
  size_t v2; // rbx
  __int64 v4; // rbp
  DWORD TickCount; // r14d
  _QWORD *v6; // rdi
  HLOCAL v7; // rax
  char *v8; // rax
  char *v9; // rdx
  char **v10; // rcx
  _QWORD *v11; // rax
  _QWORD *v12; // rdx

  if ( a1 )
  {
    v2 = a2;
    if ( a2 )
    {
      if ( dword_180092778 )
      {
        if ( !(unsigned int)SPFindIssuerInCache(a1, a2) )
        {
          v4 = (unsigned int)ComputeIssuerCacheIndex(a1, v2) % dword_1800926FC;
          TickCount = GetTickCount();
          v6 = SPExternalAlloc(0x38u);
          if ( v6 )
          {
            v7 = SPExternalAlloc(v2);
            v6[1] = v7;
            if ( v7 )
            {
              *((_DWORD *)v6 + 4) = v2;
              memcpy_0(v7, a1, v2);
              *(_DWORD *)v6 = TickCount;
              RtlAcquireResourceExclusive(&stru_180092718, 1u);
              v8 = (char *)(v6 + 3);
              v9 = (char *)IssuerCache + 16 * v4;
              v10 = (char **)*((_QWORD *)v9 + 1);
              if ( *v10 != v9
                || (*(_QWORD *)v8 = v9,
                    v6[4] = v10,
                    *v10 = v8,
                    *((_QWORD *)v9 + 1) = v8,
                    v11 = v6 + 5,
                    v12 = (_QWORD *)qword_180092710,
                    *(__int64 **)qword_180092710 != &qword_180092708) )
              {
                __fastfail(3u);
              }
              *v11 = &qword_180092708;
              v6[6] = v12;
              *v12 = v11;
              ++dword_180092704;
              qword_180092710 = (__int64)(v6 + 5);
              RtlReleaseResource(&stru_180092718);
            }
            else
            {
              SPExternalFree(v6);
            }
          }
        }
      }
    }
  }
}
// 1800926FC: using guessed type int dword_1800926FC;
// 180092704: using guessed type int dword_180092704;
// 180092708: using guessed type __int64 qword_180092708;
// 180092710: using guessed type __int64 qword_180092710;
// 180092778: using guessed type int dword_180092778;
