/*
 * Running_shadow.c
 *
 * Created: 11.10.2014 10:23:19
 *  Author: Андрей
 */ 
int i=0;

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB=0xFF;
	while(1)
    {
        PORTB|=(1<<i);
		i++;
		if (i==8) i=0;
		_delay_ms(1000);
		
		
    }
}
