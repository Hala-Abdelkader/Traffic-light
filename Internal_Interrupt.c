/*
 * Internal_Interrupt.c
 *
 * Created: 05/12/2022 21:38:37
 *  Author: hala
 */ 

#include "../../Lib/types.h"
#include "../../Lib/bit.h"
#include "Internal_Interrupt.h"

/*Functions Prototypes*/
void Internal_Interrupt_Enable(void)
{
	SET_BIT(SREG,7);
}

void Internal_Interrupt_Disable(void)
{
	CLR_BIT(SREG,7);
}

