//----- (0000000180072790) ----------------------------------------------------
void __fastcall DTlsRec::~DTlsRec(DTlsRec *this)
{
  if ( *((_QWORD *)this + 1) )
    (*(void (__fastcall **)(_QWORD, _QWORD))(**((_QWORD **)this + 2) + 16i64))(
      *((_QWORD *)this + 2),
      *((_QWORD *)this + 3));
}

