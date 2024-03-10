
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <regex.h>
#include "main.h"

#define DEFAULT_DELAY  100 // default delay constant in milliseconds

/// @brief initiates delay struct.
/// @param delay 
/// @param duration 
void delayInit(delay_t *delay, tick_t duration){
    if (duration <= 0){
        duration = DEFAULT_DELAY;
    }
    delay->duration = duration;
    delay->running = false;
    delay->startTime = 0;
    
}
/// @brief Reads from a delay object the current state of the delay, if it's running or not.
/// @param delay 
/// @retval running state
bool_t delayRead(delay_t *delay){

    uint32_t currentTime = HAL_GetTick();
    bool isRunning = delay->running;
    
    if ((isRunning) && (currentTime - delay->startTime >= delay->duration)){
        delay->running = false;
        return true;
    
    }
    
    delay->running = true;
    delay->startTime = currentTime;
    return  false;    
    

}
/// @brief modifies or writes onto an existing delay object.
/// @param delay 
/// @param duration 
void delayWrite(delay_t *delay,tick_t duration){
    if (duration <= 0){
        duration = DEFAULT_DELAY;
    }
    delay->duration = duration;
}

