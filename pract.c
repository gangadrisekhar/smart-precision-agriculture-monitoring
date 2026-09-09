#include<lpc21xx.h>

#include "header.h"

int soil,ldr,temp,water;


CAN1 m1;

int main()

{
//i2c_init();
//rtc_init();
//uart0_init(9600);
//rtc_data();
//rtc_print();
//EEPROM_data();
//EEPROM_print();
int flag=0;

//unsigned int adcout;

//float temp_out1,centigrade;

IODIR0=green|red|yellow|pump;

IOSET0=green|red|yellow|pump;

//can1_init();

lcd_init();

adc_init();

//spi0_init();

uart0_init(9600);

	i2c_init();

	rtc_init();

	

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


	soil=Soil_sensor();

	delay_ms(100);
   

	water=Water_sensor();

	delay_ms(100);

	temp=Temp_sensor();

	uart0_tx_string("\n\r");

   delay_ms(100);
	

   Rain();

	delay_ms(100);

    ldr=LDR_sensor();

	delay_ms(100);

	Flame();

	delay_ms(100);

	PIR_sensor();

	delay_ms(100);
	//rtc_init();
	rtc_data();

	 delay_ms(100);

		uart0_tx_string("sending wifi data...r\n");

	wifi();

	delay_ms(100);

	uart0_tx_string("\r\n");




	 //uart0_tx_string("CAN transmiting \r\n");

	 //m1.byteA=soil | (water<<8) | (temp<<16);

//can1_tx(m1);


EEPROM_data();
EEPROM_print();

	 uart0_tx_string("-----------------------\r\n");

	   

	delay_ms(100);


}

}





