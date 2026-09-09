#include<lpc21xx.h>
#include "header.h"
volatile u8  sec,min,hrs,day,month,year;
void EEPROM_data(void)
{
//i2c_write
rtc_data();
i2c_write(0xA0,0x02,sec);
delay_ms(10);
i2c_write(0xA0,0x03,min);
delay_ms(10);
i2c_write(0xA0,0x04,hrs);
delay_ms(10);
//////////////////////
i2c_write(0xA2,0x02,day);
delay_ms(10);
i2c_write(0xA2,0x03,month);
delay_ms(10);
i2c_write(0xA2,0x04,year);
delay_ms(10);
}

void EEPROM_print(){
//u8 sec,min,hrs,day,month,year;
sec=i2c_read(0xA1,0x02);
min=i2c_read(0xA1,0x03);
hrs=i2c_read(0xA1,0x04);
//////////////////////
day=i2c_read(0xA3,0x02);
month=i2c_read(0xA3,0x03);
year=i2c_read(0xA3,0x04);
uart0_tx_string("EEPROM DATE: ");
    uart0_tx((day / 16) + '0');
    uart0_tx((day % 16) + '0');
    uart0_tx('/');
    uart0_tx((month / 16) + '0');
    uart0_tx((month % 16) + '0');
    uart0_tx('/');
    uart0_tx((year / 16) + '0');
    uart0_tx((year % 16) + '0');
    uart0_tx_string("\r\n");

    // 3. Print Time: HH:MM:SS
    uart0_tx_string("EEPROM TIME    : ");
	if (hrs > 0x12){
	u8 hr=hrs-0x12;
    uart0_tx((hr / 16) + '0');
    uart0_tx((hr % 16) + '0');
	}
	else
	{
	uart0_tx((hrs / 16) + '0');
    uart0_tx((hrs % 16) + '0');
	}
    uart0_tx(':');
    uart0_tx((min / 16) + '0');
    uart0_tx((min % 16) + '0');
    uart0_tx(':');
    uart0_tx((sec / 16) + '0');
    uart0_tx((sec % 16) + '0');

    // 4. Print AM / PM directly
    if (hrs >= 0x12)
    {
        uart0_tx_string(" PM\r\n");
    }
    else
    {
        uart0_tx_string(" AM\r\n");
    }
}
/*
//read data

temp=i2c_read(0xA1,0x02);

if(temp==rtc_data())

{

//strcpy(EEPROM_status,"DATA SAVED");

uart0_tx_string("EEPROM_status: DATA SAVED\r\n");

uart0_tx_string("\n\r");

IOCLR0=green;

IOSET0=yellow| red;

}

else

{

 //strcpy(EEPROM_status,"WRITE FAIL");

 uart0_tx_string("EEPROM_status: WRITE FAIL\r\n");

 uart0_tx_string("\n\r");

		 IOCLR0=red;

IOSET0=yellow|green;


}

} */


