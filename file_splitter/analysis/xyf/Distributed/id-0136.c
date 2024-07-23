//----- (000000018000B32C) ----------------------------------------------------
__int64 __fastcall CSslSerializeHelper::DeserializeContext(
        CSslSerializeHelper *this,
        unsigned __int8 *a2,
        int a3,
        struct CSslUserContext **a4)
{
  unsigned int v4; // ebx
  unsigned __int8 *v7; // r8
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // r9d
  unsigned int v11; // ebx
  struct CSslUserContext *UserContext; // rax

  *a4 = 0i64;
  v4 = 0;
  *((_DWORD *)this + 6) = a3;
  v7 = &a2[a3];
  *((_QWORD *)this + 1) = a2;
  while ( 1 )
  {
    if ( a2 + 16 > v7 )
      goto LABEL_11;
    v8 = *((_DWORD *)a2 + 2);
    v9 = *((_DWORD *)a2 + 1);
    if ( v8 > v9 )
      goto LABEL_11;
    v10 = *(_DWORD *)a2;
    if ( !*(_DWORD *)a2 )
      break;
    if ( v10 == 1 )
    {
      if ( v9 < 0xC8 )
        goto LABEL_11;
      v4 = 464;
    }
    else
    {
      if ( v10 <= 1 )
        goto LABEL_18;
      if ( v10 > 3 )
      {
        if ( v10 > 17 )
        {
          if ( v10 > 20 )
          {
LABEL_18:
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_d(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                0xBu,
                (__int64)&WPP_3fd35671b5b538c236a2a452323fc10e_Traceguids,
                v10);
            }
LABEL_11:
            v11 = -2146893052;
            goto LABEL_22;
          }
        }
        else
        {
          v4 += (v8 + 7) & 0xFFFFFFF8;
        }
      }
    }
    a2 += v9 + 16;
  }
  UserContext = CreateUserContext(v4);
  *a4 = UserContext;
  if ( UserContext )
  {
    v11 = CSslSerializeHelper::DeserializeContextWorker(this, UserContext);
    if ( !v11 )
      return v11;
  }
  else
  {
    v11 = -2146893056;
  }
LABEL_22:
  if ( *a4 )
    DeleteUserContext(*a4);
  return v11;
}

