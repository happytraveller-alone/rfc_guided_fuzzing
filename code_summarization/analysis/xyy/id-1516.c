//----- (000000018007A4A8) ----------------------------------------------------
void __fastcall _DbgpSetExt(unsigned int a1, unsigned __int16 *a2)
{
  *a2 = 46;
  a2[4] = 0;
  a2[3] = a1 % 0xA + 48;
  a2[1] = a1 / 0xA / 0xA % 0xA + 48;
  a2[2] = a1 / 0xA % 0xA + 48;
}
