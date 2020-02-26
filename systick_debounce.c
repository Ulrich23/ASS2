#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

extern INT64S ticks;

void systick_debounce()
{
	INT16S current_ticks = ticks;
	while (1) {
		if (ticks - current_ticks > 2)
		{
			return;
		}
	}
}

void systick_debounce990ms()
{
	INT16S current_ticks = ticks;
	while (1) {
		if (ticks - current_ticks > 198)
		{
			return;
		}
	}
}

void systick_debounce1000ms()
{
	INT16S current_ticks = ticks;
	while (1) {
		if (ticks - current_ticks > 200)
		{
			return;
		}
	}
}
