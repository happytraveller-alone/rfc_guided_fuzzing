// File count: 1399
// Total lines: 8
-----------------------------------------
DTlsMessage *__fastcall DTlsMessage::`scalar deleting destructor'(DTlsMessage *this)
{
  DTlsMessage::~DTlsMessage(this);
  if ( this )
    SPExternalFree(this);
  return this;
}
