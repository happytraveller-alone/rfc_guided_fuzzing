//----- (0000000180073880) ----------------------------------------------------
__int64 __fastcall DTlsMessage::initMsg(DTlsMessage *this, int a2, int a3, int a4, unsigned int a5)
{
  unsigned int v5; // ebx
  unsigned int v10; // ebp
  void *v11; // rax
  void *v12; // rax
  __int64 v13; // rax

  v5 = 0;
  v10 = a4 + a5;
  if ( !(a4 + a5) )
    return 87;
  v11 = operator new(v10);
  *((_QWORD *)this + 5) = v11;
  if ( !v11 )
    return 8;
  v12 = operator new((unsigned __int64)(unsigned int)(a4 + 7) >> 3);
  *((_QWORD *)this + 7) = v12;
  if ( !v12 )
  {
    operator delete(*((void **)this + 5));
    *((_QWORD *)this + 5) = 0i64;
    return 8;
  }
  *((_DWORD *)this + 5) = v10;
  *((_DWORD *)this + 4) = a4;
  *((_DWORD *)this + 7) = a4 == 0;
  memset_0(v12, 0, (unsigned __int64)(unsigned int)(a4 + 7) >> 3);
  if ( a4 )
    v13 = *((_QWORD *)this + 5) + a5;
  else
    v13 = 0i64;
  *((_QWORD *)this + 6) = v13;
  *((_DWORD *)this + 6) = a2;
  *((_DWORD *)this + 16) = a3;
  return v5;
}
