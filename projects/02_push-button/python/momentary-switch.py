import RPi.GPIO as GPIO

ledPin = 11
buttonPin = 12
ledState = False


def setup():
    GPIO.setmode(GPIO.BOARD)

    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.LOW)
    print('Pin #%d set to OUTPUT mode.' % ledPin)

    GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    print('Pin #%d set to INPUT mode (pull-up).' % buttonPin)


def loop():
    global ledState

    while True:
        if GPIO.input(buttonPin) == GPIO.LOW:
            GPIO.output(ledPin, GPIO.HIGH)

            if not ledState:
                print('Turning LED on...')
                ledState = True
        else:
            GPIO.output(ledPin, GPIO.LOW)

            if ledState:
                print('Turning LED off...')
                ledState = False


def destroy():
    GPIO.output(ledPin, GPIO.LOW)
    GPIO.cleanup()


if __name__ == '__main__':
    setup()

    try:
        loop()
    except KeyboardInterrupt:
        destroy()
