#include<lpc21xx.h>
#include"header.h"

#define GREEN 0x01
#define YELLOW 0x02
#define RED 0x04
#define Pump (1 << 17) 

void water_sensor(void)
{
  int adcout, temp;
	
	adcout = adc_read(1);
	
	temp = (adcout * 100)/1023;
	
	uart0_tx_string("Water Level : ");
	uart0_tx_integer(temp);
	uart0_tx_string(" %\r\n");
	
	if(temp < 30)
	{
	  uart0_tx_string("Tank Status : LOW \r\n");
	  uart0_tx_string("Pump Status : ON \r\n");
		
		IOCLR0 = RED;
		IOSET0 = GREEN | YELLOW;
		
		IOCLR0 = Pump;
		
	  lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Water :LOW");
		lcd_cmd(0xC0);
		lcd_string("Pump :OFF");
	}
	
	else if(temp < 70)
	{
	  uart0_tx_string("Tank Status : NORMAL\r\n");
	  uart0_tx_string("Pump Status : READY\r\n");
		
		IOCLR0 = YELLOW;
		IOSET0 = GREEN | RED;
		
		IOCLR0 = Pump;
		 
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Water :NORMAL");
		lcd_cmd(0xC0);
		lcd_string("Pump :READY");
	}
	else
	{
	  uart0_tx_string("Tank Status : FULL\r\n");
	  uart0_tx_string("Pump Status : READY\r\n");
		
		IOCLR0 = GREEN;
		IOSET0 = YELLOW | RED;
		
		IOSET0 = Pump;
		
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Water :FULL");
		lcd_cmd(0xC0);
		lcd_string("Pump :READY");
	}
	
	uart0_tx_string("-----------------------------------\r\n");
	
	delay_ms(100);
}
