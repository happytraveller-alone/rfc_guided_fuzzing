// File count: 1398
// Total lines: 13
----------------------------------------
void __fastcall DTlsMessage::~DTlsMessage(DTlsMessage *this)
{
  void *v2; // rcx
  void *v3; // rcx

  v2 = (void *)*((_QWORD *)this + 5);
  if ( v2 )
    operator delete(v2);
  v3 = (void *)*((_QWORD *)this + 7);
  if ( v3 )
    operator delete(v3);
}
