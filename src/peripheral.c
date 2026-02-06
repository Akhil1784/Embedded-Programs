#include "peripheral.h"

static GPIO_Reg_t MOCK_PORT = { .raw_byte = 0x00 };

ClockManager_t* GetClockManager(void) {
    static ClockManager_t instance;
    static uint8_t isInit = 0;

    if (!isInit) {
        instance.port = &MOCK_PORT;
        instance.config.frequency = 1000000; // 1MHz
        instance.config.state = CLK_OFF;
        isInit = 1;
    }
    return &instance;
}