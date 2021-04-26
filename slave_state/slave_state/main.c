/*
 * slave_state.c
 *
 * Created: 19/04/2021 05:03:36 م
 */ 
#include "LED.h"
#include "SPI.h"
#include "MOTOR.h"
int main(void)
{
	Motor_Init(0);
	LED0_Initialize();
	LED1_Initialize();
	SPI_Init();
	_delay_ms(1000);
	Uint8t spi_rec =0;
	Uint8t direc =0;
    while (1) 
    {
		spi_rec = SPI_Receive();
		switch (spi_rec)
		{
		case 1 :
		    if(direc==0){
			Motor1_Enable();
			Motor1_Direction(0);
			direc = 1;
		    break;
			}
		else if(direc==1) {
			Motor1_Enable();
			Motor1_Direction(1);
			direc = 0;
			break;
		}
		spi_rec =0;
		break;
		case 'a':
		LED0_TGL();
		spi_rec =0;
		break;
		}
    }
}

