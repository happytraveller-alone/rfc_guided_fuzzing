//----- (0000000180009E8C) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::AllocateOutputBuffer(CSsl3TlsContext *this, struct SPBuffer *a2, unsigned int a3)
{
  HLOCAL Memory; // rax

  if ( *((_QWORD *)a2 + 1) )
  {
    if ( *(_DWORD *)a2 >= a3 )
      goto LABEL_3;
    *((_DWORD *)a2 + 1) = a3;
    return 2148074273i64;
  }
  else
  {
    *(_DWORD *)a2 = a3;
    Memory = CSslContext::GetMemory(this, a3);
    *((_QWORD *)a2 + 1) = Memory;
    if ( Memory )
    {
LABEL_3:
      *((_DWORD *)a2 + 1) = 0;
      return 0i64;
    }
    return 14i64;
  }
}

