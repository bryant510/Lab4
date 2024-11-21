/**
 * @file PWM1_3.c
 *
 * @brief Source file for the PWM1_3 driver.
 *
 * This file contains the function definitions for the PWM1_3 driver.
 * It uses the Module 1 PWM Generator 3 to generate a PWM signal with the PF2 pin.
 *
 * @note This driver assumes that the system clock's frequency is 50 MHz.
 *
 * @note This driver assumes that the PWM_Clock_Init function has been called
 * before calling the PWM1_3_Init function.
 *
 * @author Bryant Cuenca
 */
 
#include "PWM1_3.h"
 
void PWM1_3_Init(uint16_t period_constant, uint16_t duty_cycle)
{	
	// Return from the function if the specified duty_cycle is greater than
	// or equal to the given period. The duty cycle cannot exceed 99%.
	if (duty_cycle >= period_constant) return;
	
	// Enable the clock to PWM MOdule 1 by setting the 
	// R1 bit (Bit 1) in the RCGCPWM register
	SYSCTL->RCGCPWM |= 0x02;
	
	// Enable the clock to GPIO Port F by setting the 
	// R5 bit (Bit 5) in the RCGCPWM register
	SYSCTL->RCGCGPIO |= 0x20;
	
	// Configure the PF2 pin to use the alternate function (M1PWM6)
	//by setting Bit 2 in the AFSEL register
	GPIOF->AFSEL |= 0x04;
	
	// Clear the PMC2 field (Bits 11 to 8) in the PCTL register
	GPIOF->PCTL &= ~0x00000F00;

	// Configure the PF2 pin to operate as a Module 1 PWM6 pin (M1PWM6)
	// by writing 0x5 to the PMC2 field (Bits 11 to 8) in the PCTL register
	// The 0x5 value is derived from Table 23-5 in the TM4C123G Microcontroller Datasheet
	GPIOF->PCTL |= 0x00000500;
	
	// Enable the digital functionality for the PF2 pin
	// by setting Bit 2 in the DEN register
	GPIOF->DEN |= 0x04;
	
	// Disable the Module 1 PWM Generator 3 block (PWM1_3) before
	// configuration by clearing the ENABLE bit (Bit 0) in the PWM3CTL register
	PWM1->_3_CTL &= ~0x01;
	
	// Configure the counter for the PWM1_3 block to
	// use Count-Down mode by clearing the MODE bit (Bit 1)
	// in the PWM3CTL register. The counter will count from the load value
	// to 0, and then wrap back to the load value
	PWM1->_3_CTL &= ~0x02;
	
	// Set the ACTCMPAD field (Bits 7 to 6) to 0x3 in the PWM3GENA register
	// to drive the PWM signal high when the counter matches 
	// the comparator (i.e. the value in PWM3CMPA) while counting down
	PWM1->_3_GENA |= 0xC0;
	
	// Set the ACTLOAD field (Bits 3 to 2) to 0x2 in the PWM3GENA register
	// to drive the PWM signal low when the counter matches the value 
	// in the PWM3LOAD register
	PWM1->_3_GENA |= 0x08;
	
	// Set the period by writing to the LOAD field (Bits 15 to 0)
	// in the PWM3LOAD register. This determines the number of clock
	// cycles needed to count down to zero
	PWM1->_3_LOAD = (period_constant - 1);
		
	// Set the duty cycle by writing to the COMPA field (Bits 15 to 0)
	// in the PWM3CMPA register. When the counter matches the value in this register,
	// the PWM signal will be driven high
	PWM1->_3_CMPA = (duty_cycle - 1);
	
	// Enable the PWM1_3 block after configuration by setting the 
	// ENABLE bit (Bit 0) in the PWM3CTL register
	PWM1->_3_CTL |= 0x01;
	
	// Enable the PWM1_3 signal to be passed to the PF2 pin (M1PWM6)
	// by setting the PWM6EN bit (Bit 6) in the PWMENABLE register
	PWM1->ENABLE |= 0x40;
}

void PWM1_3_Update_Duty_Cycle(uint16_t duty_cycle)
{
	// Set the duty cycle by writing to the COMPA field (Bits 15 to 0)
	// in the PWM3CMPA register. When the counter matches the value in this register, 
	// the PWM signal will be driven high
	PWM1->_3_CMPA = (duty_cycle - 1);
}
