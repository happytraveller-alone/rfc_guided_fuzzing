//----- (0000000180062884) ----------------------------------------------------
void __fastcall CSsl3TlsServerContext::GenerateNewSessionTicket(
        CSsl3TlsServerContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned int *a5)
{
  unsigned __int8 v5; // r10
  size_t v7; // rsi
  int v10; // r14d
  unsigned int v11; // ebp
  unsigned __int8 *v12; // rcx
  __int16 v13; // [rsp+20h] [rbp-28h]

  v5 = *((_BYTE *)this + 233);
  v7 = a3;
  v10 = a3 + 10 + (v5 != 0 ? 8 : 0);
  v13 = *((_WORD *)this + 110);
  v11 = CSslGlobals::m_dwSessionTicketLifespan / 0x3E8;
  *((_WORD *)this + 110) = v13 + 1;
  SetHandshakeHeader((__int64)a4, 4, 0i64, v10 - (v5 != 0 ? 12 : 4), v13, v5);
  if ( *((_BYTE *)this + 233) )
  {
    a4[13] = BYTE2(v11);
    v12 = a4 + 18;
    a4[12] = HIBYTE(v11);
    a4[14] = BYTE1(v11);
    a4[15] = v11;
    a4[16] = BYTE1(v7);
    a4[17] = v7;
  }
  else
  {
    a4[5] = BYTE2(v11);
    v12 = a4 + 10;
    a4[4] = HIBYTE(v11);
    a4[6] = BYTE1(v11);
    a4[7] = v11;
    a4[8] = BYTE1(v7);
    a4[9] = v7;
  }
  memcpy_0(v12, a2, v7);
  *a5 = v10;
}

