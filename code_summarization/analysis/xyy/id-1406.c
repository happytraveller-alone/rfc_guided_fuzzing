//----- (000000018006FCD4) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::FragmentOutgoingBuffer(CSsl3TlsContext *this, struct SPBuffer *a2)
{
  char *v2; // rsi
  __int64 v4; // r15
  __int64 v6; // rcx
  unsigned int v7; // r12d
  __int64 v8; // rdi
  int v9; // ecx
  char v10; // r10
  unsigned int v11; // r8d
  unsigned int v12; // ecx
  char *v13; // r9
  char *v14; // rdx
  unsigned __int64 v15; // r13
  __int64 result; // rax
  unsigned int v17; // edi
  struct DTlsRec *v18; // rax
  struct DTlsRec *v19; // rbp
  char v20; // [rsp+60h] [rbp+8h]

  v2 = (char *)*((_QWORD *)a2 + 1);
  v4 = *((unsigned int *)this + 15);
  if ( !v2 )
    return 0i64;
  LODWORD(v6) = *((_DWORD *)a2 + 1);
  v7 = 0;
  while ( 1 )
  {
    v8 = (unsigned __int8)v2[12] + ((unsigned __int8)v2[11] << 8);
    v7 += v4 + v8;
    if ( v7 > (unsigned int)v6 )
      return 87i64;
    v9 = (unsigned __int8)v2[12] + ((unsigned __int8)v2[11] << 8);
    v10 = *v2;
    v20 = *v2;
    if ( (*((_BYTE *)this + 32) & 4) != 0 )
    {
      v11 = *((_DWORD *)this + 13);
      v12 = v8 + *((_DWORD *)this + 12);
      if ( v11 )
      {
        if ( (*((_BYTE *)this + 56) & 1) != 0 )
          v11 -= v12 % v11;
        v12 += v11;
      }
      v9 = *((_DWORD *)this + 11) + v12;
    }
    if ( *((_DWORD *)this + 15) + v9 > (unsigned int)*((unsigned __int16 *)this + 108) )
    {
      v13 = &v2[v8 + v4];
      v14 = &v2[v4];
      while ( 1 )
      {
        v15 = (unsigned __int64)&v14[0x10000 * (unsigned __int64)(unsigned __int8)v14[1]
                                   + 12
                                   + 256 * (unsigned __int8)v14[2]
                                   + (unsigned __int8)v14[3]];
        if ( v15 > (unsigned __int64)v13 )
          return 87i64;
        result = CSsl3TlsContext::FragmentMessage((__int64)this, v14, v10);
        if ( (_DWORD)result )
          return result;
        v13 = &v2[v8 + v4];
        v10 = v20;
        v14 = (char *)v15;
        if ( (__int64)(v15 - (_QWORD)&v2[v4]) >= (unsigned int)v8 )
        {
          v17 = v4 + v8;
          goto LABEL_18;
        }
      }
    }
    v17 = v4 + v8;
    v18 = DTlsMsgMgr::AddOutgoingRec(*((DTlsMsgMgr **)this + 72), v17);
    v19 = v18;
    if ( !v18 )
      return 8i64;
    memcpy_0(*((void **)v18 + 1), v2, v17);
    *((_DWORD *)v19 + 1) = v17;
LABEL_18:
    v6 = *((unsigned int *)a2 + 1);
    v2 += v17;
    if ( (__int64)&v2[-*((_QWORD *)a2 + 1)] >= v6 )
      return 0i64;
  }
}
