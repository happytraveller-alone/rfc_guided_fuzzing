//----- (000000018006ECE0) ----------------------------------------------------
__int64 __fastcall CTls13ServerContext::SetClientShare(CTls13ServerContext *this, unsigned int a2, unsigned __int64 a3)
{
  int ClientShare; // eax
  unsigned int v8; // edi
  unsigned __int16 v9; // [rsp+68h] [rbp+10h] BYREF
  unsigned __int8 *v10; // [rsp+78h] [rbp+20h] BYREF

  if ( a2 > 0xFFFF )
    return 87i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 66i64, &WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids, a2);
  v10 = 0i64;
  v9 = 0;
  ClientShare = CTls13ServerContext::FindClientShare(this, a2, (const unsigned __int8 **)&v10, &v9);
  v8 = ClientShare;
  if ( ClientShare )
  {
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
      WPP_SF_DD(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        0x43u,
        (__int64)&WPP_d144303c37633bde7ff6f9c18fccf166_Traceguids,
        a2,
        ClientShare);
    return v8;
  }
  else if ( (unsigned int)CTls13Context::SetPeerPublicKey((CTls13ServerContext *)((char *)this + 1000), a2, v10, v9, a3) )
  {
    CSslContext::SetErrorAndFatalAlert((__int64)this, 1202, -2146893048, 0x32u);
    return 2148074248i64;
  }
  else
  {
    return 0i64;
  }
}
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);

