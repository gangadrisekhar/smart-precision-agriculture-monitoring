#include <lpc21xx.h>

#include "header.h"


void wifi(void) //p0.0-->txd0,p0.1-->rxd0

{   

    uart0_tx_string("AT\r\n");

    delay_ms(100);


    // Set ESP8266 to Station mode

    uart0_tx_string("AT+CWMODE=1\r\n");

    delay_ms(100);


    // Connect to mobile hotspot

    // Hotspot Name : srinidhi

    // Password     : Sweetysri

    uart0_tx_string("AT+CWJAP=\"srinidhi\",\"Sweetysri\"\r\n");

    delay_ms(100);


    // Get ESP8266 IP address

    uart0_tx_string("AT+CIFSR\r\n");

    delay_ms(100);


    // Connect to ThingSpeak server

    uart0_tx_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");

    delay_ms(100);


    // Send data length

    uart0_tx_string("AT+CIPSEND=101\r\n");

    delay_ms(100);


    // Send HTTP GET request

    uart0_tx_string("GET /update?api_key=P3NMKR3M8JKHDZFJ&field1=30&field2=45 HTTP/1.1\r\n");

    uart0_tx_string("Host: api.thingspeak.com\r\n");

    uart0_tx_string("Connection: close\r\n");

    uart0_tx_string("\r\n");


    delay_ms(100);

		uart0_tx_string("-----------------------------------\r\n");

}




void esp_read(void)

{

    unsigned char ch;


    while(1)

    {

        ch = uart0_rx();

        uart0_tx(ch);

    }

}

