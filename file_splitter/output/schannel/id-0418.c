// File count: 418
// Total lines: 7
------------------------------------------
void __fastcall PacReadFcn(_DWORD *state, char **pbuffer, unsigned int *psize)
{
  *pbuffer = *(char **)state;
  *(_QWORD *)state += *psize;
  state[2] -= *psize;
}
