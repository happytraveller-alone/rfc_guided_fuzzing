//----- (0000000180023030) ----------------------------------------------------
bool __fastcall CTls13ServerContext::UseSchannelRecordLayer(CTls13ServerContext *this)
{
  return (*((_QWORD *)this + 17) & 0x100000000i64) == 0;
}

