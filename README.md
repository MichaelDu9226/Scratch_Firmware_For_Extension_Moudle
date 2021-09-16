Scratch firmware for extension moudle
==========

Scratch firmware for extension moudle

Tested on Dexarm Extension Moule V1(ESP32 WROVER) & Arduino 1.8.15

![avatar](/image/System_Block.png)


![avatar](/image/Scratch_Demo_For_Dexarm.png)

### Manual installation on Arduino

Install MH_TCS34725&Dexarm_Arduino_Library into Arduino library.

### Guide

- Connect PC to Dexarm Extension Moule V1 PROGRAM PORT with USB A-C cable.
- Connect Dexarm to Dexarm Extension Moule V1 DEXARM PORT1 with USB C-C cable.
- Connect Color sensor to Dexarm Extension Moule V1 PORTA.
- Connect Item detected sensor to Dexarm Extension Moule V1 PORTB.
- Powerup Dexarm.
- Build&Download Scratch_Firmware_For_Extension_Moudle.ino to Dexarm Extension Moule V1.
- Please adjust the position and color sensor threshold as needed.

### Refer link
- https://github.com/Rotrics-Dev/Marlin_For_DexArm/commit/0c9470913b9a58fb58e01bcbc73de92d9367aeeb
