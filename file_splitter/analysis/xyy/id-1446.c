//----- (000000018007395C) ----------------------------------------------------
__int64 __fastcall DTlsRec::initRec(DTlsRec *this, unsigned int a2, struct CSsl3TlsContext *a3)
{
  unsigned int v3; // ebx
  __int64 v6; // rax

  v3 = 0;
  if ( a3 )
  {
    *((_QWORD *)this + 2) = a3;
    v6 = (*(__int64 (__fastcall **)(struct CSsl3TlsContext *, _QWORD))(*(_QWORD *)a3 + 8i64))(a3, a2);
    *((_QWORD *)this + 3) = v6;
    if ( v6 )
    {
      *((_QWORD *)this + 1) = v6;
      *(_DWORD *)this = a2;
      *((_DWORD *)this + 1) = 0;
      *((_DWORD *)this + 8) = 0;
    }
    else
    {
      return 8;
    }
  }
  else
  {
    return 87;
  }
  return v3;
}

