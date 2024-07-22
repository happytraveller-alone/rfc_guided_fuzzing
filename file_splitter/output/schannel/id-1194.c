//----- (000000018005E790) ----------------------------------------------------
void __fastcall CSslCredential::~CSslCredential(CSslCredential *this)
{
  *(_QWORD *)this = &CSslCredential::`vftable';
  CSslCredential::DeleteCredential(this);
  *(_QWORD *)this = &IAllocate::`vftable';
}
// 18007C298: using guessed type void *IAllocate::`vftable';
// 18007FD20: using guessed type void *CSslCredential::`vftable';

