// File count: 1088
// Total lines: 11
----------------------------------------
CTls13ChangeCipherSpec *__fastcall CTls13ChangeCipherSpec::`vector deleting destructor'(
        CTls13ChangeCipherSpec *this,
        char a2)
{
  *(_QWORD *)this = &CTls13ChangeCipherSpec::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
// 18007CB58: using guessed type void *CTls13ChangeCipherSpec::`vftable';
