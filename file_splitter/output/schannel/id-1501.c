// File count: 1501
// Total lines: 13
----------------------------------------
__int64 __fastcall CTls13ChangeCipherSpec::GenerateMessage(CTls13ChangeCipherSpec *this)
{
  __int64 result; // rax

  result = (*(__int64 (__fastcall **)(_QWORD, __int64, void *))(**((_QWORD **)this + 1) + 32i64))(
             *((_QWORD *)this + 1),
             1i64,
             &CTls13ChangeCipherSpec::CcsMessage);
  if ( !(_DWORD)result )
    return (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)this + 1) + 40i64))(*((_QWORD *)this + 1));
  return result;
}
