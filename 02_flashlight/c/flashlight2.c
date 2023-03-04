#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0
#define buttonPin 1

int ledState = LOW;
int buttonState = HIGH;
int lastBtnState = HIGH;
int tempBtnState;
long lastChangeTime;
long debounceThreshold = 50;

int main(void)
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
		tempBtnState = digitalRead(buttonPin);

		if (tempBtnState != lastBtnState)
		{
			lastChangeTime = millis();
		}

		if (millis() - lastChangeTime >= debounceThreshold)
		{
			if (tempBtnState != buttonState)
			{
				buttonState = tempBtnState;

				if (buttonState == LOW)
				{
					printf("You pressed the button!\n");
					ledState = !ledState;

					if (ledState)
					{
						printf("Turning LED on...\n");
					}
					else
					{
						printf("Turning LED off...\n");
					}
				}
			}
		}

		digitalWrite(ledPin, ledState);
		lastBtnState = tempBtnState;
	}

	return 0;
}
