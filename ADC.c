#include"ADC.h"

void ADC_init()
{
  PINSEL0 |=0x00000000;
	PINSEL1 |=0x04000000;
	PINSEL2 |=0x00000000;	
	AD0CR|=0x00200F04;
	AD0CR|=(1<<16);
}

 unsigned int ADC_read()
{
 	    AD0CR|=(1<<24);
      while(!(AD0DR2&(1<<31)));	    
     	return ((AD0DR2&(0x0000FFC0))>>6);

}