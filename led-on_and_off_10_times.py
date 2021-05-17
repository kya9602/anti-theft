import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.OUT)
GPIO.output(4, False)

print("start")
print("----------")

for i in range(0, 10):
    print("ON")
    GPIO.output(4, True)
    time.sleep(0.5)

    print("OFF")
    GPIO.output(4, False)
    time.sleep(0.5)

GPIO.cleanup()
print("------")
print("END")
