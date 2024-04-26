# Derived from: 
# * https://github.com/peterhinch/micropython-async/blob/master/v3/as_demos/auart.py
# * https://github.com/tve/mqboard/blob/master/mqtt_async/hello-world.py


from mqtt_async import MQTTClient, config
import uasyncio as asyncio
import time
from machine import UART
import my_oled
import logging
logging.basicConfig(level=logging.DEBUG)

MAXTX = 4

# Change the following configs to suit your environment
TOPIC_PUB_l = 'EGR314/Team305/LDR'
TOPIC_SUB_l = 'EGR314/Team305/LDR'
TOPIC_PUB_t = 'EGR314/Team305/TEMP'
TOPIC_SUB_t = 'EGR314/Team305/TEMP'
TOPIC_PUB_h = 'EGR314/Team305/HALL'
TOPIC_SUB_h = 'EGR314/Team305/HALL'
TOPIC_PUB_m = 'EGR314/Team305/MOTOR'
TOPIC_SUB_m = 'EGR314/Team305/MOTOR'

config.server = 'egr3x4.ddns.net' # can also be a hostname
config.ssid     = 'photon'
config.wifi_pw  = 'particle'

uart = UART(2, 9600,tx=17,rx=16)
uart.init(9600, bits=8, parity=None, stop=1,flow=0) # init with given parameters

async def receiver():
    b = b''
    sreader = asyncio.StreamReader(uart)
    while True:
        res = await sreader.read(1)
        if res==b'l':
            await client.publish(TOPIC_PUB_l, b, qos=1)
            print('published', b)
            my_oled.print_data(b, 0)
            b = b''
        elif res==b't':
            await client.publish(TOPIC_PUB_t, b, qos=1)
            print('published', b)
            my_oled.print_data(b, 1)
            b = b''
        elif res==b'h':
            await client.publish(TOPIC_PUB_h, b, qos=1)
            print('published', b)
            my_oled.print_data(b, 2)
            b = b''
        elif res==b'm':
            await client.publish(TOPIC_PUB_m, b, qos=1)
            print('published', b )
            my_oled.print_data(b, 3)
            b = b''
        else:
            b+=res
        

def callback(topic, msg, retained, qos):
    print('callback',topic, msg, retained, qos)
    
    #my_oled.print_data(msg)
    #my_oled.plot_data(msg)
    
    while (not not msg):
        
        uart.write(msg[:MAXTX])
        time.sleep(.01)
        msg = msg[MAXTX:]

    uart.write('\r\n')
    time.sleep(.01)
  
async def conn_callback(client):
    
    """
    await client.subscribe(TOPIC_SUB_l, 1)
    await client.subscribe(TOPIC_SUB_t, 1)
    await client.subscribe(TOPIC_SUB_h, 1)
    await client.subscribe(TOPIC_SUB_m, 1)
    """
    

async def main(client):
    await client.connect()
    asyncio.create_task(receiver())
    while True:
        await asyncio.sleep(1)

config.subs_cb = callback
config.connect_coro = conn_callback

client = MQTTClient(config)
loop = asyncio.get_event_loop()
loop.run_until_complete(main(client))