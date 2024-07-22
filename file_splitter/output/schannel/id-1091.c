//----- (000000018005AB60) ----------------------------------------------------
CTls13Context *__fastcall CTls13Context::`vector deleting destructor'(CTls13Context *this, char a2)
{
  CTls13Context::~CTls13Context(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

