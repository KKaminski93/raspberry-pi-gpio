#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0
#define buttonPin 1

int ledState = LOW;

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
			digitalWrite(ledPin, HIGH);

			if (ledState == LOW)
			{
				printf("Turning LED on...\n");
				ledState = HIGH;
			}
		}
		else
		{
			digitalWrite(ledPin, LOW);

			if (ledState == HIGH)
			{
				printf("Turning LED off...\n");
				ledState = LOW;
			}
		}
	}
}
