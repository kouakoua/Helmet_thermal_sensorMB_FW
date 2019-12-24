/*
 * cpt_btn.h
 *
 *  Created on: Oct 18, 2019
 *      Author: MOHIT
 */
#include "nrf_drv_gpiote.h"

#ifndef DRIVERS_CPT_INC_CPT_BTN_H_
#define DRIVERS_CPT_INC_CPT_BTN_H_

/*
 * Use Pin Prt Number as Macros
 * Example:- If GPIO is connected to P0.11 then make Macro 11 to enable tht GPIO*/

#define BTN_INTERRUPT_ON_OFF	29
extern bool start_acc;
extern uint32_t cpt_gpio_BtnInit(uint8_t gpioIntPin);


#endif /* DRIVERS_CPT_INC_CPT_BTN_H_ */
