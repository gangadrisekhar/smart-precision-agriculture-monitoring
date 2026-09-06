#include <lpc21xx.h>
#include "header.h"

#define GREEN 0x01
#define YELLOW 0x02
#define RED 0x04
#define Pump (1 << 17) // RElay Connect to P0.17

void soil_moisture_sensor(void)
{
    int adcout, temp;
	//moist;

    adcout = adc_read(0);      // Read sensor
    
		temp = (adcout * 100) / 1023;

    uart0_tx_string("Soil Moisture = ");
    uart0_tx_integer(temp);
    uart0_tx_string("%\r\n");

    if(temp < 30)
		{ 
		  uart0_tx_string("Soil Status : DRY\r\n");
			uart0_tx_string("Pump Status : ON \r\n");
			
			IOCLR0 = YELLOW;
			IOSET0 = GREEN | RED;
			IOCLR0 = Pump;  //  On
			
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("Soil :DRY");
			lcd_cmd(0xC0);
			lcd_string("Pump :ON");
    }
		
		else if(temp < 70)
		{
		  uart0_tx_string("Soil Status : NORMAL\r\n");
		  uart0_tx_string("Pump Status : OFF \r\n");
			
			IOCLR0 = GREEN;
			IOSET0 = YELLOW | RED;
			IOSET0 = Pump; // OFF
			
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("Soil :NORMAL");
			lcd_cmd(0xC0);
			lcd_string("Pump :OFF");
		}
		else
		{
		  uart0_tx_string("Soil Status : WET\r\n");
		  uart0_tx_string("Pump Status : OFF\r\n");
			
			IOCLR0 = GREEN;
			IOSET0 = YELLOW | RED;
			IOSET0 = Pump; // OFF
			
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("Soil :WET");
			lcd_cmd(0xC0);
			lcd_string("Pump :OFF");
		}
		
    uart0_tx_string("-----------------------------------\r\n");

    delay_ms(100);
}
