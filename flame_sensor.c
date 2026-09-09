#include <lpc21xx.h>

#include "header.h"


/* Flame sensor connected to P0.17 */

#define FLAME_sens  ((IOPIN0 >> 17) & 1)


void Flame(void)

{

    if(FLAME_sens == 1)        // No fire detected

    {

        uart0_tx_string("Flame Status : SAFE\r\n");

        uart0_tx_string("Alarm : OFF\r\n");


        /* Green LED ON */

        IOCLR0 = green;

        IOSET0 = yellow | red;


        /* Buzzer OFF */

        IOCLR0 = BUZZER;


        /* LCD Display */

        lcd_cmd(0x01);

        lcd_cmd(0x80);

        lcd_string("Flame : SAFE");

        lcd_cmd(0xC0);

        lcd_string("Status : NORMAL");

    }

    else                  // Fire detected

    {

        uart0_tx_string("Flame Status : DETECTED\r\n");

        uart0_tx_string("Alarm : ON\r\n");


        /* Red LED ON */

        IOCLR0 = red;

        IOSET0 = green | yellow;


        /* Buzzer ON */

        IOSET0 = BUZZER;


        /* LCD Display */

        lcd_cmd(0x01);

        lcd_cmd(0x80);

        lcd_string("FIRE ALERT!!");

        lcd_cmd(0xC0);

        lcd_string("Check Field");

    }


    uart0_tx_string("-----------------------------------\r\n");


    delay_ms(100);

}
