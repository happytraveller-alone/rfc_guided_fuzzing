// File count: 1434
// Total lines: 58
----------------------------------------
struct DTlsRec *__fastcall DTlsMsgMgr::AddOutgoingRec(DTlsMsgMgr *this, unsigned int a2)
{
  _QWORD *v2; // rsi
  _QWORD *v3; // rbx
  DTlsMsgMgr *v6; // rdi
  DTlsMsgMgr *v7; // r14
  DTlsRec *v8; // rcx
  _QWORD *v9; // rax
  _QWORD *v10; // rdi
  _QWORD *v11; // rcx
  _QWORD *v12; // rax

  v2 = (_QWORD *)((char *)this + 56);
  v3 = 0i64;
  if ( (_QWORD *)*v2 == v2 )
  {
    v6 = (DTlsMsgMgr *)((char *)this + 72);
    v7 = (DTlsMsgMgr *)*((_QWORD *)this + 9);
    if ( v7 != (DTlsMsgMgr *)((char *)this + 72) )
    {
      do
      {
        v8 = (DTlsMsgMgr *)((char *)v7 - 40);
        v7 = *(DTlsMsgMgr **)v7;
        if ( v8 )
          DTlsRec::`scalar deleting destructor'(v8);
      }
      while ( v7 != v6 );
      *((_QWORD *)v6 + 1) = v6;
      *(_QWORD *)v6 = v6;
    }
  }
  v9 = SPExternalAlloc(0x38u);
  v10 = v9;
  if ( v9 )
  {
    v9[1] = 0i64;
    *v9 = 0i64;
    if ( (unsigned int)DTlsRec::initRec((DTlsRec *)v9, a2, *((struct CSsl3TlsContext **)this + 11)) )
    {
      DTlsRec::`scalar deleting destructor'((DTlsRec *)v10);
    }
    else
    {
      v11 = (_QWORD *)v2[1];
      v12 = v10 + 5;
      if ( (_QWORD *)*v11 != v2 )
        __fastfail(3u);
      *v12 = v2;
      v3 = v10;
      v10[6] = v11;
      *v11 = v12;
      v2[1] = v12;
    }
  }
  return (struct DTlsRec *)v3;
}
