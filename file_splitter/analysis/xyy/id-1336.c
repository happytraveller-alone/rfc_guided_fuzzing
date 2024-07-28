//----- (000000018006930C) ----------------------------------------------------
__int64 __fastcall CTls13ClientHandshake::ParseCertificateRequest(
        CTls13ClientHandshake *this,
        unsigned __int8 *a2,
        int a3)
{
  __int64 v4; // rcx
  unsigned int v5; // ebx
  int v6; // edx
  unsigned __int8 v7; // r9
  __int64 result; // rax
  __int64 v9; // rbp
  unsigned __int8 *v10; // rdi
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  unsigned __int16 v13; // cx
  unsigned int v14; // eax

  if ( !a2 || !a3 )
    return 87i64;
  v4 = *((_QWORD *)this + 1);
  v9 = *a2;
  v10 = a2 + 1;
  v11 = a3 - 1;
  if ( (_BYTE)v9 )
  {
    if ( *(_DWORD *)(v4 + 68) != 78 || v11 < (unsigned int)v9 )
      goto LABEL_4;
    result = CTls13ClientContext::SetCertificateRequestContext((CTls13ClientContext *)v4, v10, *a2);
    if ( (_DWORD)result )
      return result;
    v10 += v9;
    v11 -= v9;
LABEL_13:
    if ( v11 >= 2 && (v12 = v11 - 2, (v13 = _byteswap_ushort(*(_WORD *)v10)) != 0) && v12 >= v13 )
    {
      v14 = CTlsExt::ParseTlsExtensions(*((_QWORD *)this + 2), v10 + 2, v12, 13);
      v4 = *((_QWORD *)this + 1);
      v5 = v14;
      if ( v14 )
      {
        v7 = 110;
        v6 = 403;
        goto LABEL_5;
      }
      if ( v4 == -510 )
        return 2148074244i64;
      if ( *(_WORD *)(v4 + 510) )
        return 0i64;
    }
    else
    {
      v4 = *((_QWORD *)this + 1);
    }
LABEL_4:
    v5 = -2146893048;
    v6 = 400;
    v7 = 40;
LABEL_5:
    CSslContext::SetErrorAndFatalAlert(v4, v6, v5, v7);
    return v5;
  }
  if ( *(_DWORD *)(v4 + 68) != 78 )
    goto LABEL_13;
  result = CTls13ClientContext::SetCertificateRequestContext((CTls13ClientContext *)v4, 0i64, 0);
  if ( !(_DWORD)result )
    goto LABEL_13;
  return result;
}
