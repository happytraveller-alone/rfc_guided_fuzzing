//----- (000000018000AD34) ----------------------------------------------------
__int64 __fastcall CSchannelTelemetryContext::LogTlsExtensionTelemetry(__int64 a1, int a2, int a3)
{
  char v3; // r9
  int v4; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d
  int v8; // r8d
  int v9; // r8d
  int v10; // r8d
  int v11; // r8d
  __int64 result; // rax

  v3 = a3;
  if ( a1 && CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized )
  {
    v4 = a3 - 10;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        v6 = v5 - 2;
        if ( v6 )
        {
          v7 = v6 - 1;
          if ( v7 )
          {
            v8 = v7 - 2;
            if ( v8 )
            {
              v9 = v8 - 7;
              if ( v9 )
              {
                v10 = v9 - 1;
                if ( v10 )
                {
                  v11 = v10 - 11;
                  if ( v11 )
                  {
                    if ( v11 == 65246 )
                      v3 = 16;
                  }
                  else
                  {
                    v3 = 13;
                  }
                }
                else
                {
                  v3 = 15;
                }
              }
              else
              {
                v3 = 12;
              }
            }
            else
            {
              v3 = 11;
            }
          }
          else
          {
            v3 = 10;
          }
        }
        else
        {
          v3 = 9;
        }
      }
      else
      {
        v3 = 8;
      }
    }
    else
    {
      v3 = 7;
    }
    result = 1i64;
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        result = (unsigned int)(1 << v3);
        *(_DWORD *)(a1 + 72) |= result;
      }
    }
    else
    {
      result = (unsigned int)(1 << v3);
      *(_DWORD *)(a1 + 68) |= result;
    }
  }
  return result;
}
// 1800927AC: using guessed type bool CSchannelTelemetryContext::m_bTelemetryIsGloballyInitialized;

