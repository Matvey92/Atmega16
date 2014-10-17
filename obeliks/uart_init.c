#define FOSC 8000000			        // частота клока
#define BAUD 9600				          //бодрейт юарта
#define MYUBRR FOSC/16/BAUD-1	    //бодрейт, который запишем в UBRR 
                                  //(для 8Мгц и 9600 в даташите 51 с ошибкой 0,2 %)
void main( void )
{
	//инициализация юарт
	USART_Init ( MYUBRR );
}


void USART_Init( unsigned int ubrr)
{
	// Установка бодрейта производится в двух регистрах
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	// Разрешить работу приемника и педедатчика
	UCSRB = (1<<RXEN)|(1<<TXEN);
	// Установить формат посылки: 1 стоп бит, 8 информационных бит */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}
