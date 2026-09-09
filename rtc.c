#include <lpc21xx.h>
#include "header.h"

volatile u8 s, m, h, dd, mm, yy;

void rtc_init(void)
{
    // Enable oscillator and set time to 09:08:45
    i2c_write(0xD0, 0x0, 0x15); // Seconds (Bit 7 = 0 starts the clock)
    i2c_write(0xD0, 0x1, 0x05); // Minutes
    i2c_write(0xD0, 0x2, 0x12); // 24 hrs format

    // Set date to 17/08/26
    i2c_write(0xD0, 0x04, 0x18); // Date: 17
    i2c_write(0xD0, 0x05, 0x08); // Month: 08
    i2c_write(0xD0, 0x06, 0x26); // Year: 26
}




void rtc_data(void)
{
   
    // 1. Read RTC registers
    s  = i2c_read(0xD1, 0x0);
    m  = i2c_read(0xD1, 0x1);
    h  = i2c_read(0xD1, 0x2);
    dd = i2c_read(0xD1, 0x4);
    mm = i2c_read(0xD1, 0x5);
    yy = i2c_read(0xD1, 0x6);
}
void rtc_print(){
rtc_data();
    // 2. Print Date: DD/MM/YY
    uart0_tx_string("RTC DATE: ");
    uart0_tx((dd / 16) + '0');
    uart0_tx((dd % 16) + '0');
    uart0_tx('/');
    uart0_tx((mm / 16) + '0');
    uart0_tx((mm % 16) + '0');
    uart0_tx('/');
    uart0_tx((yy / 16) + '0');
    uart0_tx((yy % 16) + '0');
    uart0_tx_string("\r\n");

    // 3. Print Time: HH:MM:SS
    uart0_tx_string("TIME    : ");
	if (h > 0x12){
	u8 hr=h-0x12;
    uart0_tx((hr / 16) + '0');
    uart0_tx((hr % 16) + '0');
	}
	else
	{
	uart0_tx((h / 16) + '0');
    uart0_tx((h % 16) + '0');
	}
    uart0_tx(':');
    uart0_tx((m / 16) + '0');
    uart0_tx((m % 16) + '0');
    uart0_tx(':');
    uart0_tx((s / 16) + '0');
    uart0_tx((s % 16) + '0');

    // 4. Print AM / PM directly
    if (h >= 0x12)
    {
        uart0_tx_string(" PM\r\n");
    }
    else
    {
        uart0_tx_string(" AM\r\n");
    }
} 	




