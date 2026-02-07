# ReClock

ReClock is a small project to utilise an Si5351 based clock generator board in conjunction with an ATTiny 85 microcontroller to generate clocks for systems where crystals are missing and replacements are difficult to find.
Specifically this project started to replace the following Atari crystals:

1. 3.546894 MHz - PAL main system clock frequency
2. 4.433618 Mhz - PAL colourburst clock frequency
3. 3.579575 Mhz - NTSC main system clock frequency

Item 1 on the list is now very hard to find in the UK and whilst it is available in the US, specifically Best Electronics has them, shipping makes the price quite expensive so I wanted to see if there was an alternative.

Items 2 & 3 are very easy to obtain, however the Si5351 has 3 outputs so it made sense to just add in the other Atari clocks.

Of course the Si5351 can output clocks anywhere between 8Khz and 160Mhz so this is not limited to just Atari machines and theoretically could replace clock crystals in many systems.

Please note that this is a clock replacement not a crystal replacement, so it is important to understand that in your chosen system, the Si5351 clock output needs to be connected in place of entire original clock circuit, which may need
to be disabled to prevent interference with the new clock. Do not connect it in place of the crystal, it won't work.

Parts cost is intended to be minimal and the price of building one of these flexible clock generators should be less than £10 unless you opt for a board with Stemm QT connectors, which will make the cost just above £10 as it is slightly 
more expensive.

Costs and links to suggested items will be dealt with separately to this readme.
