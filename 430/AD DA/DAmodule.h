#ifndef DA_module_h
#define DA_module_h
void init_DA(void)
{  ADC12CTL0|=REF2_5V+REFON;
  DAC12_0CTL|=DAC12IR+DAC12AMP_5+DAC12ENC;
}
void send_DA(unsigned int data)
{DAC12_0DAT=data;
}
#endif