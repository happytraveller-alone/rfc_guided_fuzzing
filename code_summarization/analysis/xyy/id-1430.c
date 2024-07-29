//----- (00000001800726F4) ----------------------------------------------------
void __fastcall DTlsMsgMgr::~DTlsMsgMgr(DTlsMsgMgr *this)
{
  DTlsMessage *v1; // rsi
  DTlsMessage *v3; // rbx
  DTlsMessage *v4; // rcx
  DTlsMsgMgr *v5; // rbx
  DTlsMessage *v6; // rcx
  DTlsMsgMgr *v7; // rbx
  DTlsRec *v8; // rcx
  _QWORD **v9; // rdi
  _QWORD *v10; // rbx
  DTlsRec *v11; // rcx

  v1 = (DTlsMsgMgr *)((char *)this + 24);
  v3 = (DTlsMessage *)*((_QWORD *)this + 3);
  while ( v3 != v1 )
  {
    v4 = v3;
    v3 = *(DTlsMessage **)v3;
    DTlsMessage::`scalar deleting destructor'(v4);
  }
  v5 = (DTlsMsgMgr *)*((_QWORD *)this + 5);
  while ( v5 != (DTlsMsgMgr *)((char *)this + 40) )
  {
    v6 = v5;
    v5 = *(DTlsMsgMgr **)v5;
    DTlsMessage::`scalar deleting destructor'(v6);
  }
  v7 = (DTlsMsgMgr *)*((_QWORD *)this + 7);
  while ( v7 != (DTlsMsgMgr *)((char *)this + 56) )
  {
    v8 = (DTlsMsgMgr *)((char *)v7 - 40);
    v7 = *(DTlsMsgMgr **)v7;
    if ( v8 )
      DTlsRec::`scalar deleting destructor'(v8);
  }
  v9 = (_QWORD **)((char *)this + 72);
  v10 = *v9;
  while ( v10 != v9 )
  {
    v11 = (DTlsRec *)(v10 - 5);
    v10 = (_QWORD *)*v10;
    if ( v11 )
      DTlsRec::`scalar deleting destructor'(v11);
  }
}

