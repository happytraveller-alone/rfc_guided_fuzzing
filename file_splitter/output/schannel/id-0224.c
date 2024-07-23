// File count: 224
// Total lines: 9
------------------------------------------
void __fastcall CCredentialGroup::~CCredentialGroup(CCredentialGroup *this)
{
  *(_QWORD *)this = &CCredentialGroup::`vftable';
  CCredentialGroup::DeleteCredentialGroup(this);
  *(_QWORD *)this = &IAllocate::`vftable';
}
// 18007C298: using guessed type void *IAllocate::`vftable';
// 18007D0D8: using guessed type void *CCredentialGroup::`vftable';
