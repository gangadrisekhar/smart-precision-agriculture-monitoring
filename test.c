#include<lpc21xx.h>
#include"header.h"
#define Pump (1 << 17) 
#define GREEN 0x01
#define YELLOW	0x02
#define RED	 0x04
int main()
{
int flag=0;
//unsigned int adcout;
//float temp_out1,centi;
IODIR0=GREEN|RED|YELLOW|Pump;
IOSET0=GREEN|RED|YELLOW|Pump;
lcd_init();
adc_init();
uart0_init(9600);
uart0_tx_string("*****************************************\n\r");
uart0_tx_string("SMART PRECISION AGRICULTURE SYSTEM       \n\r");
uart0_tx_string("****************************************\n\r");
uart0_tx_string("Controller    :  OK\n\r");
uart0_tx_string("ADC           :  OK\n\r");
uart0_tx_string("UART          :  OK\n\r");
uart0_tx_string("I2C           :  OK\n\r");
uart0_tx_string("SPI           :  OK\n\r");
uart0_tx_string("CAN           :  OK\n\r");
uart0_tx_string("controller    : active\n\r");
uart0_tx_string("initliazation : success\n\r");
lcd_cmd(0x80);
lcd_string("system ready");
lcd_cmd(0xc0);
lcd_string("LPC2129 active");
while(1)
{
  if(flag==0)
  {
  uart0_tx_string("controller     : LPC2119\n\r");
  uart0_tx_string("system status  : running\n\r");
  uart0_tx_string("sensor status  : monotoring\n\r");
  uart0_tx_string("decision Engine: active\n\r");
  uart0_tx_string("decision Engine: active\n\r");
  uart0_tx_string("Pump COntrol   : active\n\r");
  uart0_tx_string("cloud status   : active\n\r");
  lcd_cmd(0x80);
  lcd_string("system running");
  lcd_cmd(0xc0);
  lcd_string("monitoring");
  flag=1;
  
  }
	soil_moisture_sensor();
//LM35_temp_sensor();
	delay_ms(100);
}
}
