//----- (000000018000EC6C) ----------------------------------------------------
void __fastcall CSslUserContext::~CSslUserContext(CSslUserContext *this)
{
  *(_QWORD *)this = &CSslUserContext::`vftable';
  CSslUserContext::CleanupUserContext(this);
  *(_QWORD *)this = &ISslSerialize::`vftable';
}
// 18007CFB8: using guessed type void *ISslSerialize::`vftable';
// 18007D058: using guessed type void *CSslUserContext::`vftable';

