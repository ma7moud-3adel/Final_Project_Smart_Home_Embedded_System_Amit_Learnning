/*
 * Master_state.c
 *
 * Created: 14/04/2021 04:38:57 م
 */ 
#include "UART.h"
#include "ADC.h"
#include "LED.h"
#include "SPI.h"
#include "LCD.h"
#include "InOut.h"
#include "ADC.h"
Uint8t state_machine =0;
Uint8t data =0 ;
Uint8t data1 = 0;
Uint16t data2 = 0;
Uint16t data3 =0;
int main(void)
{
    LCD_Init();
    while (1) 
    {
		switch(state_machine)
		{
			case 0:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Welcome");
			state_machine =1;
			_delay_ms(1000);
			break;
			case 1:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Led_intialize");
			LED0_Initialize();
			state_machine = 2;
			_delay_ms(1000);
			break;
			case 2:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Pot_Inialization");
			ADC_Init(ADC0);
			state_machine = 3;
			_delay_ms(1000);
			break;
			case 3:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"HC05_Inialization");
			UART_Init();
			sei();
			state_machine = 4;
			_delay_ms(1000);
			break;
			case 4:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Button_Inialization");
			BUTTON0_Initialize();
			state_machine = 5;
			_delay_ms(1000);
			break;
			case 5:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Waiting");
			if(BUTTON0_Read()==1){
				while(BUTTON0_Read()==1);
				state_machine = 6;
				data1 = 1;
			}
			
			else if(data!=0){
				state_machine =6;
			}
			else if(data3!=0){
				state_machine =6;
			}
			 _delay_ms(50);
			break;
			case 6:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Recieving");
			_delay_ms(1000);
			if(data!=0||data1!=0||data3!=0)
			state_machine = 7;
			break;
			case 7:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Spi intialize");
			SPI_Init();
			_delay_ms(1000);
			state_machine = 8;
			break;
			case 8:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"Spi transmit");
			if(data!=0)SPI_Transmit(data);
			else if(data1!=0)SPI_Transmit(data1);
			else if(data2!=0)SPI_Transmit(data3);
			_delay_ms(1000);
			state_machine = 9;
			break;
			case 9:
			LCD_Clear();LCD_Write_String((Uint8t*)"StateMachine");LCD_Write_Number(state_machine);
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8t*)"New_Start");
			_delay_ms(1000);
			data =0;
			data1 =0;
			data3 =0;
			state_machine = 5;
			break;
		}
    }
	
}
ISR(USART_RXC_vect){
	data = UDR;
}
ISR(ADC_vect){
	data2 = ADC_Read();
	data3 = ((data2*5)/1024);
	SET_BIT(ADCSRA,ADSC);
}
