
// Resource Table
// Created by IDE, Do not modify this table

.TEXT
.public _RES_Table;
.external __RES_1_A24_sa
.public _RES_1_A24_SA;
.external __RES_1_A24_ea;
.public _RES_1_A24_EA;
.external __RES_2_A24_sa
.public _RES_2_A24_SA;
.external __RES_2_A24_ea;
.public _RES_2_A24_EA;
.external __RES_3_A24_sa
.public _RES_3_A24_SA;
.external __RES_3_A24_ea;
.public _RES_3_A24_EA;


_RES_Table:

_RES_1_A24_SA:
	.DW offset __RES_1_A24_sa,seg __RES_1_A24_sa;
_RES_1_A24_EA:
	.DW offset __RES_1_A24_ea,seg __RES_1_A24_ea;

_RES_2_A24_SA:
	.DW offset __RES_2_A24_sa,seg __RES_2_A24_sa;
_RES_2_A24_EA:
	.DW offset __RES_2_A24_ea,seg __RES_2_A24_ea;

_RES_3_A24_SA:
	.DW offset __RES_3_A24_sa,seg __RES_3_A24_sa;
_RES_3_A24_EA:
	.DW offset __RES_3_A24_ea,seg __RES_3_A24_ea;


// End Table
.PUBLIC _SACM_A1600_SpeechTable
_SACM_A1600_SpeechTable:
	.DW _RES_1_A24_SA
	.DW _RES_2_A24_SA
	.DW _RES_3_A24_SA
