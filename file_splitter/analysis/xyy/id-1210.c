//----- (00000001800603D0) ----------------------------------------------------
CTlsExtClient *__fastcall CTlsExtClient::`scalar deleting destructor'(CTlsExtClient *this, char a2)
{
  CTlsExtClient::~CTlsExtClient(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

