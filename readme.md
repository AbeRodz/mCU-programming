# mCU-programming

***This repo serves for the class of Microcontroller programming at UBA***

## Description
On this repo every project and HW will be uploaded here, as a requirement an STM32F429ZI Nucleo board is needed for testing although currently I do not have a board, so I'll be using QEMU as a temporary solution.

## QEMU
QEMU was setted up on STM32CUBE IDE to quickly verify the code, this has a few caveats:

- In order to run the emulator with a project in STM32CUBE, it is needed to create a new project with a compatible board in this case I chose de STM32F407VG, as currently projects are still simple.
- You have to change on the projects settings the Floating-point ABI to "Sofware" to make it compatible.
- Set up the run configuration by taking in consideration the compatible boards noted in here [xpack.](https://xpack.github.io/blog/2021/10/17/qemu-arm-v2-8-0-13-released/).


## Projects Description

### Project 1
This project was made during class an is actually not relevant.

### Project 2 (tested with QEMU)
***This project was tested on QEMU, check the directory /test_q to check it out***
This project consists in the following:

1. Given a delay struct the following functions need to be implemented :white_check_mark::
    - delayInit
    - delayRead
    - delayWrite

**Check the file on ***practica_2/Src/main.c*** to see the docs for every function.**

2.  After implementing the functions, make a program that uses  non-blocking delays and makes blink an LED of the board. :white_check_mark:

3. [Optional] Implement on the same project a program that makes and LED blink in a periodic way and with 50% work cycle with the following :watch: :
- 5 times at 1s.
- 5 times at 200ms.
- 5 times at 100ms. 

