'''
sudo raspi-config -> Enable SPI
sudo apt update
sudo apt install can-utils
add these lines to boot/config.txt AT THE END OF THE FILE (VERY VERY IMPORTANT)
->
dtparam=spi=on
dtoverlay=mcp2515-can0,oscillator=8000000,interrupt=25
dtoverlay=spi-bcm2835
<-
sudo reboot
sudo ip link set can0 up type can bitrate 500000
ifconfig can0

make sure that can is installed in the raspberry pi and the respective laptop using sudo apt install python3-can

'''

import can
import time

def main():
    # Create CAN bus instance
    bus = can.interface.Bus(channel='can0', bustype='socketcan')

    # First packet: "hello" (5 bytes)
    msg1 = can.Message(arbitration_id=0x123,
                       data=b'hello',
                       is_extended_id=False)
    
    # Second packet: "world" (5 bytes)
    msg2 = can.Message(arbitration_id=0x124,
                       data=b'world',
                       is_extended_id=False)

    try:
        bus.send(msg1)
        print("Sent: hello")
        time.sleep(0.1)  # Short delay
        bus.send(msg2)
        print("Sent: world")

    except can.CanError as e:
        print(f"CAN transmission error: {e}")

if __name__ == "__main__":
    main()
