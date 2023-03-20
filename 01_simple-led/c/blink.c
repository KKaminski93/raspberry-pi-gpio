#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0

void main(void)
{
  /* Required to initialize WiringPi */
  wiringPiSetup();

  pinMode(ledPin, OUTPUT);
  printf("Pin #%d set to OUTPUT mode.\n", ledPin);

  while (TRUE)
  {
    printf("Turning LED on...\n");
    digitalWrite(ledPin, HIGH);
    delay(1000);

    digitalWrite(ledPin, LOW);
    printf("Turning LED off...\n");
    delay(1000);
  }
}
