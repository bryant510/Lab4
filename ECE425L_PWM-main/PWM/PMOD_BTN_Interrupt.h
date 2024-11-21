/**
 * @file PMOD_BTN_Interrupt.h
 *
 * @brief Header file for the PMOD_BTN_Interrupt driver.
 *
 * This file contains the function definitions for the PMOD_BTN_Interrupt driver.
 * It interfaces with the PMOD BTN module. The following pins are used:
 * 	- BTN0 (PA2)
 *	- BTN1 (PA3)
 *	- BTN2 (PA4)
 *	- BTN3 (PA5)
 *
 * It configures the pins to trigger interrupts on rising edges. The PMOD BTN
 * push buttons operate in an active high configuration.
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"

// Declare pointer to the user-defined task
extern void (*PMOD_BTN_Task)(uint8_t pmod_btn_state);

/**
 * @brief Initializes interrupts for the PMOD BTN module using Port A.
 *
 * This function initializes interrupts for the PMOD BTN module
 * connected to the following pins:
 * 	- BTN0 (PA2)
 *	- BTN1 (PA3)
 *	- BTN2 (PA4)
 *	- BTN3 (PA5)
 *
 * It configures the specified pins to trigger interrupts on rising edges.
 * When an interrupt occurs, the provided task function is executed with the current button status.
 * Interrupt priority is set to 3 for GPIO Port A.
 *
 * @param task A pointer to the user-defined function to be executed upon button interrupts.
 *
 * @return None
 */
void PMOD_BTN_Interrupt_Init(void(*task)(uint8_t));

/**
 * @brief Reads the current status of the PMOD BTN module.
 *
 * This function reads the current status of the PMOD BTN module connected to Port A.
 * It returns the button status as an 8-bit unsigned integer, where each bit represents
 * the state of a specific button.
 *
 * @return An 8-bit unsigned integer representing the status of the PMOD BTN module.
 */
uint8_t PMOD_BTN_Read(void);

/**
 * @brief The interrupt service routine (ISR) for GPIO Port A.
 *
 * This function is the interrupt service routine (ISR) GPIO Port A.
 * It checks if an interrupt has been triggered by the PA5, PA4, PA3, or PA2 pins,
 * and if so, it executes the user-defined task function with the current button status.
 * After executing the task function, it acknowledges and clears the interrupt.
 *
 * @param None
 *
 * @return None
 */
void GPIOA_Handler(void);
