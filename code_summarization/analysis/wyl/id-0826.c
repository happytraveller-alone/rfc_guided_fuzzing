//----- (0000000180043FA0) ----------------------------------------------------
__int64 __fastcall GenerateDTLSHelloVerify(struct SPBuffer *a1, unsigned __int8 *a2)
{
  char *v2; // rax
  unsigned int v3; // ebx
  __int128 v6; // xmm1
  __int64 v7; // rcx

  v2 = (char *)*((_QWORD *)a1 + 1);
  v3 = 0;
  if ( !v2 )
  {
    *(_DWORD *)a1 = 60;
    v2 = (char *)SPExternalAlloc(0x3Cu);
    *((_QWORD *)a1 + 1) = v2;
    if ( !v2 )
      return 14;
LABEL_6:
    *((_DWORD *)a1 + 1) = 0;
    *(_OWORD *)(v2 + 28) = *(_OWORD *)a2;
    v6 = *((_OWORD *)a2 + 1);
    *(_DWORD *)(v2 + 13) = 587202563;
    *(_OWORD *)(v2 + 44) = v6;
    *((_DWORD *)v2 + 6) = 553647651;
    *((_DWORD *)v2 + 5) = 0;
    v2[19] = 0;
    v7 = *((_QWORD *)a1 + 1);
    *(_DWORD *)v7 = 16776726;
    *(_WORD *)(v7 + 4) = 0;
    *(_DWORD *)(v7 + 7) = 0;
    *(_BYTE *)(v7 + 6) = 0;
    *(_WORD *)(v7 + 11) = 12032;
    *((_DWORD *)a1 + 1) = 60;
    return v3;
  }
  if ( *(_DWORD *)a1 >= 0x3Cu )
    goto LABEL_6;
  *((_DWORD *)a1 + 1) = 60;
  return (unsigned int)-2146893023;
}

