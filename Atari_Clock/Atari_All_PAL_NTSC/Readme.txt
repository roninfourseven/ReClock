Clock output 0 configured as 3.546894MHz PAL Master clock
Clock output 1 4.433618Mhz PAL Colourburst clock
Clock output 2 3.579575 Mhz NTSC Master clock

ATTiny idle light interval 100Ms

The .ino file is for use in the Arduino IDE and can be used as the basis for your own clock projects.

The hex files can be directly programmed to the ATTiny 85 using something like a TL866.

The hex file with the boot loader is included so you can directly program over USB to test your clock works as expected. It shouldn't be used as it introduces a delay at boot time of 5-6 seconds.