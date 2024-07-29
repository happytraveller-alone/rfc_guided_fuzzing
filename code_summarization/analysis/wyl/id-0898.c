//----- (000000018004BCEC) ----------------------------------------------------
void __fastcall SslFreeString(struct _UNICODE_STRING *a1)
{
  PWSTR Buffer; // rcx

  if ( a1 )
  {
    Buffer = a1->Buffer;
    if ( Buffer )
    {
      SPExternalFree(Buffer);
      *a1 = 0i64;
    }
  }
}

