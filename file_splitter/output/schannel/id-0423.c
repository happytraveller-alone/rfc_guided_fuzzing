// File count: 423
// Total lines: 20
-----------------------------------------
unsigned __int64 __fastcall CCipherMill::GetAProvider(CCipherMill *this)
{
  unsigned __int64 v1; // rbx
  CCipherMill *v2; // rcx
  unsigned __int64 v4; // [rsp+30h] [rbp+8h] BYREF

  v1 = 0i64;
  v4 = 0i64;
  RtlAcquireResourceShared(&Resource, 1u);
  if ( qword_1800924A0[0] )
  {
    CCipherMill::ReferenceProvider(v2, qword_1800924A0[0], &v4);
    v1 = v4;
  }
  RtlReleaseResource(&Resource);
  return v1;
}
// 180018E87: variable 'v2' is possibly undefined
// 1800924A0: using guessed type unsigned __int64 qword_1800924A0[32];
