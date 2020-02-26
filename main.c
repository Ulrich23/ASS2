#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

#include "systick.h"
#include "button_ID.h"
#include "display_color.h"
#include "Initialization.h"
#include "light_states.h"
#include "systick_debounce.h"

/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/
extern INT64S ticks;
extern INT64S prev_ticks;

/*****************************   Functions   *******************************/


INT16S main(void)
{
//**********INITIALIZATION**************
	disable_global_int();
	init_systick();
	init_GPIO();
	enable_global_int();
//**************************************

	normal_mode();

	INT64S double_click = 0;
	INT64S double_test = 0;
	while (1)
	{
		while (get_button_id() == 0) {}
		prev_ticks = ticks;
		double_test = ticks - double_click;
		systick_debounce();
		while (get_button_id() != 0) {}
		double_click = ticks;
		systick_debounce();
		if (ticks - prev_ticks > 400)	// Detect long press
		{
			normal_mode();
		}
		else if (double_test < 20)
		{
			emergency_light();
		}
		else
		{
			norwegian_night();
		}
	}
	return 0;
}