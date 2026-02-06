#include "peripheral.h"
#include <stdio.h>

int main() {
    ClockManager_t *clk = GetClockManager();
    clk->port->raw_byte |= (1 << 1); 

    printf("Starting Clock Signal Simulation...\n");

    for (int i = 0; i < 4; i++) {
        clk->port->pins.clk_pin = 1;
        printf("Reg: 0x%02X | Clock: HIGH\n", clk->port->raw_byte);
        clk->port->raw_byte &= ~(1 >> 0); 
        printf("Reg: 0x%02X | Clock: LOW\n", clk->port->raw_byte);
    }

    clk->config.state = CLK_ON;
    printf("\nFinal System Freq: %u Hz\n", clk->config.frequency);

    return 0;
}