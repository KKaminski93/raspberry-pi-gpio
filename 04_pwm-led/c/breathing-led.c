#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define ledPin 1

void main(void)
{
	/* Required to initialize WiringPi */
	wiringPiSetup();

	softPwmCreate(ledPin, 0, 100);

	while (TRUE)
	{
		int i;

		for (i = 0; i < 100; i++)
		{
			softPwmWrite(ledPin, i);
			delay(20);
		}

		delay(300);

		for (i = 100; i >= 0; i--)
		{
			softPwmWrite(ledPin, i);
			delay(20);
		}

		delay(300);
	}
}
