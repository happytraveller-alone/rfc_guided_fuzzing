// File count: 1093
// Total lines: 7
-----------------------------------------
DTlsMsgMgr *__fastcall DTlsMsgMgr::`scalar deleting destructor'(DTlsMsgMgr *this)
{
  DTlsMsgMgr::~DTlsMsgMgr(this);
  operator delete(this);
  return this;
}
