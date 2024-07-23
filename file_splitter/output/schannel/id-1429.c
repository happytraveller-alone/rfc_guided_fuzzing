// File count: 1429
// Total lines: 19
----------------------------------------
void __fastcall DTlsHandshakeQueue::~DTlsHandshakeQueue(DTlsHandshakeQueue *this)
{
  DTlsMessage *v2; // rcx
  DTlsMessage *v3; // rcx

  v2 = (DTlsMessage *)*((_QWORD *)this + 2);
  if ( v2 )
  {
    DTlsMessage::`scalar deleting destructor'(v2);
    *((_QWORD *)this + 2) = 0i64;
  }
  v3 = (DTlsMessage *)*((_QWORD *)this + 3);
  if ( v3 )
  {
    DTlsMessage::`scalar deleting destructor'(v3);
    *((_QWORD *)this + 3) = 0i64;
  }
}
