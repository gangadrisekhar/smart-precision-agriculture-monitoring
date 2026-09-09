#include<lpc21xx.h>
#include "header.h"
void lcd_data(unsigned char data)
{
unsigned int temp;
IOCLR1=0xFE<<16;
temp=(data & 0xF0)<<16;
IOSET1=temp;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
IOCLR1=0xFE<<16;
temp=(data & 0x0F)<<20;
IOSET1=temp;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}

void lcd_cmd(unsigned char cmd)
{
unsigned int temp;
IOCLR1=0xFE<<16;
temp=(cmd & 0xF0)<<16;
IOSET1=temp;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
IOCLR1=0xFE<<16;
temp=(cmd & 0x0F)<<20;
IOSET1=temp;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}

void lcd_init()
{
IODIR1=0xFE<<16;
IOCLR1=1<<19;
lcd_cmd(0x02);
lcd_cmd(0x28);
lcd_cmd(0x0E);
lcd_cmd(0x01);
}

//lcd string function
void lcd_string(const char *p)
{
while(*p!=0)
{
lcd_data(*p++);
}
}
void lcd_integer(int num)
{
int a[20],i;
lcd_init();
if(num==0)
lcd_data('0');
if(num<0)
{
num=-num;
lcd_data('-');
}
while(num>0)
{
a[i]=num%10+'0';
num=num/10;
i++;
}
for(i=i-1;i>=0;i--)
lcd_data(a[i]);
}

void lcd_float(double f)
{
int num;
if(f==0)
lcd_string("0.0");
if(f<0)
{
f=-f;
lcd_data('-');
}
num=f;
lcd_integer(num);
lcd_data('.');
num=(num-f)*1000000;
lcd_integer(num);
}
