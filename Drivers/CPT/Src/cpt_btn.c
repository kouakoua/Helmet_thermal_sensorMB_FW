/*
 * cpt_btn.c
 *
 *  Created on: Oct 18, 2019
 *      Author: INERTIAL ELEMENTS
 *      @BRIEF : Converting the gpios into required button input
 */
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "cpt_btn.h"
#include <stdio.h>
#include <stdbool.h>
#include "ble_interface.h"
#include "nrf_nvic.h"
bool start_ble;
bool start_acc;
bool g_state;

void in_pin_BtnHandler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
	//Event handler for the GPIOs when any gpio toggle is detected
    switch(action)
    {
        case NRF_GPIOTE_POLARITY_TOGGLE:
        	NRF_LOG_INFO("btn");
        	if(g_state ==false)
        	   g_state =true;
        	  else
        	   g_state = false;

        	if(pin == BTN_INTERRUPT_ON_OFF)
        	{

        		if (timer>3)
        		{
        			if(start_ble==true)
        			{
        			//start_ble=false;
        			start_ble=false;
        			}
        			else
        				start_ble = true;
        			if(start_ble==true)
        			{
        				start_acc=true;
        				ble_on();
        			}
        			else
        			{
        			//start_acc =false;
        			sd_nvic_SystemReset();
        			}
        			//g_state=false;
        		}
        	}

            break;
            default:
            //do nothing
            break;
    }
}



/**
 * @brief Initializing the GPIO settings for reading the GPIO interrupt from the button
 */
//uint32_t sample_number = 0;

uint32_t cpt_gpio_BtnInit(uint8_t gpioIntPin)
{
    ret_code_t errCode=0;

    if(!nrf_drv_gpiote_is_init())
    {
    //	NRF_LOG_INFO("Initializing the GPIO pin = %d\r\n ", gpioIntPin);
        errCode = nrf_drv_gpiote_init(); //Initializing the GPIO pin for reading the interrupt
    }

    APP_ERROR_CHECK(errCode);
    // Choose high Sense setting for reading the  interrupt
    nrf_drv_gpiote_in_config_t in_config =  	GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
   	in_config.pull = NRF_GPIO_PIN_PULLDOWN;
    errCode = nrf_drv_gpiote_in_init(gpioIntPin, &in_config, in_pin_BtnHandler);// Config and event on initialization
  //  NRF_LOG_INFO("err %u\n",errCode);
    APP_ERROR_CHECK(errCode);
   // NRF_LOG_INFO("err %u\n",errCode);
    NRF_LOG_INFO("Interrupt Initiated on Pin Number is %d\n", gpioIntPin);
	//updated_hrm_value = gpioIntPin;
    nrf_drv_gpiote_in_event_enable(gpioIntPin, true);
   // NRF_LOG_INFO("err %u\n",errCode);
    return errCode;
}

