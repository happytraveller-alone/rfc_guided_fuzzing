// File count: 197
// Total lines: 31
-----------------------------------------
void __fastcall CCredentialGroup::GetCredentialExpirationTime(CCredentialGroup *this, union _LARGE_INTEGER *a2)
{
  struct _RTL_RESOURCE *v4; // rsi
  _QWORD *v5; // rdi
  _QWORD *v6; // rcx
  __int64 v7; // rax

  if ( a2 )
  {
    a2->QuadPart = 0x7FFFFF36D5969FFFi64;
    if ( *((_DWORD *)this + 7) )
    {
      v4 = (struct _RTL_RESOURCE *)((char *)this + 48);
      RtlAcquireResourceShared((PRTL_RESOURCE)((char *)this + 48), 1u);
      v5 = (_QWORD *)((char *)this + 32);
      v6 = (_QWORD *)*v5;
      while ( v6 != v5 )
      {
        v7 = v6[3];
        v6 = (_QWORD *)*v6;
        if ( v7 )
        {
          *a2 = *(union _LARGE_INTEGER *)(*(_QWORD *)(v7 + 24) + 72i64);
          break;
        }
      }
      RtlReleaseResource(v4);
    }
  }
}
