#include <lpc21xx.h>

#include "header.h"


/* Rain sensor connected to P0.19 */

#define RAIN_SENS   ((IOPIN0 >> 19) & 1)


void Rain(void)

{

    if(RAIN_SENS == 1)        // No rain

    {

        uart0_tx_string("Rain Status : NO RAIN\r\n");

        uart0_tx_string("Pump Status : READY\r\n");


        /* Green LED ON */

        IOCLR0 = green;

        IOSET0 = yellow | red;


        lcd_cmd(0x01);

        lcd_cmd(0x80);

        lcd_string("Rain : NO");


        lcd_cmd(0xC0);

        lcd_string("Pump : READY");

    }

    else                      // Rain detected

    {

        uart0_tx_string("Rain Status : DETECTED\r\n");

        uart0_tx_string("Pump Status : OFF\r\n");


        /* Yellow LED ON */

        IOCLR0 = yellow;

        IOSET0 = green | red;
	  
	   /* Relay OFF (active LOW relay module) */

        IOSET0 = pump;


        lcd_cmd(0x01);

        lcd_cmd(0x80);

        lcd_string("Rain : YES");


        lcd_cmd(0xC0);

        lcd_string("Pump : OFF");

    }


    uart0_tx_string("-----------------------------------\r\n");


    delay_ms(100);

}

