// File count: 584
// Total lines: 79
-----------------------------------------
int __cdecl _isa_available_init()
{
  int v5; // r11d
  int v6; // r10d
  int v7; // esi
  int v9; // r9d
  int v14; // edi
  int v15; // eax
  unsigned __int64 v16; // rax
  __int64 v17; // rcx
  int v18; // r8d
  int v23; // eax
  char v25; // [rsp+20h] [rbp+8h]

  _RAX = 0i64;
  __asm { cpuid }
  v5 = 0;
  v6 = _RDX;
  v7 = _RAX;
  _RAX = 1i64;
  v9 = _RCX ^ 0x6C65746E | _RBX ^ 0x756E6547;
  __asm { cpuid }
  v14 = _RCX;
  if ( !(v6 ^ 0x49656E69 | v9)
    && ((_memcpy_nt_iters = -1i64, v15 = _RAX & 0xFFF3FF0, v15 == 67264)
     || v15 == 132704
     || v15 == 132720
     || (v16 = (unsigned int)(v15 - 198224), (unsigned int)v16 <= 0x20) && (v17 = 0x100010001i64, _bittest64(&v17, v16))) )
  {
    v18 = _favor | 1;
    _favor |= 1u;
  }
  else
  {
    v18 = _favor;
  }
  _RAX = 7i64;
  if ( v7 >= 7 )
  {
    __asm { cpuid }
    v5 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      _favor = v18 | 2;
  }
  _isa_available = 1;
  _isa_enabled = 2;
  if ( (v14 & 0x100000) != 0 )
  {
    _isa_available = 2;
    _isa_enabled = 6;
    if ( (v14 & 0x8000000) != 0 && (v14 & 0x10000000) != 0 )
    {
      __asm { xgetbv }
      v25 = _RAX;
      if ( (_RAX & 6) == 6 )
      {
        v23 = _isa_enabled | 8;
        _isa_available = 3;
        _isa_enabled |= 8u;
        if ( (v5 & 0x20) != 0 )
        {
          _isa_available = 5;
          _isa_enabled = v23 | 0x20;
          if ( (v5 & 0xD0030000) == -805109760 && (v25 & 0xE0) == 0xE0 )
          {
            _isa_enabled |= 0x40u;
            _isa_available = 6;
          }
        }
      }
    }
  }
  return 0;
}
// 180091980: using guessed type int _isa_available;
// 180091984: using guessed type int _isa_enabled;
// 180091988: using guessed type __int64 _memcpy_nt_iters;
// 180092008: using guessed type int _favor;
