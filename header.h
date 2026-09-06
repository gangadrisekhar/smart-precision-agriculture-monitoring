#include<lpc21xx.h>
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
extern void lcd_string(char *ptr);
extern void lcd_integer(int num);
extern void lcd_float(double f);

//sensors
extern void LM35_temp_sensor(void);
extern void soil_moisture_sensor(void);
extern void water_sensor(void);


