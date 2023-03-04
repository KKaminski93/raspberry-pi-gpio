import RPi.GPIO as GPIO

ledPin = 11
buttonPin = 12


def setup():
    GPIO.setmode(GPIO.BOARD)

    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.LOW)
    print('Pin #%d set to OUTPUT mode.' % ledPin)

    GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    print('Pin #%d set to INPUT mode (pull-up).' % buttonPin)


def loop():
    while True:
        if GPIO.input(buttonPin) == GPIO.LOW:
            print('Turning LED on...')
            GPIO.output(ledPin, GPIO.HIGH)
        else:
            print('Turning LED on...')
            GPIO.output(ledPin, GPIO.LOW)


def destroy():
    GPIO.output(ledPin, GPIO.LOW)
    GPIO.cleanup()


if __name__ == '__main__':
    setup()

    try:
        loop()
    except KeyboardInterrupt:
        destroy()
