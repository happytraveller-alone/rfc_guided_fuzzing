//----- (0000000180065210) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeStatusRequestExtensionSize(CTls13ServerHandshake *this)
{
  __int64 v1; // rax
  __int64 v2; // rdx

  v1 = *((_QWORD *)this + 1);
  *((_WORD *)this + 76) = 0;
  v2 = *(_QWORD *)(v1 + 1512);
  if ( v2 )
  {
    if ( *(_DWORD *)(v2 + 16) > 0xFFF7u )
      return 87i64;
    *((_WORD *)this + 76) = *(_WORD *)(v2 + 16) + 4;
  }
  return 0i64;
}
