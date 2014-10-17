void USART_Transmit( unsigned char data )
{
  //ждем, пока освободится буфер. Для этого смотри на флаг UDRE - Data Register Empty в регистре UCSRA
  while ( !( UCSRA & (1<<UDRE)) );
  //записываем данные в буфер, они автоматически отправляются
  UDR = data;
}
