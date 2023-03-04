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


def onBtnPress(channel):
    global ledState

    print('You pressed the button! (GPIO %d)' % channel)
    ledState = not ledState

    if ledState:
        print('Turning LED on...')
    else:
        print('Turning LED on...')

    GPIO.output(ledPin, ledState)


def loop():
    GPIO.add_event_detect(buttonPin, GPIO.FALLING,
                          callback=onBtnPress, bouncetime=300)

    while True:
        pass


def destroy():
    GPIO.output(ledPin, GPIO.LOW)
    GPIO.cleanup()


if __name__ == '__main__':
    setup()

    try:
        loop()
    except KeyboardInterrupt:
        destroy()
