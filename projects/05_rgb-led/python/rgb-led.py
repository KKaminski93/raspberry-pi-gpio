import RPi.GPIO as GPIO
import time
import random

pins = [11, 12, 13]


def setup():
    global pwmRed, pwmGreen, pwmBlue
    
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(pins, GPIO.OUT)
    GPIO.output(pins, GPIO.HIGH)
    
    pwmRed = GPIO.PWM(pins[0], 2000)
    pwmGreen = GPIO.PWM(pins[1], 2000)
    pwmBlue = GPIO.PWM(pins[2], 2000)
    
    pwmRed.start(0)
    pwmGreen.start(0)
    pwmBlue.start(0)


def setColor(r_val, g_val, b_val):
    pwmRed.ChangeDutyCycle(r_val)
    pwmGreen.ChangeDutyCycle(g_val)
    pwmBlue.ChangeDutyCycle(b_val)


def loop():
    while True:
        r = random.randint(0, 100)
        g = random.randint(0, 100)
        b = random.randint(0, 100)
        
        setColor(r, g, b)
        print('RGB LED Set - (Red: %d%%,  Green:=%d%%,  Blue: %d%%)' % (r, g, b))
        
        time.sleep(1)


def destroy():
    pwmRed.stop()
    pwmGreen.stop()
    pwmBlue.stop()
    
    GPIO.cleanup()


if __name__ == '__main__':
    setup()
    
    try:
        loop()
    except KeyboardInterrupt:
        destroy()
