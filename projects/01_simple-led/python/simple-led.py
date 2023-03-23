import RPi.GPIO as GPIO
import time

ledPin = 11


def setup():
    GPIO.setmode(GPIO.BOARD)
    
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.LOW)
    print('Pin #%d set to OUTPUT mode.' % ledPin)


def loop():
    while True:
        print('Turning LED on...')
        GPIO.output(ledPin, GPIO.HIGH)
        time.sleep(1)

        print('Turning LEF off...')
        GPIO.output(ledPin, GPIO.LOW)
        time.sleep(1)


def destroy():
    GPIO.cleanup()


if __name__ == '__main__':
    setup()

    try:
        loop()
    except KeyboardInterrupt:
        destroy()
