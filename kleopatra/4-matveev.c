
#include <avr/io.h>
#include <avr/delay.h>

unsigned int port=0xFFFF;
int i=9;

void next(){
	if (++i>9){
		i=-1;
		port=0xFFFF;
		PORTB=0xFF;
		PORTA|=_BV(PA2) | _BV(PA5);
	}else{
		port&=~_BV(i);
		PORTB=port & 0x00FF;
		PORTA&=((port & 0xFF00) >> 6) | ~(1 << PA2);
		PORTA&=((port & 0xFF00) >> 4) | ~(1 << PA5);
	}
}

int main(void)
{
	DDRB=0xFF;
	DDRA|=_BV(PA2) | _BV(PA5);
	next();
    while(1)
    {
		unsigned char p;
		//ожидание нажатия
		do{
			p=PINA & (1 << PA3);
		}while(p);
		//шаг
		next();
		//игнорируем переходный процесс
		
		_delay_ms(250);
		//ждем пока кнопка не будет отпущена, если она все еще нажата
        do{
			p=PINA & (1 << PA3);
		}while(!p);
		_delay_ms(250);
    }
}
