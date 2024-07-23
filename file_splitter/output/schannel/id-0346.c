// File count: 346
// Total lines: 32
-----------------------------------------
__int64 __fastcall CSslUserContext::PopulateSerialContextState(CSslUserContext *this, struct _SSL_PACKED_CONTEXT *a2)
{
  *(_DWORD *)a2 = *((_DWORD *)this + 2);
  *((_QWORD *)a2 + 1) = *((_QWORD *)this + 2);
  *((_DWORD *)a2 + 4) = *((_DWORD *)this + 6);
  *((_DWORD *)a2 + 5) = *((_DWORD *)this + 14);
  *((_DWORD *)a2 + 6) = *((_DWORD *)this + 15);
  *((_DWORD *)a2 + 7) = *((_DWORD *)this + 7);
  *((_DWORD *)a2 + 8) = *((_DWORD *)this + 16);
  *((_DWORD *)a2 + 9) = *((_DWORD *)this + 18);
  *((_DWORD *)a2 + 38) = *((_DWORD *)this + 17);
  *((_DWORD *)a2 + 10) = *((_DWORD *)this + 49);
  *((_QWORD *)a2 + 6) = *((_QWORD *)this + 12);
  *((_QWORD *)a2 + 7) = *((_QWORD *)this + 13);
  *((_DWORD *)a2 + 44) = *((_DWORD *)this + 29);
  *((_QWORD *)a2 + 20) = *((_QWORD *)this + 15);
  *((_QWORD *)a2 + 21) = *((_QWORD *)this + 16);
  *((_WORD *)a2 + 90) = *((_WORD *)this + 68);
  *((_WORD *)a2 + 91) = *((_WORD *)this + 69);
  *((_DWORD *)a2 + 47) = *((_DWORD *)this + 115);
  *((_BYTE *)a2 + 192) = *((_BYTE *)this + 456);
  *((_BYTE *)a2 + 44) = *((_BYTE *)this + 32);
  *((_DWORD *)a2 + 36) = *((_DWORD *)this + 94);
  *((_DWORD *)a2 + 37) = *((_DWORD *)this + 95);
  *((_DWORD *)a2 + 22) = *((_DWORD *)this + 80);
  memcpy_0((char *)a2 + 92, (char *)this + 324, *((unsigned int *)this + 80));
  *((_DWORD *)a2 + 31) = *((_DWORD *)this + 89);
  memcpy_0((char *)a2 + 128, (char *)this + 360, *((unsigned int *)this + 89));
  *((_QWORD *)a2 + 10) = *((_QWORD *)this + 37);
  return 0i64;
}
