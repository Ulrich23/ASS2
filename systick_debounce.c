#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

extern INT64S ticks;

void systick_debounce(INT64S time_value)
{
	INT16S current_ticks = ticks;
	while (1) {
		if (ticks - current_ticks > time_value)
		{
			return;
		}
	}
}
