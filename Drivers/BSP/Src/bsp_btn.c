/*
 * bsp_btn.h
 *
 *  Created on: Oct 18, 2019
 *      Author: INERTIAL ELEMENTS
 *      @BRIEF : THis files contain the higher level function for button input
 */

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "bsp_btn.h"
#include "cpt_btn.h"
#include "SEGGER_RTT.h"


uint32_t bsp_gpio_IntInit(void)
{
	uint32_t errCode;

	errCode = cpt_gpio_BtnInit(BTN_INTERRUPT_ON_OFF);
	NRF_LOG_INFO("err %u\n",errCode);
	return errCode;

}
