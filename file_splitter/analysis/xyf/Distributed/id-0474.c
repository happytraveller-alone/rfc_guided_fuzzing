//----- (0000000180022F70) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::PreparseMessage(CTls13ServerContext *this, struct SPBuffer *a2)
{
  unsigned int v2; // ebx

  v2 = 0;
  if ( a2 && this )
  {
    if ( *((_DWORD *)this + 17) == 4 && *((_DWORD *)a2 + 1) )
    {
      if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_s(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          0x12u,
          (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
          "server");
      *((_DWORD *)this + 17) = 78;
    }
  }
  else
  {
    return (unsigned int)-2146892963;
  }
  return v2;
}

