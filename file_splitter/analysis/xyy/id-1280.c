//----- (0000000180065098) ----------------------------------------------------
__int64 __fastcall CTls13ServerHandshake::ComputeServerHelloOrHRRSize(
        CTls13ServerHandshake *this,
        __int64 a2,
        char a3,
        unsigned __int16 *a4)
{
  __int64 v6; // rax
  __int64 result; // rax
  __int64 v8; // rcx
  unsigned int v9; // eax
  unsigned int v10; // edx

  if ( !a2 || !a4 )
    return 87i64;
  v6 = *((_QWORD *)this + 1);
  *((_QWORD *)this + 3) = a2;
  *((_WORD *)this + 22) = *(_WORD *)(v6 + 16);
  if ( !a3 )
  {
    *((_WORD *)this + 26) = 2;
    *((_BYTE *)this + 54) = 2;
    result = CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::ComputeGenericExtensionsSize((__int64)this, 2);
    if ( (_DWORD)result )
      return result;
    v9 = *(unsigned __int16 *)(v8 + 122) + 12;
    if ( v9 > 0xFFFF )
      return 1359i64;
    *(_WORD *)(v8 + 40) = v9;
LABEL_10:
    v10 = *(unsigned __int8 *)(*((_QWORD *)this + 1) + 1281i64) + *((unsigned __int16 *)this + 20) + 44;
    if ( v10 <= 0xFFFF )
    {
      *((_WORD *)this + 80) = v10;
      result = 0i64;
      *a4 = v10;
      return result;
    }
    return 1359i64;
  }
  result = CTls13ServerHandshake::ComputeServerHelloExtensionsSize(this);
  if ( !(_DWORD)result )
    goto LABEL_10;
  return result;
}
// 1800650E7: variable 'v8' is possibly undefined

