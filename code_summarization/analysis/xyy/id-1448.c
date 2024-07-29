//----- (0000000180073A40) ----------------------------------------------------
__int64 __fastcall DTlsMsgMgr::swapSaveAndOutgoing(DTlsMsgMgr *this)
{
  _QWORD *v1; // rdx
  _QWORD *v2; // rax
  _QWORD *v3; // rax
  __int64 result; // rax

  v1 = (_QWORD *)((char *)this + 56);
  if ( (_QWORD *)*v1 != v1 )
    return 2148074244i64;
  v2 = (_QWORD *)*((_QWORD *)this + 9);
  if ( v2 == (_QWORD *)((char *)this + 72) )
    return 2148074244i64;
  *v1 = v2;
  v2[1] = v1;
  v3 = (_QWORD *)*((_QWORD *)this + 10);
  *((_QWORD *)this + 8) = v3;
  *v3 = v1;
  result = 0i64;
  *((_QWORD *)this + 10) = (char *)this + 72;
  *((_QWORD *)this + 9) = (char *)this + 72;
  return result;
}

