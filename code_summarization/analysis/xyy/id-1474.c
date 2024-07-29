//----- (0000000180076BA0) ----------------------------------------------------
__int64 __fastcall CSsl3TlsContext::SetPSKExchangeValue(
        CSsl3TlsContext *this,
        unsigned __int8 *a2,
        unsigned int a3,
        int a4)
{
  unsigned int v4; // ebx
  unsigned __int8 *v6; // r14
  unsigned __int16 v7; // di
  unsigned __int16 *v8; // rax

  v4 = 0;
  if ( !a4 && a3 < 2 || a3 == 1 )
    goto LABEL_4;
  if ( a3 < 2 )
    return v4;
  v6 = a2 + 2;
  v7 = _byteswap_ushort(*(_WORD *)a2);
  if ( v7 == a3 - 2 )
  {
    if ( v7 )
    {
      if ( *((_QWORD *)this + 108) )
        (*(void (__fastcall **)(CSsl3TlsContext *))(*(_QWORD *)this + 16i64))(this);
      v8 = (unsigned __int16 *)(*(__int64 (__fastcall **)(CSsl3TlsContext *, _QWORD))(*(_QWORD *)this + 8i64))(
                                 this,
                                 (unsigned int)v7 + 2);
      *((_QWORD *)this + 108) = v8;
      if ( v8 )
      {
        *v8 = v7;
        memcpy_0((void *)(*((_QWORD *)this + 108) + 2i64), v6, v7);
      }
      else
      {
        return 14;
      }
    }
  }
  else
  {
LABEL_4:
    v4 = -2146893048;
    CSslContext::SetErrorAndFatalAlert((__int64)this, 827, -2146893048, 0x32u);
  }
  return v4;
}

