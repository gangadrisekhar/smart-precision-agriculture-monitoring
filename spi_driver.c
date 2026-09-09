#include <lpc21xx.h>

#include "header.h"

#define SPIF ((S0SPSR>>7)&1)

#define SD_CS (1 << 7) // P0.7 Chip Select


void spi0_init(void)

{

    PINSEL0 |= 0x00001500; // Configure P0.4 (SCK), P0.5 (MISO), P0.6 (MOSI)

    IODIR0  |= SD_CS;      // Set CS as Output

    IOSET0   = SD_CS;      // Deselect SD Card

    

	  S0SPCR  = 0x20;       // Master mode, 8-bit, MSB first, POL=0, PHA=0;

    S0SPCCR = 15;          // SPI Clock counter (Must be even, >= 8)

}


u8 spi0(u8 data)

{

    S0SPDR = data;

    while (SPIF==0); // Wait for SPIF flag

    return S0SPDR;

}


void sd_select(void)

{

    IOCLR0 = SD_CS;

}


/* SD Card Deselect */

void sd_deselect(void)

{

    IOSET0 = SD_CS;

}


/*void SDCard_status(void)

{
    uart0_tx_string("SD Card : Mounted\r\n");

    uart0_tx_string("Log File : Updated\r\n");

} */
