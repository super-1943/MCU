#include "reg52.h"
#include "tft320240.h"

void delay(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=200;i;i--)
	for(j=200;j;j--);
}


void main(void)
{
	tft320240_initial();
	tft320240_clear();
	tft320240_blockwrite(0,239,0,319);
	// Make sure we're disconnected from the upstream port

	while(1) 
	{ // Indefinite loop to handle keyboard scanning


	}
}

