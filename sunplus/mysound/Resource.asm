
// Resource Table
// Created by IDE, Do not modify this table

.TEXT
.public _RES_Table;
.external __RES_2_16K_sa
.public _RES_2_16K_SA;
.external __RES_2_16K_ea;
.public _RES_2_16K_EA;


_RES_Table:

_RES_2_16K_SA:
	.DW offset __RES_2_16K_sa,seg __RES_2_16K_sa;
_RES_2_16K_EA:
	.DW offset __RES_2_16K_ea,seg __RES_2_16K_ea;


// End Table
.public T_SACM_A2000_SpeechTable
T_SACM_A2000_SpeechTable:
	.dw _RES_2_16K_SA;
