// File count: 1099
// Total lines: 37
----------------------------------------
void __fastcall CSslContextManager::DeleteFullSslContext(CSslContextManager *this, struct CSslParentContext *a2)
{
  __int64 v4; // rcx
  int v5; // esi
  int v6; // r14d
  int v7; // ebx

  v4 = *((_QWORD *)a2 + 1);
  v5 = *(_DWORD *)(v4 + 64);
  v6 = *(_DWORD *)(v4 + 68);
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_q(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x12u, (__int64)&WPP_5f5b8daccbb63ec51f5b3bdd6563a375_Traceguids, a2);
    v4 = *((_QWORD *)a2 + 1);
  }
  if ( v4 )
  {
    v7 = *(_DWORD *)(v4 + 64);
    (**(void (__fastcall ***)(__int64, _QWORD))v4)(v4, 0i64);
    if ( (v7 & 0x800A2AAA) != 0 )
      SPExternalFree(*((void **)a2 + 1));
    *((_QWORD *)a2 + 1) = 0i64;
  }
  if ( (v5 & 0x51550) != 0 )
  {
    CSslContextManager::DeleteContextScratch((__int64)this, *((_QWORD *)a2 + 3), *((_BYTE *)a2 + 32), v6);
    *((_QWORD *)a2 + 3) = 0i64;
    (*(void (__fastcall **)(_QWORD, struct CSslParentContext *))(**((_QWORD **)this + 6) + 32i64))(
      *((_QWORD *)this + 6),
      a2);
  }
  else
  {
    SPExternalFree(a2);
  }
}
