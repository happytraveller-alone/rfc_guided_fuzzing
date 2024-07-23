// File count: 1435
// Total lines: 22
----------------------------------------
void __fastcall DTlsHandshakeQueue::DtlsHandshakeDone(DTlsHandshakeQueue *this)
{
  DTlsMessage *v2; // rcx
  DTlsMessage *v3; // rcx

  *((_DWORD *)this + 2) = 0;
  v2 = (DTlsMessage *)*((_QWORD *)this + 2);
  if ( v2 )
  {
    DTlsMessage::`scalar deleting destructor'(v2);
    *((_QWORD *)this + 2) = 0i64;
  }
  *((_DWORD *)this + 3) = 0;
  v3 = (DTlsMessage *)*((_QWORD *)this + 3);
  if ( v3 )
  {
    DTlsMessage::`scalar deleting destructor'(v3);
    *((_QWORD *)this + 3) = 0i64;
  }
  *((_DWORD *)this + 8) = 4;
}
