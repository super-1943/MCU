		ORG		30H
START:	MOV		SP,#60H
		MOV		SCON,#01010000B		;�趨���з�ʽ��
									;8λ�첽���������
		MOV		TMOD,#20H			;�趨������1Ϊģʽ2
		ORL		PCON,#10000000B		;�����ʼӱ�
		MOV		TH1,#0F3H			;�趨������Ϊ4800
		MOV		TL1,#0F3H
		SETB	TR1					;������1��ʼ��ʱ
AGAIN:
;		JNB		RI,$				;�ȴ��������
		CLR		RI					;����ձ�־
		MOV		A,#30h				;���������ͻ�����
		MOV		SBUF,A				;�����յ�������
		JNB		TI,$				;�ȴ��������
		CLR		TI					;�巢�ͱ�־
		SJMP	AGAIN
		END