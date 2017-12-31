void usart_t_init(void)
{
  UCSR0B=(1<<TXEN0);
  UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
  UBRR0=0X33;
}

void usart_r_init(void)
{
  UCSR0B=(1<<RXEN0);
  UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
  UBRR0=0X33;
}


void usart_reset(void)
{
  UCSR0B &= ~(1<<RXEN0);
  UCSR0B &= ~(1<<TXEN0);
  }

char usart_recieve()
{
  
  while(UCSR0A&(1<<UDRE0));
  return UDR0;

}

void usart_send(char ch)
{
  while(!UCSR0A&(1<<UDRE0));
  UDR0=ch;
}

void setup() {
  // put your setup code here, to run once:
usart_r_init();
usart_t_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  usart_send('k');

char ch =usart_recieve();

usart_reset();
}
