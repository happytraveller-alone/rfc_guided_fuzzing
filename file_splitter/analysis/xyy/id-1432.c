//----- (00000001800727CC) ----------------------------------------------------
DTlsRec *__fastcall DTlsRec::`scalar deleting destructor'(DTlsRec *this)
{
  DTlsRec::~DTlsRec(this);
  if ( this )
    SPExternalFree(this);
  return this;
}

