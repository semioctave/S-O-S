# S-O-S

![sosl](https://user-images.githubusercontent.com/34485667/34904403-25b73320-f86b-11e7-9268-2defac264929.jpg)

___
## Introduction & Overview

Designing Traffic light controller using <b>TM4C123 Tiva C Series LAUNCHPAD</b> an<b> ARM Cortex M4 based MCU</b>
from Scratch in C using Industrial Tool <b> ARM Keil </b>. ARM Cortex M4 Processor is used in modern Embedded Devices like
fitness bands & other Automative applications. <b>ARM Cortex M series</b> processors are of great importance to modern day Embedded industry. 

___

## Hardware Components used

1. TM4C123 Tiva C Series Launchpad.
2. Resistors.
3. LED
4. Switches

___

## Software tool Used

I used ARM Keil IDE to write code , compile & Burn the code.
One may use other Embedded Designing Tools like <b>IAR Embedded Benchmark</b> or <b>TI Code Compose Studio</b>

### Links for downloading the Tools

1. [ARM Keil](http://www2.keil.com/mdk5/)
2. [IAR Embedded Benchmark](https://www.iar.com/iar-embedded-workbench/)
3. [TI Code Compose Studio](http://www.ti.com/tool/CCSTUDIO)

___

## Working   

<b> SOS </b>is SOS is the International Morse code distress signal <b>(...___...) </b> <br/>.
A distress signal or distress call is an internationally recognized means for obtaining help. Distress signals are communicated by transmitting radio signals, displaying a visually observable item or illumination, or making a sound audible from a distance.
The SOS distress signal is a continuous sequence of three dots, three dashes, and three dots, with no spaces between the letters.

Circuit consists of a ARM MCU to Generate SOS signal and a Switch to start Signal generation
Further, Signal obtained At the Port can be Amplified using Suitable Amplifier Circuit(POWER AMP), but for testing and prototyping Purposes one can observe o/p using LED.

System is Generatly used in Ships 

___

## Deployment of Machine

First of all Make a new project and add <b>Startup.s </b>file to your project or the startupfile provided by your tool for yours praticular processor Model. Now add <b>main.c</b> file , main.c file consists of main C code of your Machine now <b>compile and debug</b> your
code using your Embedded Designing Tool. After Succesful Debugging Burn the code onto your Machine and your Prototype is ready to use
