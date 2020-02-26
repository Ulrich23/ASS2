#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

#include "button_ID.h"
#include "display_color.h"
#include "systick_debounce.h"

extern INT64S ticks;
extern INT64S prev_ticks;


void normal_mode()
{
	while (1)
	{
		ticks = 0;
		while (ticks < 400)
		{
			display_color(RED_EMP);
			if (get_button_id() != 0)
			{
				return;
			}
		}
		while (ticks < 600)
		{
			display_color(REDYELLOW_EMP);
			if (get_button_id() != 0)
			{
				return;
			}
		}
		while (ticks < 1200)
		{
			display_color(GREEN_EMP);
			if (get_button_id() != 0)
			{
				return;
			}
		}
		while (ticks < 1600)
		{
			display_color(YELLOW_EMP);
			if (get_button_id() != 0)
			{
				return;
			}
		}



	}
}

void norwegian_night()
{
	INT16S button = 0;
	while(1)
	{
		if (get_button_id() != 0) { button = 1; }
		display_color(YELLOW_EMP);
		systick_debounce();
		display_color(OFF_EMP);
		systick_debounce990ms();
	}
}

void emergency_light()
{
	display_color(RED_EMP);
}