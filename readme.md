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
Check the video [here](/assets/) 
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

### Project 3 (tested with QEMU)
***This project was tested on QEMU, check the directory /sim_practica_3 to check it out***
Check the video [here](/assets/) 
This project consists in the following:

1. With the same code made on practica_2, create a folder called API inside Drivers, add an Inc and Src folder with the files API_delay.h and API_delay.c :white_check_mark:

**Check the file on ***practica_3/Drivers/API/API_delay.c*** to see the docs for every function.**


2.  After migrating the folder structure make the leds on the board blink periodically for 200ms each :white_check_mark:

***The Optional bullet point defined on Project 2 was implemented on this project, the code was added on API_delay.***
Now given an array of Leds and their configuration a periodic blinking sequence was implemented for example:

``` C
duty_cycle cycles[3] = {
        {200, 0.5, GPIO_PIN_13,5}, // duration, dutyCycle, led, counter
        {200, 0.5, GPIO_PIN_14,5},
        {200, 0.5, GPIO_PIN_15,1}
    };
```
This defines an array of Leds with their respective configuration. Now we just loop this array to initiate all Leds with the same code created on Project 2, and aftewards we can can loop again to make them blink in a straight-forward way.

This new functionality required a couple of new functions, so the following were added:

``` C
void periodicBlinkInit(delay_t *delays,duty_cycle * duties, size_t numLed); // for initiating every Led given an array
void periodicBlink(delay_t *delays,duty_cycle * duties, size_t numLed, uint32_t counter); // Blinks every Led given an array
```

### Project 4 (tested with NUCLEO board)
***This project was tested on the NUCLEO board, check the directory /practica_4 to check it out***

This project consists in the following:

### Part 1
1. Implement a debounce finite state machine that allows to read the state of the button within the board and generate events with this  :white_check_mark:

### Part 2
1. Implement a module inside the existing API folder from project 3, and create the .h and .c files for API_debounce, and copy the prototypes and implementations of part 1, afterwards implement a new function readKey() to read the internal private variable of the state inside the new module.  :white_check_mark:
2. Implement a program that changes the blinking frequency of the LED from 100ms to 500 ms every time the button is pressed using everything implemented before in debounce and delay. :white_check_mark:

**Check the file on ***practica_4/Drivers/API/*** to see the docs for every function.**


Using the same way I declared an array of leds and their configuration for periodic blinking, I reused this logic and created a similar way:

``` C

duty_cycle cycles[3] = {
		{500, 0.5, LED1}, // duration, dutyCycle, led
		{100, 0.5, LED1},
		{200, 0.5, LED1}
};
```
This way the array contains the target LEDs and their configurations for duration a dutyCycle, we can use this to apply the new config every time an event is done, this required new functionality to integrate from both modules, delay and debounce for that the following function was added:


``` C
void push_to_change_freq(delay_t *delays, duty_cycle *cycles, size_t arrayLength); // given an event, it swaps the current delay with duty cycle given an LED on the LED array
```

The implementation is quite interesting:

``` C
void push_to_change_freq(delay_t *delays, duty_cycle *cycles, size_t arrayLength){
	if ((delays == NULL) || (cycles == NULL)){
		Error_Handler();
	}
    debounceFSM_update(); // button event listener 
	bool_t currentState = readKey(); // button current state

    if (currentState) {

        duty_cycle temp = cycles[0]; // swapping current config for the next config
        for (uint8_t i = 0; i < arrayLength - 1; i++) {
            cycles[i] = cycles[i + 1];
        }
        cycles[arrayLength - 1] = temp;


        for (size_t i = 0; i < arrayLength; i++) { // initiating new config
        	tick_t duration = (tick_t)(cycles[i].duration)*(cycles[i].dutyCycle);
            delayInit(&delays[i], duration );
        }


    }
    blink(&delays[0], &cycles[0]); //blinks with new config

}
```

The current implementation will work for multiple LEDS configured, but it hasn't been tested thoroughly. 