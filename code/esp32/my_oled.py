from machine import Pin, SoftI2C
import ssd1306
import gfx
from time import sleep

i2c = SoftI2C(scl=Pin(22), sda=Pin(21))

oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)
graphics = gfx.GFX(oled_width, oled_height, oled.pixel)

ldr = 0
temp = 0
hall = 0
motor = "Stop"

def print_data(msg, TOPIC):
    # convert byte array to string
    my_string = msg.decode('utf-8')
    
    global ldr
    global temp
    global hall
    global motor
    
    if TOPIC == 0:
        ldr = my_string
        
    if TOPIC == 1:
        temp = my_string
        
    if TOPIC == 2:
        hall = my_string
    
    if TOPIC == 3:
        if my_string == "0":
            motor = "Forward"
            
        if my_string == "1":
            motor = "Stop"
            
        if my_string == "2":
            motor = "Backward"

    oled.fill(0)
    oled.text("LDR: " + str(ldr), 0, 0)
    oled.text("TEMP: " + str(temp), 0, 10)
    oled.text("HALL: " + str(hall), 0, 20)
    oled.text("MOTOR: " + str(motor), 0, 30)
    
    
    oled.show()


def plot_data(msg):
    
    #oled.fill(0)
    #width 128
    #height 64
    
    my_string = msg.decode('utf-8')
    my_strings = my_string.split(" ")
    my_values = [int(item) for item in my_strings]
    
    if len(my_values) % 2 == 0:
        for ii in range(len(my_values)/2 - 1):
            
            x1 = my_values[0+2*ii]
            y1 = my_values[1+2*ii]
            x2 = my_values[2+2*ii]
            y2 = my_values[3+2*ii]
            
            graphics.line(x1, y1, x2, y2, 1)
            oled.show()
