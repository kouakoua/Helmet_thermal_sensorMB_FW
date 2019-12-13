/*
 * bsp_sensor.c
 *
 *  Created on: 19-Oct-2019
 *      Author: CG-DTE
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "bsp_sensor.h"

#include "../../CPT/Inc/cpt_sht3x_data.h"
#include "app_util_platform.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf51.h"


/**
 * @brief Switch on the sensors Initialization
 * Just the usual way. Nothing special here.
 */
void bsp_Sensor0init(void)
{

	twi_init();
}

/**
 * @brief Data from Sensors connected to J31
 * Just the usual way. Nothing special here.
 */
void bsp_ReadSensor0read(void)
{
	NRF_LOG_INFO("Sensor---------------------------------- 0\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS, 77);
	nrf_delay_ms(20);
	k_number=0;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
		{
			temperature[k_number]= (uint16_t)(tempfloat*10);
			humidity[k_number]=(uint8_t) humdfloat;
		}
	else
	{
		temperature[k_number]=0;
		humidity[k_number]=0;
	}
}

/**
 * @brief Data from Sensors connected to J32
 * Just the usual way. Nothing special here.
 */
void bsp_ReadSensor1read(void)
{
	// The SCL and the SDA pins are set .
	NRF_LOG_INFO("Sensor----------------------------------- 1\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,177);
	nrf_delay_ms(20);
	k_number=1;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
			{
				temperature[k_number]= (uint16_t)(tempfloat*10);
				humidity[k_number]=(uint8_t)humdfloat;
			}
		else
		{
			temperature[k_number]=0;
			humidity[k_number]=0;
		}
	NRF_LOG_INFO("Temp %d\n",temperature[k_number]);
	NRF_LOG_INFO("Humd %d\n",humidity[k_number]);

}

/**
 * @brief Data from Sensors connected to J33
 * Just the usual way. Nothing special here.
 */

void bsp_ReadSensor2read(void)
{
	// The SCL and the SDA pins are set .
	NRF_LOG_INFO("Sensor----------------------------------- 2\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,202);
	nrf_delay_ms(20);
	k_number=2;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
	{
		temperature[k_number]= (uint16_t)(tempfloat*10);
		humidity[k_number]=(uint8_t) humdfloat;
	}
	else
	{
		temperature[k_number]=0;
		humidity[k_number]=0;
	}
	NRF_LOG_INFO("Temp %d\n",temperature[k_number]);
	NRF_LOG_INFO("Humd %d\n",humidity[k_number]);

}

/**
 * @brief Data from Sensors connected to J41
 * Just the usual way. Nothing special here.
 */

void bsp_ReadSensor3read(void)
{
	// The SCL and the SDA pins are set .
	NRF_LOG_INFO("Sensor------------------------------------ 3\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,216);
	nrf_delay_ms(20);
	k_number=3;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
	{
		temperature[k_number]= (uint16_t)(tempfloat*10);
		humidity[k_number]=(uint8_t) humdfloat;
	}
	else
	{
		temperature[k_number]=0;
		humidity[k_number]=0;
	}
	NRF_LOG_INFO("Temp %d\n",temperature[k_number]);
	NRF_LOG_INFO("Humd %d\n",humidity[k_number]);

}


/**
 * @brief Data from Sensors connected to J42
 * Just the usual way. Nothing special here.
 */


void bsp_ReadSensor4read(void)
{
	NRF_LOG_INFO("Sensor------------------------------------- 4\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,250);
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,184);
	nrf_delay_ms(20);
	k_number=4;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
	{
		temperature[k_number]= (uint16_t)(tempfloat*10);
		humidity[k_number]=(uint8_t)humdfloat;

	}
	else
	{
		temperature[k_number]=0;
		humidity[k_number]=0;
	}

	NRF_LOG_INFO("Temp %d\n",temperature[k_number]);
	NRF_LOG_INFO("Humd %d\n",humidity[k_number]);
}


/**
 * @brief Data from Sensors connected to J43
 * Just the usual way. Nothing special here.
 */


void bsp_ReadSensor5read(void)
{
	// The SCL and the SDA pins are set .
	NRF_LOG_INFO("Sensor---------------------------------------5\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,249);
	nrf_delay_ms(20);
	k_number=5;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
	{
		temperature[k_number]= (uint16_t)(tempfloat*10);
		humidity[k_number]=(uint8_t) humdfloat;
	}
	else
	{
		temperature[k_number]=0;
		humidity[k_number]=0;
	}
	NRF_LOG_INFO("Temp %d\n",temperature[k_number]);
	NRF_LOG_INFO("Humd %d\n",humidity[k_number]);
}


/**
 * @brief Data from Sensors connected to J1
 * Just the usual way. Nothing special here.
 */


void bsp_ReadSensor6read(void)
{
	// The SCL and the SDA pins are set .
	NRF_LOG_INFO("Sensor----------------------------------- 6\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,00);
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,132);
	nrf_delay_ms(20);
	k_number=6;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
	{
		temperature[k_number]= (uint16_t)(tempfloat*10);
		humidity[k_number]=(uint8_t)humdfloat;
	}
	else
	{
		temperature[k_number]=0;
		humidity[k_number]=0;
	}
	NRF_LOG_INFO("Temp %d\n",temperature[k_number]);
	NRF_LOG_INFO("Humd %d\n",humidity[k_number]);
}

/**
 * @brief Data from Sensors connected to J2
 * Just the usual way. Nothing special here.
 */


void bsp_ReadSensor7read(void)
{
	// The SCL and the SDA pins are set .
	NRF_LOG_INFO("Sensor----------------------------------- 7\n");
	pass = false;
	fail = false;
	nrf_delay_ms(20);
	sht3x_set_SENSOR(MUX_ADDRESS,238);
	nrf_delay_ms(20);
	k_number=7;
	sht3x_set_mode(ADDR_A, SHT_CMD_STRETCH_MSB, SHT_CMD_STRETCH_LSB_HIGH);
	if((pass ==true)&&(fail ==false))
		{
			temperature[k_number]= (uint16_t)(tempfloat*10);
			humidity[k_number]=(uint8_t) humdfloat;
		}
		else
		{
			temperature[k_number]=0;
			humidity[k_number]=0;
		}
	NRF_LOG_INFO("Temp %d\n",temperature[k_number]);
	NRF_LOG_INFO("Humd %d\n",humidity[k_number]);

}




