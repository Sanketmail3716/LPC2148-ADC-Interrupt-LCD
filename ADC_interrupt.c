#include<lpc214x.h>           
#include"PLL.h"
#include"Lcd_4bit.h" 
#include"ADC.h"

void initInterrupt(void);
void ADCISR(void)__irq;
void Delay(unsigned int );    
unsigned int read;
void main (void)
	
{ 
	PLL_SET();
  LCD_Init();
	ADC_init();
	initInterrupt();
	LCD_Command(0x80);
	LCD_string("ADC value :");
    while(1)                
    {		   		
		 display(read);			
		}
}

void Delay(unsigned int time)
{
    int j;
    int i;
    for(i=0;i<time;i++)
    {
        for(j=0;j<60000;j++)
        {
        }
    }
}

void initInterrupt(void)
{
 PINSEL1|=0x00000000;
 VICIntEnable=(1<<18);
 VICVectCntl0=(1<<5)|18 ;
 VICVectAddr0=(unsigned) ADCISR;
 AD0INTEN=(1<<2);
}

void ADCISR(void)__irq
{
  read=((AD0DR2&(0x0000FFC0))>>6);
  VICVectAddr=0x00;
}