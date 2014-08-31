		ORG		30H
START:	MOV		SP,#60H
		MOV		SCON,#01010000B		;设定串行方式：
									;8位异步，允许接收
		MOV		TMOD,#20H			;设定计数器1为模式2
		ORL		PCON,#10000000B		;波特率加倍
		MOV		TH1,#0F3H			;设定波特率为4800
		MOV		TL1,#0F3H
		SETB	TR1					;计数器1开始计时
AGAIN:
;		JNB		RI,$				;等待接收完成
		CLR		RI					;清接收标志
		MOV		A,#30h				;接收数据送缓冲区
		MOV		SBUF,A				;发送收到的数据
		JNB		TI,$				;等待发送完成
		CLR		TI					;清发送标志
		SJMP	AGAIN
		END