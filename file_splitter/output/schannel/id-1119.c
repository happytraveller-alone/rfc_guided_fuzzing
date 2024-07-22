//----- (000000018005B354) ----------------------------------------------------
ULONG __fastcall CSslContext::ImpersonateNonLsNs(CSslContext *this, int *a2)
{
  __int64 v2; // r8
  __int64 v3; // rax

  v2 = *((_QWORD *)this + 10);
  *a2 = 0;
  v3 = *(_QWORD *)(v2 + 740);
  if ( v3 == 999 || v3 == 996 )
    return 0;
  else
    return SslImpersonateClient(*(_QWORD *)(v2 + 752), a2);
}

