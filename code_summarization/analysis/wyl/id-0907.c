//----- (000000018004CA84) ----------------------------------------------------
__int64 __fastcall SslCheckPacForSidFiltering(void *a1, unsigned __int8 **a2, unsigned int *a3)
{
  struct _PACTYPE *v3; // rbx
  unsigned __int8 *v4; // rdi
  unsigned int v5; // r14d
  int v6; // esi
  CCipherMill *v10; // rcx
  unsigned __int64 i; // rdx
  __int64 v12; // rdx
  unsigned int v13; // edx
  struct _PACTYPE *v14; // r8
  __int64 v15; // rcx
  int v17; // eax
  void *v18; // r8
  int updated; // eax
  __int64 v20; // rdx
  int *v21; // rcx
  int v22; // eax
  __int128 v23; // [rsp+30h] [rbp-10h] BYREF
  struct _PACTYPE *v24; // [rsp+88h] [rbp+48h] BYREF
  struct _NETLOGON_VALIDATION_SAM_INFO3 *v25; // [rsp+90h] [rbp+50h] BYREF

  v3 = (struct _PACTYPE *)*a2;
  v4 = 0i64;
  v5 = *a3;
  v6 = 0;
  v25 = 0i64;
  v24 = 0i64;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 10i64, &WPP_30aed76c620c331e1998e7b09f72e2d4_Traceguids);
  if ( !(unsigned int)PAC_UnMarshal((unsigned __int64)v3, v5) )
  {
    v10 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 11i64, &WPP_30aed76c620c331e1998e7b09f72e2d4_Traceguids);
      v10 = WPP_GLOBAL_Control;
    }
    v6 = -2146893047;
    goto LABEL_32;
  }
  v23 = 0i64;
  if ( v3 )
  {
    for ( i = (unsigned __int64)v3 + 8; i < (unsigned __int64)v3 + 16 * *(unsigned int *)v3 + 8; i += 16i64 )
    {
      if ( *(_DWORD *)i == 1 )
      {
        if ( !i )
          break;
        v17 = PAC_UnmarshallValidationInfo(&v25, *(unsigned __int8 **)(i + 8), *(_DWORD *)(i + 4));
        v6 = v17;
        if ( v17 >= 0 )
        {
          v6 = SslFilterSids(a1, v25);
          if ( v6 >= 0 )
          {
            updated = PAC_InitAndUpdateGroupsEx(v25, (struct _SAMPR_PSID_ARRAY *)&v23, v18, v3, &v24);
            v6 = updated;
            if ( updated >= 0 )
            {
              v4 = (unsigned __int8 *)v24;
              v5 = 0;
              if ( v24 )
              {
                v5 = (16 * *(_DWORD *)v24 + 15) & 0xFFFFFFF8;
                if ( *(_DWORD *)v24 )
                {
                  v20 = *(unsigned int *)v24;
                  v21 = (int *)((char *)v24 + 12);
                  do
                  {
                    v22 = *v21;
                    v21 += 4;
                    v5 += (v22 + 7) & 0xFFFFFFF8;
                    --v20;
                  }
                  while ( v20 );
                }
              }
              v3 = v24;
              goto LABEL_18;
            }
            v10 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              WPP_SF_D(
                *((_QWORD *)WPP_GLOBAL_Control + 2),
                15i64,
                &WPP_30aed76c620c331e1998e7b09f72e2d4_Traceguids,
                (unsigned int)updated);
              v4 = (unsigned __int8 *)v24;
              goto LABEL_18;
            }
            v4 = (unsigned __int8 *)v24;
          }
          else
          {
            v10 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
            {
              v12 = 14i64;
              goto LABEL_17;
            }
          }
        }
        else
        {
          v10 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0 )
          {
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              13i64,
              &WPP_30aed76c620c331e1998e7b09f72e2d4_Traceguids,
              (unsigned int)v17);
            goto LABEL_18;
          }
        }
        goto LABEL_19;
      }
    }
  }
  v10 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 2) != 0 )
  {
    v12 = 12i64;
LABEL_17:
    WPP_SF_(*((_QWORD *)v10 + 2), v12, &WPP_30aed76c620c331e1998e7b09f72e2d4_Traceguids);
LABEL_18:
    v10 = WPP_GLOBAL_Control;
  }
LABEL_19:
  if ( v3 )
  {
    v13 = 0;
    if ( *(_DWORD *)v3 )
    {
      v14 = (struct _PACTYPE *)((char *)v3 + v5);
      while ( 1 )
      {
        v15 = 2 * (v13 + 1i64);
        if ( *((_QWORD *)v3 + 2 * v13 + 2) > (unsigned __int64)v14 || v3 > v14 )
          break;
        ++v13;
        *((_QWORD *)v3 + v15) = (unsigned int)(*((_DWORD *)v3 + 2 * v15) - (_DWORD)v3);
        if ( v13 >= *(_DWORD *)v3 )
        {
          v10 = WPP_GLOBAL_Control;
          goto LABEL_26;
        }
      }
      v6 = -2146893047;
    }
    else
    {
LABEL_26:
      if ( !v4 )
        goto LABEL_32;
      if ( *a2 == v4 )
        goto LABEL_30;
      (*(void (__fastcall **)(_QWORD))(LsaTable + 48))(*a2);
      *a2 = v4;
      v4 = 0i64;
      *a3 = v5;
    }
    v10 = WPP_GLOBAL_Control;
  }
LABEL_30:
  if ( v4 )
  {
    (*(void (__fastcall **)(unsigned __int8 *))(LsaTable + 48))(v4);
    v10 = WPP_GLOBAL_Control;
  }
LABEL_32:
  if ( v25 )
  {
    (*(void (__fastcall **)(struct _NETLOGON_VALIDATION_SAM_INFO3 *))(LsaTable + 48))(v25);
    v10 = WPP_GLOBAL_Control;
  }
  if ( v10 != (CCipherMill *)&WPP_GLOBAL_Control && (*((_BYTE *)v10 + 28) & 4) != 0 )
    WPP_SF_D(*((_QWORD *)v10 + 2), 16i64, &WPP_30aed76c620c331e1998e7b09f72e2d4_Traceguids, (unsigned int)v6);
  return (unsigned int)v6;
}
// 18004CD56: variable 'v18' is possibly undefined
// 180041CB0: using guessed type __int64 __fastcall WPP_SF_(_QWORD, _QWORD, _QWORD);
// 180041CDC: using guessed type __int64 __fastcall WPP_SF_D(_QWORD, _QWORD, _QWORD, _QWORD);
// 180092620: using guessed type __int64 LsaTable;
