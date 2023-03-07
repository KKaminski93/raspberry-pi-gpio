#include <wiringPi.h>
#include <stdio.h>

#define numLeds 10

int ledPins[numLeds] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10};

void main(void)
{
	int i;

	/* Required to initialize WiringPi */
	wiringPiSetup();

	for (i = 0; i < numLeds; i++)
	{
		pinMode(ledPins[i], OUTPUT);
		printf("Pin #%d set to OUTPUT mode.\n", ledPins[i]);
	}

	while (TRUE)
	{
		for (i = 0; i < numLeds; i++)
		{
			digitalWrite(ledPins[i], LOW);
			delay(100);
			digitalWrite(ledPins[i], HIGH);
		}

		for (i = numLeds - 1; i > -1; i--)
		{
			digitalWrite(ledPins[i], LOW);
			delay(100);
			digitalWrite(ledPins[i], HIGH);
		}
	}
}
