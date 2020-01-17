#include "ble_interface.h"
#include "bsp_btn.h"
//#include "bsp_btn.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_backend.h"

int main(void){
	//SEGGER_RTT_WriteString(0, "Hello World!\n");
    uint32_t err_code;
    err_code = NRF_LOG_INIT(NULL);
    bsp_gpio_IntInit();
   // APP_ERROR_CHECK(err_code);
	//NRF_LOG_INFO("Heart Rate Sensor Start!\r\n");
	//bsp_gpio_IntInit();
	NRF_LOG_INFO("BLE is Starting!\r\n");
	ble_init();
	//bsp_gpio_IntInit();
}


//int main()
//{
//    while(true)
//    {
//        // Wait for an event.
//        __WFE();
//        // Clear the internal event register.
//        __SEV();
//        __WFE();
//    }
//}
