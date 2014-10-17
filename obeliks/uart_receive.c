unsigned char USART_Receive( void )
{
  //ждем пока данные примутся. Для этого смотрим на флаг RXC - Receive Complete в регистре UCSRA
  while ( !(UCSRA & (1<<RXC)) );
  //вытаскиваем принятые данные из буфера
  return UDR;
}
