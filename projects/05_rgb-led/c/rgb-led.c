#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

#define ledPinRed 0
#define ledPinGreen 1
#define ledPinBlue 2

void setupLedPins(void)
{
	softPwmCreate(ledPinRed, 0, 100);
	softPwmCreate(ledPinGreen, 0, 100);
	softPwmCreate(ledPinBlue, 0, 100);
}

void setLedColor(int r, int g, int b)
{
	softPwmWrite(ledPinRed, r);
	softPwmWrite(ledPinGreen, g);
	softPwmWrite(ledPinBlue, b);
}

int main(void)
{
	int r, g, b;

	/* Required to initialize WiringPi */
	wiringPiSetup();

	setupLedPins();

	while (TRUE)
	{
		r = random() % 100;
		g = random() % 100;
		b = random() % 100;
		
		setLedColor(r, g, b);
		printf("RGB LED Set - (Red: %d%%,  Green:=%d%%,  Blue: %d%%) \n", r, g, b);
		
		delay(1000);
	}

	return 0;
}
