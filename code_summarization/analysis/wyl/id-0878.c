//----- (0000000180047838) ----------------------------------------------------
void __fastcall ConvertNameString(struct _UNICODE_STRING *a1)
{
  PWSTR Buffer; // rdx
  unsigned __int16 v2; // r10
  PWSTR v3; // r9
  __int64 v4; // rax

  Buffer = a1->Buffer;
  v2 = 0;
  if ( Buffer && a1->MaximumLength )
  {
    v3 = a1->Buffer;
    if ( a1->MaximumLength != 2i64 )
    {
      do
      {
        if ( !*Buffer )
          break;
        *v3 = *Buffer;
        if ( *Buffer == 13 && Buffer[1] == 10 )
        {
          ++Buffer;
          *v3 = 44;
        }
        v2 += 2;
        ++v3;
        ++Buffer;
      }
      while ( v2 < (unsigned __int64)a1->MaximumLength - 2 );
    }
    *v3 = 0;
    v4 = -1i64;
    do
      ++v4;
    while ( a1->Buffer[v4] );
    a1->Length = 2 * v4;
  }
}

