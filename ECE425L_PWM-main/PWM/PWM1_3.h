/**
 * @file PWM1_3.h
 *
 * @brief Header file for the PWM1_3 driver.
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
 
#include "TM4C123GH6PM.h"

/**
 * @brief Initializes the PWM Module 1 Generator 3 with the specified period and duty cycle.
 *
 * This function initializes the PWM Module 1 Generator 3 with the given period constant and duty cycle.
 * It configures the PF2 pin to operate as a Module 1 PWM6 pin (M1PWM6) to output the PWM signal.
 * period_constant determines the PWM signal's frequency. The specified duty_cycle value must be less 
 * than the period_constant.
 *
 * @param period_constant The period constant for the PWM signal that determines the
 *                        PWM signal's frequency.
 *
 * @param duty_cycle The duty cycle, as a percentage of period_constant, for the PWM signal.
 *                   This value controls pulse width of the PWM signal.
 *
 * @return None
 */
void PWM1_3_Init(uint16_t period_constant, uint16_t duty_cycle);

/**
 * @brief Updates the PWM Module 1 Generator 3 duty cycle for the PWM signal on the PF2 pin (M1PWM6).
 *
 * @param duty_cycle The new duty cycle for the PWM signal on the PF2 pin (M1PWM6).
 *
 * @return None
 */
void PWM1_3_Update_Duty_Cycle(uint16_t duty_cycle);
