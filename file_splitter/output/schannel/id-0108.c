//----- (0000000180008DA0) ----------------------------------------------------
void __fastcall CTlsExtClient::~CTlsExtClient(CTlsExtClient *this)
{
  void *v2; // rcx

  *(_QWORD *)this = &CTlsExtClient::`vftable';
  v2 = (void *)*((_QWORD *)this + 5);
  if ( v2 )
    SPExternalFree(v2);
  *(_QWORD *)this = &CTlsExt::`vftable';
}
// 18007D038: using guessed type void *CTlsExt::`vftable';
// 18007D048: using guessed type void *CTlsExtClient::`vftable';

