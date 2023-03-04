#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0
#define buttonPin 1

void main(void)
{
	/* Required to initialize WiringPi */
	wiringPiSetup();

	pinMode(ledPin, OUTPUT);
	printf("Pin #%d set to OUTPUT mode.\n", ledPin);

	pinMode(buttonPin, INPUT);
	pullUpDnControl(buttonPin, PUD_UP);
	printf("Pin #%d set to INPUT mode (pull-up).\n", buttonPin);

	while (TRUE)
	{
		if (digitalRead(buttonPin) == LOW)
		{
			printf("Turning LED on...\n");
			digitalWrite(ledPin, HIGH);
		}
		else
		{
			printf("Turning LED off...\n");
			digitalWrite(ledPin, LOW);
		}
	}
}
