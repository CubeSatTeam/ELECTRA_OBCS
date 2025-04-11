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

'''