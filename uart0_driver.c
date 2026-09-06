#include<lpc21xx.h>
#include"header.h"
#include<string.h>
void uart0_init(unsigned int baud)
{
int pclk,result=0;
if(VPBDIV==0x0)
pclk=15000000;
else if(VPBDIV==0x01)
pclk=60000000;
else if(VPBDIV==0x02)
pclk=30000000;
result=pclk/(16*baud); //baud rate setting
PINSEL0 |= 0x000000005;//selecting tx and rx pin
U0LCR = 0x83;						//unlock the baud rate
U0DLL = (result&0xff);	 // extract lower bits
U0DLM =	 ((result>>8)& 0xff);		//extact higher nibble
U0LCR=0x03;								//lock the baud rate
}
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
 while(RDR==0);			
 return U0RBR;
}
void uart0_tx_string(char *ptr)
{
while(*ptr)
{
uart0_tx(*ptr);
ptr++;
}
}
int uart0_rx_integer(void)
{
int a[20],temp,num,i=0;
while(1)
{
 temp=uart0_rx();
 uart0_tx(temp);
 if(temp==13)
 break;
 a[i]=temp;
 i++;
 }
for(--i,num=0,temp=1;i>=0;i--)
{
if(a[i]=='-')
continue;
num=(a[i]-48)*temp+num;
temp=temp*10;
}
if(a[0]=='-')
num=-num;
return num;
}
						   
 void uart0_tx_integer(int num)
 {
 int a[20],i=0;
 if(num==0)
 {
 uart0_tx('0');
 return;
 }
 if(num<0)
 {
 num=-num;
 uart0_tx('-');
 }
 while(num)
 {
 a[i]=num%10+48;
 num=num/10;
 i++;
 }
 for(--i;i>=0;i--)
 {
 uart0_tx(a[i]);
 }
 }
 void uart0_rx_string(char *s,int size)
 {
 int i=0,temp;
 while(i<size)
 {
 temp=uart0_rx();
 uart0_tx(temp);
 if(temp==13)
 break;
 s[i]=temp;
 i++;
 }
 s[i]=0;
 }
void uart0_float(float f)

{

int num;

if(f==0)

{

uart0_tx_string("0.00");

return;

}

if(f<0)

{

f=-f;

uart0_tx('-');

}

num=f;

uart0_tx_integer(num);

uart0_tx('.');

num=(f-num)*1000000;

uart0_tx_integer(num);

}








 void uart0_strrev(char *s)
 {
 int len=strlen(s);
 int i,j,t;
 for(i=0,j=len-1;i<j;i++,j--)
 {
	 t=s[i];
	 s[i]=s[j];
	 s[j]=t;
	 }
	 }
 void uart0_binary(int num)
 {
 int pos;
 for(pos=7;pos>=0;pos--)
 {
 uart0_tx((num>>pos&1)+48);
 }
 }
void uart0_char_ident(char a)
{
if((a>='a' && a<='z')|| (a>='A' && a<='z'))
uart0_tx_string("alphabet\r\n");
else if(a>='0'&& a<='9')
uart0_tx_string("digit\r\n");
else 
uart0_tx_string("special charter\r\n");
}
























