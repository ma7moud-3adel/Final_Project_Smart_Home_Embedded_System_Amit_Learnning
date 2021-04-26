/*
* LCD.c
*
* Created: 2/27/2021 12:31:54 PM
*/

#include "LCD.h"

void LCD_Init(void)
{
	/*Define direction for command pins*/
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_RS, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_RW, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_EN, LCD_OUTPUT);
	/*Define direction for data pins*/
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_PIN4, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_PIN5, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_PIN6, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_PIN7, LCD_OUTPUT);
	/*LCD controller is slower than MC speed*/
	_delay_ms(100);
	LCD_Write_Command(0x02);
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x0C);
	LCD_Write_Command(0x01);
	LCD_Write_Command(0x06);
	_delay_ms(10);
}
void LCD_Clear(void)
{
	LCD_Write_Command(0x01);
}
void LCD_Write_Command(Uint8t command)
{
	/*RS is logic(0) to write inside control register*/
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_LOW);
	/*RW is logic(0) to write on LCD*/
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RW, LCD_LOW);
	/*To be sure of enable state before start operation*/
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	/*Send high nibble of command*/
	PORTA = (command & 0xF0) | (PORTA & 0x0F);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	/*send low nibble of command*/
	PORTA = (command << 4) | (PORTA & 0x0F);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	/*Delay for 2 millisecond*/
	_delay_ms(2);
}
void LCD_Write_Character(Uint8t character)
{
	/*RS is logic(1) to write inside data register*/
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_HIGH);
	/*RW is logic(0) to write on LCD*/
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RW, LCD_LOW);
	/*To be sure of enable state before start operation*/
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	/*Send high nibble of command*/
	PORTA = (character & 0xF0) | (PORTA & 0x0F);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	/*send low nibble of command*/
	PORTA = (character << 4) | (PORTA & 0x0F);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	/*Delay for 2 millisecond*/
	_delay_ms(2);
}
void LCD_Write_String(Uint8t* str)
{
	//LCD_Write_Command(0x82);
	while(*str != '\0')
	{
		LCD_Write_Character(*str);
		str++;
	}
}
void LCD_Write_Number(Uint32t number)
{
	Uint8t num[10];
	ltoa(number, (Uint8t*)num, 10);
	LCD_Write_String(num);
}
void LCD_Write_Float(Fint32t Fnumber)
{
	
}
void LCD_Write_Arabic(Uint8t* arabic)
{
	Uint8t i;
	LCD_Write_Command(0x40);
	for(i=0;i<8;i++)
	LCD_Write_Character(arabic[i]);
}
void LCD_SAVE_CGRAM(void){
	LCD_Write_Command(0x40);
	LCD_Write_Character(0x0E);
	LCD_Write_Character(0x0E);
	LCD_Write_Character(0x04);
	LCD_Write_Character(0xE);
	LCD_Write_Character(0x15);
	LCD_Write_Character(0x04);
	LCD_Write_Character(0x0A);
	LCD_Write_Character(0x0A);
	/*LCD_Write_Character(0b00000);
	LCD_Write_Character(0b00000);
	LCD_Write_Character(0b01010);
	LCD_Write_Character(0b00000);
	LCD_Write_Character(0b00000);
	LCD_Write_Character(0b10001);
	LCD_Write_Character(0b01110);
	LCD_Write_Character(0b00000);*/
}