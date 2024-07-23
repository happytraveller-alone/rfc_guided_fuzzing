// File count: 1210
// Total lines: 8
-----------------------------------------
CTlsExtClient *__fastcall CTlsExtClient::`scalar deleting destructor'(CTlsExtClient *this, char a2)
{
  CTlsExtClient::~CTlsExtClient(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
