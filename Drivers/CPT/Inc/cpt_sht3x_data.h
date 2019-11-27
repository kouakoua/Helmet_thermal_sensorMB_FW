/*
 * cpt_sht3x_data.h
 *
 *  Created on: 19 November 2019
 *      Author: Inertial Elements
 *      Version: 1.0
 *      @brief: This file include utility functions for reading the sht3x data through
 *      i2c protocol. This file includes functionality to initialize the i2c communication and
 *      and also initialize the GPIOs, reading and writing data to the accelerometer.
 *
 */

/* Private includes ----------------------------------------------------------*/

#include "app_error.h"
#include "hal_drv_twi.h"
#include "nrf_delay.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
//#include "nrf_log_default_backends.h"

#define ADDR_A                      0x44
#define ADDR_B                      0x45
#define MUX_ADDRESS             	0x70
#define SDA_PIN                       22
#define SCL_PIN                       23

#define SHT_CMD_STRETCH_MSB         0x2c
#define SHT_CMD_STRETCH_LSB_HIGH    0x06
#define SHT_CMD_STRETCH_LSB_MED     0x0D 
#define SHT_CMD_STRETCH_LSB_LOW     0x10   
#define SHT_CMD_NOSTRETCH_MSB       0x2c
#define SHT_CMD_NOSTRETCH_LSB_HIGH  0x06
#define SHT_CMD_NOSTRETCH_LSB_MED   0x0B
#define SHT_CMD_NOSTRETCH_LSB_LOW   0x16


extern uint8_t humidity[8];
extern uint16_t temperature[8];
extern uint8_t k_number;
extern bool g_real;
//TWI parametrs
/* TWI instance ID. */
#define TWI_INSTANCE_ID          0

#define NUMBER_OF_SAMPLES       20

/* Indicates if operation on TWI has ended. */
static volatile bool m_xfer_done = false;

/* Indicates if setting mode operation has ended. */
static volatile bool m_set_mode_done = false;

/* TWI instance. */
static const nrf_drv_twi_t m_twi_sht3x = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

typedef struct
{
    float temp;
    float humd;
} sensor_val_f;
static sensor_val_f m_sensor_val_f = {0};

typedef struct
{
    uint16_t temp;
    uint16_t humd;
    uint8_t  crc_t;
    uint8_t  crc_h;
} sensor_val;
static sensor_val m_sensor_val = {0};

typedef union{
    uint8_t raw;
    int8_t  conv;
}elem_t;

///* Buffer for samples read from temperature sensor. */
typedef struct
{
    elem_t  tmsb;
    elem_t  tlsb;
    elem_t  tcrc;
    elem_t  hmsb;
    elem_t  hlsb;
    elem_t  hcrc;
} sample_t;

void read_data(sample_t * p_new_sample);
void twi_init (void);
void sht3x_set_mode(uint8_t Address, uint8_t MSB, uint8_t LSB);
void sht3x_set_SENSOR(uint8_t Address, uint8_t MSB);
