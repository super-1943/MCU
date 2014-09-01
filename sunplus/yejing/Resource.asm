
// Resource Table
// Created by IDE, Do not modify this table

.TEXT
.public _RES_Table;
.external __RES_WHO_16K_sa
.public _RES_WHO_16K_SA;
.external __RES_WHO_16K_ea;
.public _RES_WHO_16K_EA;
.external __RES_COMEIN_16K_sa
.public _RES_COMEIN_16K_SA;
.external __RES_COMEIN_16K_ea;
.public _RES_COMEIN_16K_EA;
.external __RES_SORRY_16K_sa
.public _RES_SORRY_16K_SA;
.external __RES_SORRY_16K_ea;
.public _RES_SORRY_16K_EA;


_RES_Table:

_RES_WHO_16K_SA:
	.DW offset __RES_WHO_16K_sa,seg __RES_WHO_16K_sa;
_RES_WHO_16K_EA:
	.DW offset __RES_WHO_16K_ea,seg __RES_WHO_16K_ea;

_RES_COMEIN_16K_SA:
	.DW offset __RES_COMEIN_16K_sa,seg __RES_COMEIN_16K_sa;
_RES_COMEIN_16K_EA:
	.DW offset __RES_COMEIN_16K_ea,seg __RES_COMEIN_16K_ea;

_RES_SORRY_16K_SA:
	.DW offset __RES_SORRY_16K_sa,seg __RES_SORRY_16K_sa;
_RES_SORRY_16K_EA:
	.DW offset __RES_SORRY_16K_ea,seg __RES_SORRY_16K_ea;


// End Table
.public T_SACM_A2000_SpeechTable
T_SACM_A2000_SpeechTable:
	.dw _RES_COMEIN_16K_SA;
	.dw _RES_SORRY_16K_SA;
	.dw _RES_WHO_16K_SA;
