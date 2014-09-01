
// Resource Table
// Created by IDE, Do not modify this table

.TEXT
.public _RES_Table;
.external __RES_MZ_48K_sa
.public _RES_MZ_48K_SA;
.external __RES_MZ_48K_ea;
.public _RES_MZ_48K_EA;
.external __RES_QJ_48K_sa
.public _RES_QJ_48K_SA;
.external __RES_QJ_48K_ea;
.public _RES_QJ_48K_EA;
.external __RES_DC_48K_sa
.public _RES_DC_48K_SA;
.external __RES_DC_48K_ea;
.public _RES_DC_48K_EA;
.external __RES_ZG_48K_sa
.public _RES_ZG_48K_SA;
.external __RES_ZG_48K_ea;
.public _RES_ZG_48K_EA;
.external __RES_YG_48K_sa
.public _RES_YG_48K_SA;
.external __RES_YG_48K_ea;
.public _RES_YG_48K_EA;
.external __RES_YE_48K_sa
.public _RES_YE_48K_SA;
.external __RES_YE_48K_ea;
.public _RES_YE_48K_EA;
.external __RES_YB_48K_sa
.public _RES_YB_48K_SA;
.external __RES_YB_48K_ea;
.public _RES_YB_48K_EA;
.external __RES_MY_48K_sa
.public _RES_MY_48K_SA;
.external __RES_MY_48K_ea;
.public _RES_MY_48K_EA;
.external __RES_AY_48K_sa
.public _RES_AY_48K_SA;
.external __RES_AY_48K_ea;
.public _RES_AY_48K_EA;
.external __RES_JX_48K_sa
.public _RES_JX_48K_SA;
.external __RES_JX_48K_ea;
.public _RES_JX_48K_EA;
.external __RES_GJG_48K_sa
.public _RES_GJG_48K_SA;
.external __RES_GJG_48K_ea;
.public _RES_GJG_48K_EA;


_RES_Table:

_RES_MZ_48K_SA:
	.DW offset __RES_MZ_48K_sa,seg __RES_MZ_48K_sa;
_RES_MZ_48K_EA:
	.DW offset __RES_MZ_48K_ea,seg __RES_MZ_48K_ea;

_RES_QJ_48K_SA:
	.DW offset __RES_QJ_48K_sa,seg __RES_QJ_48K_sa;
_RES_QJ_48K_EA:
	.DW offset __RES_QJ_48K_ea,seg __RES_QJ_48K_ea;

_RES_DC_48K_SA:
	.DW offset __RES_DC_48K_sa,seg __RES_DC_48K_sa;
_RES_DC_48K_EA:
	.DW offset __RES_DC_48K_ea,seg __RES_DC_48K_ea;

_RES_ZG_48K_SA:
	.DW offset __RES_ZG_48K_sa,seg __RES_ZG_48K_sa;
_RES_ZG_48K_EA:
	.DW offset __RES_ZG_48K_ea,seg __RES_ZG_48K_ea;

_RES_YG_48K_SA:
	.DW offset __RES_YG_48K_sa,seg __RES_YG_48K_sa;
_RES_YG_48K_EA:
	.DW offset __RES_YG_48K_ea,seg __RES_YG_48K_ea;

_RES_YE_48K_SA:
	.DW offset __RES_YE_48K_sa,seg __RES_YE_48K_sa;
_RES_YE_48K_EA:
	.DW offset __RES_YE_48K_ea,seg __RES_YE_48K_ea;

_RES_YB_48K_SA:
	.DW offset __RES_YB_48K_sa,seg __RES_YB_48K_sa;
_RES_YB_48K_EA:
	.DW offset __RES_YB_48K_ea,seg __RES_YB_48K_ea;

_RES_MY_48K_SA:
	.DW offset __RES_MY_48K_sa,seg __RES_MY_48K_sa;
_RES_MY_48K_EA:
	.DW offset __RES_MY_48K_ea,seg __RES_MY_48K_ea;

_RES_AY_48K_SA:
	.DW offset __RES_AY_48K_sa,seg __RES_AY_48K_sa;
_RES_AY_48K_EA:
	.DW offset __RES_AY_48K_ea,seg __RES_AY_48K_ea;

_RES_JX_48K_SA:
	.DW offset __RES_JX_48K_sa,seg __RES_JX_48K_sa;
_RES_JX_48K_EA:
	.DW offset __RES_JX_48K_ea,seg __RES_JX_48K_ea;

_RES_GJG_48K_SA:
	.DW offset __RES_GJG_48K_sa,seg __RES_GJG_48K_sa;
_RES_GJG_48K_EA:
	.DW offset __RES_GJG_48K_ea,seg __RES_GJG_48K_ea;


// End Table
.public T_SACM_S480_SpeechTable
T_SACM_S480_SpeechTable:
	.dw _RES_MZ_48K_SA
	.dw _RES_QJ_48K_SA
	.dw _RES_DC_48K_SA
	.dw _RES_ZG_48K_SA
	.dw _RES_YG_48K_SA
	.dw _RES_YE_48K_SA
	.dw _RES_YB_48K_SA
	.dw _RES_MY_48K_SA
	
	.dw _RES_AY_48K_SA
	.dw _RES_JX_48K_SA
	.dw _RES_GJG_48K_SA
