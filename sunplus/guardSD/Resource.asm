
// Resource Table
// Created by IDE, Do not modify this table

.TEXT
.public _RES_Table;
.external __RES_1_48K_sa
.public _RES_1_48K_SA;
.external __RES_1_48K_ea;
.public _RES_1_48K_EA;
.external __RES_12_48K_sa
.public _RES_12_48K_SA;
.external __RES_12_48K_ea;
.public _RES_12_48K_EA;
.external __RES_15_48K_sa
.public _RES_15_48K_SA;
.external __RES_15_48K_ea;
.public _RES_15_48K_EA;
.external __RES_2_48K_sa
.public _RES_2_48K_SA;
.external __RES_2_48K_ea;
.public _RES_2_48K_EA;
.external __RES_3_48K_sa
.public _RES_3_48K_SA;
.external __RES_3_48K_ea;
.public _RES_3_48K_EA;
.external __RES_7_48K_sa
.public _RES_7_48K_SA;
.external __RES_7_48K_ea;
.public _RES_7_48K_EA;
.external __RES_6_48K_sa
.public _RES_6_48K_SA;
.external __RES_6_48K_ea;
.public _RES_6_48K_EA;
.external __RES_5_48K_sa
.public _RES_5_48K_SA;
.external __RES_5_48K_ea;
.public _RES_5_48K_EA;
.external __RES_18_48K_sa
.public _RES_18_48K_SA;
.external __RES_18_48K_ea;
.public _RES_18_48K_EA;
.external __RES_17_48K_sa
.public _RES_17_48K_SA;
.external __RES_17_48K_ea;
.public _RES_17_48K_EA;
.external __RES_16_48K_sa
.public _RES_16_48K_SA;
.external __RES_16_48K_ea;
.public _RES_16_48K_EA;
.external __RES_4_48K_sa
.public _RES_4_48K_SA;
.external __RES_4_48K_ea;
.public _RES_4_48K_EA;
.external __RES_4COM_48K_sa
.public _RES_4COM_48K_SA;
.external __RES_4COM_48K_ea;
.public _RES_4COM_48K_EA;
.external __RES_3COM_48K_sa
.public _RES_3COM_48K_SA;
.external __RES_3COM_48K_ea;
.public _RES_3COM_48K_EA;


_RES_Table:

_RES_1_48K_SA:
	.DW offset __RES_1_48K_sa,seg __RES_1_48K_sa;
_RES_1_48K_EA:
	.DW offset __RES_1_48K_ea,seg __RES_1_48K_ea;

_RES_12_48K_SA:
	.DW offset __RES_12_48K_sa,seg __RES_12_48K_sa;
_RES_12_48K_EA:
	.DW offset __RES_12_48K_ea,seg __RES_12_48K_ea;

_RES_15_48K_SA:
	.DW offset __RES_15_48K_sa,seg __RES_15_48K_sa;
_RES_15_48K_EA:
	.DW offset __RES_15_48K_ea,seg __RES_15_48K_ea;

_RES_2_48K_SA:
	.DW offset __RES_2_48K_sa,seg __RES_2_48K_sa;
_RES_2_48K_EA:
	.DW offset __RES_2_48K_ea,seg __RES_2_48K_ea;

_RES_3_48K_SA:
	.DW offset __RES_3_48K_sa,seg __RES_3_48K_sa;
_RES_3_48K_EA:
	.DW offset __RES_3_48K_ea,seg __RES_3_48K_ea;

_RES_7_48K_SA:
	.DW offset __RES_7_48K_sa,seg __RES_7_48K_sa;
_RES_7_48K_EA:
	.DW offset __RES_7_48K_ea,seg __RES_7_48K_ea;

_RES_6_48K_SA:
	.DW offset __RES_6_48K_sa,seg __RES_6_48K_sa;
_RES_6_48K_EA:
	.DW offset __RES_6_48K_ea,seg __RES_6_48K_ea;

_RES_5_48K_SA:
	.DW offset __RES_5_48K_sa,seg __RES_5_48K_sa;
_RES_5_48K_EA:
	.DW offset __RES_5_48K_ea,seg __RES_5_48K_ea;

_RES_18_48K_SA:
	.DW offset __RES_18_48K_sa,seg __RES_18_48K_sa;
_RES_18_48K_EA:
	.DW offset __RES_18_48K_ea,seg __RES_18_48K_ea;

_RES_17_48K_SA:
	.DW offset __RES_17_48K_sa,seg __RES_17_48K_sa;
_RES_17_48K_EA:
	.DW offset __RES_17_48K_ea,seg __RES_17_48K_ea;

_RES_16_48K_SA:
	.DW offset __RES_16_48K_sa,seg __RES_16_48K_sa;
_RES_16_48K_EA:
	.DW offset __RES_16_48K_ea,seg __RES_16_48K_ea;

_RES_4_48K_SA:
	.DW offset __RES_4_48K_sa,seg __RES_4_48K_sa;
_RES_4_48K_EA:
	.DW offset __RES_4_48K_ea,seg __RES_4_48K_ea;

_RES_4COM_48K_SA:
	.DW offset __RES_4COM_48K_sa,seg __RES_4COM_48K_sa;
_RES_4COM_48K_EA:
	.DW offset __RES_4COM_48K_ea,seg __RES_4COM_48K_ea;

_RES_3COM_48K_SA:
	.DW offset __RES_3COM_48K_sa,seg __RES_3COM_48K_sa;
_RES_3COM_48K_EA:
	.DW offset __RES_3COM_48K_ea,seg __RES_3COM_48K_ea;


// End Table
.PUBLIC T_SACM_S480_SpeechTable
T_SACM_S480_SpeechTable:
.DW _RES_1_48K_SA//0
.DW _RES_2_48K_SA//1
.DW _RES_3_48K_SA//2
.DW _RES_4_48K_SA//3
.DW _RES_5_48K_SA//4
.DW _RES_6_48K_SA//5
.DW _RES_7_48K_SA//6
.DW _RES_18_48K_SA//7
//.DW _RES_11_48K_SA
//.DW _RES_10_48K_SA
.DW _RES_12_48K_SA//8
.DW _RES_17_48K_SA//9
.DW _RES_16_48K_SA//10
.DW _RES_15_48K_SA//11
.DW _RES_3COM_48K_SA//12
.DW _RES_4COM_48K_SA//13
//.DW _RES_RED_ON_48K_SA//8
//.DW _RES_RED_OFF_48K_SA//9
//.DW _RES_GRE_ON_48K_SA//
//.DW _RES_GRE_OFF_48K_SA
.PUBLIC T_SACM_A2000_SpeechTable
T_SACM_A2000_SpeechTable:
