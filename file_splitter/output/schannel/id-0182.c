// File count: 182
// Total lines: 40
-----------------------------------------
__int64 __fastcall SpQueryApplicationProtocol(
        struct CSslUserContext *a1,
        struct _SecPkgContext_ApplicationProtocol *a2)
{
  _OWORD *v4; // rax
  __int64 v5; // rcx
  __int128 v6; // xmm1

  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 108i64, &WPP_744a13241c3c3d6f8c9be4f6b1c08345_Traceguids);
  v4 = (_OWORD *)*((_QWORD *)a1 + 49);
  if ( v4 )
  {
    v5 = 2i64;
    do
    {
      *(_OWORD *)&a2->ProtoNegoStatus = *v4;
      *(_OWORD *)&a2->ProtocolId[7] = v4[1];
      *(_OWORD *)&a2->ProtocolId[23] = v4[2];
      *(_OWORD *)&a2->ProtocolId[39] = v4[3];
      *(_OWORD *)&a2->ProtocolId[55] = v4[4];
      *(_OWORD *)&a2->ProtocolId[71] = v4[5];
      *(_OWORD *)&a2->ProtocolId[87] = v4[6];
      a2 = (struct _SecPkgContext_ApplicationProtocol *)((char *)a2 + 128);
      v6 = v4[7];
      v4 += 8;
      *(_OWORD *)&a2[-1].ProtocolId[239] = v6;
      --v5;
    }
    while ( v5 );
    *(_QWORD *)&a2->ProtoNegoStatus = *(_QWORD *)v4;
  }
  else
  {
    memset_0(a2, 0, sizeof(struct _SecPkgContext_ApplicationProtocol));
  }
  return 0i64;
}
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
