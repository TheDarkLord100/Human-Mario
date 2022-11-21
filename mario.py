import serial
from pynput.keyboard import Key,Controller
import time
keyboard=Controller()

arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)
def A (value):
    print(value)
    if value==b'F on\r\n':
        keyboard.press ('w')
    if value==b'L on\r\n':
        keyboard.press ('a')
        
    if value==b'B on\r\n':
        keyboard.press ('s')
        
    if value==b'R on\r\n':
        keyboard.press ('d')
        
    if value==b'F off\r\n':
        keyboard.release('w')

    if value==b'L off\r\n':
        keyboard.release('a')

    if value==b'B off\r\n':
        keyboard.release('s')

    if value==b'R off\r\n':
        keyboard.release('d')

def write_read():    
    data = arduino.readline()
    return data
while True:
    # Taking input from user
    value = write_read()
    if(value != b''):
        A(value)