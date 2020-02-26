#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

#include "Initialization.h"

void init_GPIO(){

    INT64S dummy;

    // Enable the GPI0 port that is used for the on-board LEDs and switches.
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    dummy = SYSCTL_RCGC2_R;

    GPIO_PORTF_LOCK_R = 0x4C4F434B;     /* unlock commit register for SW2 */

    GPIO_PORTF_CR_R = 0x01;             /* make PORTF0 configurable */

    // Set the the data direction direction as output (PF1 - PF3). and SW1 and SW2 as input.
    GPIO_PORTF_DIR_R = 0x0E; // (0000 1110), SW1 (PF4) and SW2 (PF0) is input, PF1-3 is output.
                                 //  ---0 ---0  = SW1 (PF4) and SW2 (PF0) = Input (Bit 0 = SW2 , Bit 4 = SW1)
                                 //  ---- 111-  = PF1-PF3 = Input (Bit 1 to 3)

    // Enable the GPIO pins for digital function (PF0 - PF4) (Digital Enable = DEN)
    GPIO_PORTF_DEN_R = 0x1F; // (0001 1111), Enable PF0-PF4 for digital function

    // Enable internal pull-up (PF4). Pull-Up-Resistor = PUR
    GPIO_PORTF_PUR_R = 0x11; // (0001 0001) --> Pullup resistor allways used for inputs.
}
