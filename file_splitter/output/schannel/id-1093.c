//----- (000000018005ABD8) ----------------------------------------------------
DTlsMsgMgr *__fastcall DTlsMsgMgr::`scalar deleting destructor'(DTlsMsgMgr *this)
{
  DTlsMsgMgr::~DTlsMsgMgr(this);
  operator delete(this);
  return this;
}

