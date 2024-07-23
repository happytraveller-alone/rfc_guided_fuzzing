//----- (000000018006F734) ----------------------------------------------------
DTlsMessage *__fastcall DTlsMessage::`scalar deleting destructor'(DTlsMessage *this)
{
  DTlsMessage::~DTlsMessage(this);
  if ( this )
    SPExternalFree(this);
  return this;
}

