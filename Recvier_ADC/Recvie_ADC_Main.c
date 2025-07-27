#include<lpc21XX.h>  
#include"Lcd_4bit.h"
#include"UART.h"
#include"PLL.h"

char ADC_DATA[5];
unsigned char RX_DATA;
unsigned int ADC_value_1 = 0;

void Delay(unsigned int );          
void ADC_DATA_Read(char *, unsigned int);
void ADC_data();

void main (void)
{ 
	char Read_result;
	PINSEL0|=0x00000000;
	PINSEL1|=0x00000000;
	PINSEL2|=0x00000000;
		
  UART_init();
	PLL_SET();
  LCD_Init();

	LCD_Command(0x80);
	LCD_string("ADC value1:");
				while(1)                
				{
				 Delay(30);	
			  ADC_data(); 			
				display(ADC_value_1);
       						
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




void ADC_DATA_Read(char *arr, unsigned int length)                          
{
   unsigned int i;
   for(i=0;i<length;i++)
   {  
     *(arr+i)=(UART_Rx()-'0');
   }
   
   ADC_value_1 = (unsigned int)((ADC_DATA[1]*1000)+(ADC_DATA[2]*100)+(ADC_DATA[3]*10+ADC_DATA[4]));
}

void ADC_data()
{
 RX_DATA = UART_Rx();
        if(RX_DATA==':')
        {
            ADC_DATA_Read(ADC_DATA,5);
        }
       
}





