// File count: 1432
// Total lines: 8
-----------------------------------------
DTlsRec *__fastcall DTlsRec::`scalar deleting destructor'(DTlsRec *this)
{
  DTlsRec::~DTlsRec(this);
  if ( this )
    SPExternalFree(this);
  return this;
}
