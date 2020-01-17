/*
 * cpt_sht3x_data.c
 *
 *  Created on: 19 November 2019
 *      Author: Inertial Elements
 *      Version: 1.0
 *      @brief: This file include utility functions for reading the sht3x data through
 *      i2c protocol. This file includes functionality to initialize the i2c communication and
 *      and also initialize the GPIOs, reading and writing data to the temperature and humidity sensor.
 *
 */

/* Private includes ----------------------------------------------------------*/




#include "nrf_delay.h"
#include "app_util_platform.h"
#include <stdbool.h>

#include "../Inc/cpt_sht3x_data.h"
#define SHT3x_I2C_TIMEOUT 	1000

uint8_t humidity[8];
uint16_t temperature[8];
uint8_t k_number;
bool init;
bool pass;
bool fail;
float tempfloat;
float humdfloat;

/**Takes care of the read data calculation to covert to temp and humidity values
 */

void read_data(sample_t * p_new_sample)
{
    m_sensor_val.temp   = ( ( p_new_sample->tmsb.raw << 8 ) + ( p_new_sample->tlsb.raw <<0 ) );
    m_sensor_val.humd   = ( ( p_new_sample->hmsb.raw << 8 ) + ( p_new_sample->hlsb.raw <<0 ) );	

    m_sensor_val_f.temp = (m_sensor_val.temp * 0.00267)- 45;
    m_sensor_val_f.humd = (m_sensor_val.humd * 0.00153);
  //  NRF_LOG_INFO("Temp " NRF_LOG_FLOAT_MARKER "\r\n", NRF_LOG_FLOAT(m_sensor_val_f.temp));
  //  NRF_LOG_INFO("Humd " NRF_LOG_FLOAT_MARKER "\r\n", NRF_LOG_FLOAT(m_sensor_val_f.humd));
    tempfloat = m_sensor_val_f.temp;
    humdfloat = m_sensor_val_f.humd;
   // pass =true;

}


/*Twi handler supports read and calculation as there is no register to read.*/

void twi_handler(nrf_drv_twi_evt_t const * p_event, void * p_context)
{
    ret_code_t err_code;
    static sample_t m_sample;
    
    switch (p_event->type)
    {
        case NRF_DRV_TWI_EVT_DONE:
            if ((p_event->xfer_desc.type == NRF_DRV_TWI_XFER_TX)&&(init==false))
            {
            	m_xfer_done = false;
                 nrf_delay_ms(20);
            	 err_code = nrf_drv_twi_rx(&m_twi_sht3x, ADDR_A, (uint8_t*)&m_sample, sizeof(m_sample));
            	 NRF_LOG_INFO("ERR: %d\n",err_code);


            }
            else if ((p_event->xfer_desc.type == NRF_DRV_TWI_XFER_TX)&&(init==true))
            {
            	 m_xfer_done = true;
            	// g_real = true;
            	 pass =true;
            }
            else
            {
              read_data(&m_sample);
              m_xfer_done = true;
            }
            switch(p_event->xfer_desc.type)
                       {
                           case NRF_DRV_TWI_XFER_TXTX:
                        	   m_xfer_done = true;
                               break;
                           case NRF_DRV_TWI_XFER_RX:
                        	   m_xfer_done = true;
                        	//   NRF_LOG_INFO("Received Sensor Data");
                               break;
                           case NRF_DRV_TWI_XFER_TXRX:
                        	   m_xfer_done = true;
                               break;
                           default:
                               break;
                       }
                       break;

            break;
            
        case NRF_DRV_TWI_EVT_ADDRESS_NACK:
        {
          NRF_LOG_INFO("Error Addr ACK");
          fail =true;
        }break;
        
        case NRF_DRV_TWI_EVT_DATA_NACK:
        {
          NRF_LOG_INFO("Error Data ACK");
        }break;
        default:
            break;
    }
}

/**
 * @brief TWI initialization.
 * Just the usual way. Nothing special here. The TWI0 functionality has been utilized for instantiate.
 */

void twi_init (void)
{
    ret_code_t err_code;

    const nrf_drv_twi_config_t twi_sht3x_config = {
       .scl                = SCL_PIN,
       .sda                = SDA_PIN,
       .frequency          = NRF_TWI_FREQ_400K,
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
       .clear_bus_init     = false
    };
   // NRF_LOG_INFO("I2C START");
    err_code = nrf_drv_twi_init(&m_twi_sht3x, &twi_sht3x_config, twi_handler, NULL);
 //   NRF_LOG_INFO("ERR: %d\n",err_code);
    APP_ERROR_CHECK(err_code);

    nrf_drv_twi_enable(&m_twi_sht3x);
}

/**
 * @brief Settings of the sensors i.e clock stretching
 * Just the usual way. Nothing special here. Twi handler supports read and calculation as there is no register to read.
 */

void sht3x_set_mode(uint8_t Address, uint8_t MSB, uint8_t LSB)
{
  ret_code_t err_code;
  uint32_t timeout = SHT3x_I2C_TIMEOUT;
  static uint8_t reg[2];
    reg[0] = MSB;
    reg[1] = LSB;
  init =false;
  err_code = nrf_drv_twi_tx(&m_twi_sht3x, Address, reg, sizeof(reg), false);
  NRF_LOG_INFO("tRANSERROR: %d\n",err_code);
  m_xfer_done = false;
}

/**
 * @brief MUX channel selector
 * Just the usual way. Select the I2c channel.
 */

void sht3x_set_SENSOR(uint8_t Address, uint8_t MSB)
{
  ret_code_t err_code;
  init =true;
  static uint8_t reg[1];
  reg[0] =MSB;
  err_code = nrf_drv_twi_tx(&m_twi_sht3x, Address, reg, sizeof(reg), false);
  APP_ERROR_CHECK(err_code);
  m_xfer_done = false;
  NRF_LOG_INFO("tRANSERRORint: %d\n",err_code);
}


/**
 * @brief MUX channel selector
 * Just the usual way. Select the I2c channel.
 */
uint8_t control_reg;
void sht3x_read_Channel(void)
{
  ret_code_t err_code;
  init =true;
  err_code = nrf_drv_twi_rx(&m_twi_sht3x, MUX_ADDRESS, (uint8_t*)&control_reg, sizeof(control_reg));
  APP_ERROR_CHECK(err_code);
  m_xfer_done = false;
  NRF_LOG_INFO("control_reg: %d\n",control_reg);
}
