# -*- coding: utf-8 -*-

import serial
import time

# Settings COM port
SERIAL_DEV = 'COM4'
arduino = serial.Serial(SERIAL_DEV, 9600)
time.sleep(1)
while True:
    print """Варианты: H2-включить 1 светодиод L2- выключить 1 светодиод
             H3-включить 2 светодиод L3- выключить 2 светодиод
             H4-включить 3 светодиод L4- выключить 3 светодиод"""
    outstr = raw_input("Введите комманду: ")
    if (outstr == "H2") or (outstr == "H3") or (outstr == "H4") or (outstr == "L2") or (outstr == "L3") or (outstr == "L4"):
        arduino.write(outstr + '\r')
        time.sleep(0.5)
        print arduino.readline()
    else:
        print "Неверная комманда"
