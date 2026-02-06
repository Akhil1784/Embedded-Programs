#include <stdint.h>
#include "platformTypes.h"

typedef enum { CLK_OFF = 0, CLK_ON = 1 } ClockState_t;

typedef union {
    struct {
        uint8_t clk_pin : 1;
        uint8_t data_pin: 1;
        uint8_t unused  : 6;
    } pins;
    uint8_t raw_byte;
} GPIO_Reg_t;

typedef struct {
    struct {
        uint32_t frequency;
        ClockState_t state;
    } config;             
    GPIO_Reg_t *port;   
} ClockManager_t;

ClockManager_t* GetClockManager(void);