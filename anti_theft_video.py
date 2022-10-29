from picamera import PiCamera
from time import sleep
import serial
import datetime

camera = PiCamera()


if __name__ == '__main__':
	ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
	ser.flush()
	while True:
		if ser.in_waiting > 0:
			line = ser.readline().decode('utf-8').rstrip()
			print(line)
			line = float(line)
			if line:
				camera.start_preview()
				sleep(0.001)
				saveFileName=datetime.datetime.now().strftime('%y%m%d%H%M%S%f')+'.h264'
				camera.start_recording('/home/pi/anti-theft/videos/' +saveFileName)
				sleep(10)
				camera.stop_recording()
				camera.stop_preview()
