//----- (000000018005F458) ----------------------------------------------------
void __fastcall CSslCredential::DeleteLocalServerKeys(CSslCredential *this)
{
  void *v2; // rcx

  v2 = (void *)*((_QWORD *)this + 11);
  if ( v2 )
  {
    if ( *((_DWORD *)this + 24) )
    {
      do
        CSslServerKey::Dereference(*(CSslServerKey **)(*((_QWORD *)this + 11)
                                                     + 8i64 * (unsigned int)(*((_DWORD *)this + 24) - 1)));
      while ( (*((_DWORD *)this + 24))-- != 1 );
      v2 = (void *)*((_QWORD *)this + 11);
    }
    SPExternalFree(v2);
    *((_QWORD *)this + 11) = 0i64;
  }
}
