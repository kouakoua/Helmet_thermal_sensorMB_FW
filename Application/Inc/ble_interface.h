/*
 * ble_interface.h
 *
 *  Created on: 17-Oct-2019
 *      Author: Inertial Elements
 */

#ifndef APPLICATION_INC_BLE_INTERFACE_H_
#define APPLICATION_INC_BLE_INTERFACE_H_
#include <stdint.h>
#include <string.h>
#include <stdbool.h>



extern volatile int updated_hrm_value;
void ble_on(void);

//extern bool start_acc;
extern uint8_t humidity[8];
extern  uint16_t temperature[8];
//extern uint32_t testval;

/**@brief Function for the Power manager.
 */
//extern void power_manage(void);


/**@brief Function for initializing all the BLE services.
 */
extern int ble_init(void);

#endif /* APPLICATION_INC_BLE_INTERFACE_H_ */
