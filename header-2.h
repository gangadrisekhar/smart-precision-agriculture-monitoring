#ifndef header_h

#define header_h

#include<lpc21xx.h>


#define green (1<<11)

#define yellow (1<<12)

#define red (1<<13)

#define pump (1 << 15) 

#define BUZZER (1<<14)


typedef unsigned int u32;

typedef signed int s32;

typedef unsigned char u8;

typedef signed char s8;




//uart0_

extern void uart0_init(unsigned int baud);

extern void uart0_tx(unsigned char data);

extern unsigned char uart0_rx(void);

extern void uart0_tx_string(char *ptr);

extern void uart0_tx_integer(int num);

extern void uart0_float(float f);





//ADC

extern void adc_init(void);

extern unsigned int adc_read(unsigned char ch_num);




//delay

extern void delay_sec(unsigned int sec);

extern void delay_ms(unsigned int ms);


//LCD

extern void lcd_data(unsigned char data);

extern void lcd_cmd(unsigned char cmd);

extern void lcd_init(void);

extern void lcd_string(const char *ptr);

extern void lcd_integer(int num);

extern void lcd_float(double f);


//sensors

extern int Temp_sensor(void);

extern int Soil_sensor(void);

extern int Water_sensor(void);

extern void Rain(void);

extern void Flame(void);

extern int LDR_sensor(void);

extern void PIR_sensor(void);


//I2C

extern void i2c_init(void);

extern void i2c_write(u8 sa, u8 mr, u8 data);

extern u8 i2c_read(u8 sa,u8 mr);


//EEPROM

extern void EEPROM_data(void);
extern void EEPROM_print(void);





//WI-FI

extern void wifi(void);

extern void esp_read(void);


//CAN

typedef struct CAN1_MSG{


	u32 id;


	u32 byteA;


	u32 byteB;


	u8 rtr;


	u8 dlc;


	u8 ff;


}CAN1;




extern void can1_tx(CAN1 v);

extern void can1_init(void);

extern void can1_status(void);





//SPI

extern void spi0_init(void);

extern u8 spi0(u8 data);

extern void sd_select(void);

extern void sd_deselect(void);

extern void SDCard_status(void);


//RTC
extern volatile u8 s, m, h, dd, mm, yy;
extern volatile u8 sec,min,hrs,day,month,year;
extern void rtc_init(void);
extern void rtc_data(void);
extern void rtc_print(void);



#endif

