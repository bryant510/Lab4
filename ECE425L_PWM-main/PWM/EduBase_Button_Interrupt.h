/**
 * @file EduBase_Button_Interrupt.h
 *
 * @brief Header file for the EduBase_Button_Interrupt driver.
 *
 * This file contains the function definitions for the EduBase_Button_Interrupt driver.
 * It interfaces with the EduBase Board Push Buttons. The following pins are used:
 *	- SW2 (PD3)
 *	- SW3 (PD2)
 *
 * It configures the pins to trigger interrupts on rising edges. The EduBase Board 
 * push buttons operate in an active high configuration.
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"
#include "GPIO.h"

// Declare a pointer to the user-defined task
extern void (*EduBase_Button_Task)(uint8_t edubase_button_status);

/**
 * @brief Initializes interrupts for the EduBase push buttons using Port D.
 *
 * This function initializes edge-triggered interrupts for the 
 * EduBase push buttons connected to the following pins:
 * 	- SW2 (PD3)
 *	- SW3 (PD2)
 *
 * It configures the specified pins (PD3 and PD2) to trigger interrupts on rising edges.
 * When an interrupt occurs, the provided task function is executed with the current button status.
 * Interrupt priority is set to 3 for GPIO Port D.
 *
 * @param task A pointer to the user-defined function to be executed upon button interrupts.
 *
 * @return None
 */
void EduBase_Button_Interrupt_Init(void(*task)(uint8_t));

/**
 * @brief The interrupt service routine (ISR) for GPIO Port D.
 *
 * This function is the interrupt service routine (ISR) for GPIO Port D.
 * It checks if an interrupt has been triggered by PD3 or PD2, and if so,
 * it executes the user-defined task function with the current button status.
 * After executing the task function, it acknowledges and clears the interrupt.
 *
 * @param None
 *
 * @return None
 */
void GPIOD_Handler(void);
