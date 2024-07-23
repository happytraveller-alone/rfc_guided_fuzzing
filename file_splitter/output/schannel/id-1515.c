// File count: 1515
// Total lines: 98
----------------------------------------
__int64 __fastcall _DbgpGetFileVersionString(LPCWSTR lpwstrFilename, __int64 a2, unsigned __int16 *a3)
{
  void *v5; // rdi
  unsigned int v6; // r14d
  DWORD FileVersionInfoSize; // eax
  DWORD v8; // ebx
  PVOID Heap; // rax
  DWORD v10; // ecx
  __int64 v12; // rbx
  __int64 v13; // rcx
  LPVOID lpData; // [rsp+20h] [rbp-E0h]
  DWORD dwHandle; // [rsp+30h] [rbp-D0h] BYREF
  LPVOID lpBuffer; // [rsp+38h] [rbp-C8h] BYREF
  LPVOID Src; // [rsp+40h] [rbp-C0h] BYREF
  wchar_t Buffer[128]; // [rsp+50h] [rbp-B0h] BYREF

  v5 = 0i64;
  v6 = 1;
  FileVersionInfoSize = GetFileVersionInfoSizeExW(1u, lpwstrFilename, &dwHandle);
  v8 = FileVersionInfoSize;
  if ( FileVersionInfoSize )
  {
    Heap = RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, FileVersionInfoSize);
    v5 = Heap;
    if ( !Heap )
    {
      v10 = 14;
LABEL_4:
      SetLastError(v10);
      goto LABEL_5;
    }
    if ( GetFileVersionInfoExW(3u, lpwstrFilename, 0, v8, Heap)
      && VerQueryValueW(v5, L"\\VarFileInfo\\Translation", &lpBuffer, &dwHandle) )
    {
      if ( dwHandle < 2 )
      {
        v10 = 1168;
        goto LABEL_4;
      }
      Buffer[127] = 0;
      LODWORD(lpData) = *(unsigned __int16 *)lpBuffer;
      snwprintf_s(
        Buffer,
        0x80ui64,
        0x7Fui64,
        L"\\StringFileInfo\\%04x%04x\\FileVersion",
        lpData,
        *((unsigned __int16 *)lpBuffer + 1));
      if ( VerQueryValueW(v5, Buffer, &Src, &dwHandle) )
      {
        if ( dwHandle > 0x103 )
        {
          v10 = 122;
          goto LABEL_4;
        }
        v12 = dwHandle;
        memcpy_0(a3, Src, v12 * 2);
        a3[v12] = 0;
        if ( !dwHandle )
          goto LABEL_6;
        v13 = dwHandle;
        while ( 1 )
        {
          if ( *a3 > 0x2Eu )
          {
            if ( *a3 < 0x3Au
              || *a3 > 0x3Bu && *a3 != 63 && (*a3 <= 0x5Au || *a3 > 0x5Eu && (*a3 <= 0x7Au || *a3 > 0x7Du)) )
            {
              goto LABEL_37;
            }
          }
          else if ( *a3 < 0x2Bu
                 && (*a3 < 9u
                  || *a3 > 0xAu
                  && *a3 != 13
                  && (*a3 <= 0x1Fu || *a3 > 0x21u && (*a3 <= 0x23u || *a3 > 0x26u && (*a3 <= 0x27u || *a3 > 0x29u)))) )
          {
            goto LABEL_37;
          }
          *a3 = 95;
LABEL_37:
          ++a3;
          if ( !--v13 )
            goto LABEL_6;
        }
      }
    }
  }
LABEL_5:
  *a3 = 0;
  v6 = 0;
  if ( v5 )
LABEL_6:
    RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v5);
  return v6;
}
// 18007A3AE: variable 'lpData' is possibly undefined
