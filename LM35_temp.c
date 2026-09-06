#include<lpc21xx.h>
#include"header.h"
#define GREEN 0x01
#define YELLOW 0x02
#define RED 0x04
#define Pump (1 << 17) // RElay Connect to P0.17

void LM35_temp_sensor(void)
{
unsigned int adcout;
float vout,centi;
adcout=adc_read(1);
  vout=(adcout*3.3)/1023;
	centi=(vout-0.5)/(0.01);
	//uart0_float(centi);
if(centi>=20 && centi<=30)
{
IOCLR0=1<<0;
uart0_tx_string("------------------\n\r");
uart0_tx_string("temparature : ");
uart0_tx_integer(centi);
uart0_tx_string(" C\r\n");
uart0_tx_string("status	: NORMAL\n\r");
uart0_tx_string("-----------------------\n\r");
lcd_cmd(0x80);
lcd_string("temp: ");
lcd_integer(centi);
lcd_data('C');
lcd_cmd(0xc0);
lcd_string("status: NORMAL");
}

else if(centi>=31 && centi<=50)
{
IOCLR0=1<<1;
uart0_tx_string("------------------\n\r");
uart0_tx_string("temparature : ");
uart0_tx_integer(centi);
uart0_tx_string(" C\r\n");
uart0_tx_string("status	: HIGH\n\r");
uart0_tx_string("------------------\n\r");
lcd_cmd(0x80);
lcd_string("temp: ");
lcd_integer(centi);
lcd_data('C');
lcd_cmd(0xc0);
lcd_string("status: HIGH");
}
else //if(centi>=0 && centi<=20)
{
IOCLR0=1<<2;
uart0_tx_string("------------------\n\r");
uart0_tx_string("temparature : ");
uart0_tx_integer(centi);
uart0_tx_string(" C\r\n");
uart0_tx_string("status	: LOW\n\r");
uart0_tx_string("------------------\n\r");
lcd_cmd(0x80);
lcd_string("temp: ");
lcd_integer(centi);
lcd_data('C');
lcd_cmd(0xc0);
lcd_string("status: LOW");
}
}
