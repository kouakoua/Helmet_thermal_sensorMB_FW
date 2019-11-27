/*
 * bsp_sensor.h
 *
 *  Created on: 19-Oct-2019
 *      Author: Inertial Elements
 */

#ifndef DRIVERS_BSP_INC_BSP_SENSOR_H_
#define DRIVERS_BSP_INC_BSP_SENSOR_H_

/**@brief Structure to hold sensor values.
 * All values are unsigned 16 bit integers
*/
typedef struct
{
    int16_t ST;
    int16_t SRH;
}sensor_values_t;

/*@Brief This function is used for initialization of the temperature and Humidity sensor.
*/

void bsp_Sensor0init(void);
extern void bsp_ReadSensor0read(void);
extern void bsp_ReadSensor1read(void);
extern void bsp_ReadSensor2read(void);
extern void bsp_ReadSensor3read(void);
extern void bsp_ReadSensor4read(void);
extern void bsp_ReadSensor5read(void);
extern void bsp_ReadSensor6read(void);
extern void bsp_ReadSensor7read(void);
//extern uint32_t bsp_PushToRawBuf(uint8_t sensorBuffer[1000],uint16_t count);


#endif /* DRIVERS_BSP_INC_BSP_SENSOR_H_ */
