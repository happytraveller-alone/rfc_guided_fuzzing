//----- (0000000180043028) ----------------------------------------------------
__int64 __fastcall UpdatePrivateKeysForCreds(struct CCredentialGroup *this, struct _SecBuffer *a2, char a3)
{
  int v3; // r15d
  unsigned int v4; // ebx
  unsigned int cbBuffer; // esi
  unsigned int *pvBuffer; // rdi
  struct CSslCredential *v10; // rdx
  unsigned int v11; // esi
  __int64 v12; // rax
  __int64 v13; // rcx
  struct CSslCredential *v15; // [rsp+58h] [rbp+10h] BYREF

  v15 = 0i64;
  v3 = 0;
  v4 = 0;
  if ( !a2 || !this )
    return 2148074244i64;
  cbBuffer = a2->cbBuffer;
  pvBuffer = (unsigned int *)a2->pvBuffer;
  while ( 1 )
  {
    if ( !cbBuffer )
    {
      *((_DWORD *)this + 184) = v3;
      goto LABEL_17;
    }
    if ( cbBuffer < 0x14 )
      break;
    if ( (unsigned int)CCredentialGroup::FindCredential(this, (unsigned __int8 *)pvBuffer, 20, &v15) )
      break;
    v10 = v15;
    v11 = cbBuffer - 20;
    if ( !v15 )
      break;
    if ( a3 )
    {
      if ( v11 < 8 )
        break;
      v12 = pvBuffer[5];
      v13 = pvBuffer[6];
      pvBuffer += 7;
      cbBuffer = v11 - 8;
    }
    else
    {
      if ( v11 < 0x10 )
        break;
      v12 = *(_QWORD *)(pvBuffer + 5);
      v13 = *(_QWORD *)(pvBuffer + 7);
      pvBuffer += 9;
      cbBuffer = v11 - 16;
    }
    if ( !v12 && !v13 )
      break;
    *((_QWORD *)v15 + 13) = v12;
    ++v3;
    *((_QWORD *)v10 + 14) = v13;
  }
  v4 = -2146893052;
LABEL_17:
  a2->pvBuffer = 0i64;
  a2->cbBuffer = 0;
  a2->BufferType = 0;
  CleanupAppModeInfo(0i64);
  return v4;
}

