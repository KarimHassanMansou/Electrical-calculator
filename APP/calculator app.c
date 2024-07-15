#include <util/delay.h>
#include "Gpio.h"
#include "LED.h"
#include "LCD.h"
#include "sevensegment.h"
#include "KEYPAD.h"
#include <string.h>

#define SIZE 10
#define SIZE2 5

int number_one = 0;
int number_two = 0;
int res;


int main(void)
{
    
	int i;
	
	//int result[SIZE];
	/*
	uchar8 first_operand[SIZE2];
	uchar8 second_operand[SIZE2];
	
	int first[5];
	int second[5];
	*/
	/*
	uchar8 first_operand;
	uchar8 second_operand;
	uchar8 *result;
	uchar8 Arithmetic_operator;
	
	int first;
	int second;
	int res;
	
	*/
	uchar8  key;
	uchar8  key2;
	uchar8  key3;
	//uchar8  result;
	
	uchar8  op1 = '+';
	uchar8  op2 = '-';
	uchar8  op3 = 'x';
	uchar8  op4 = '/';
	
	
	
	/*
	initialize_pin(GPIO_C , 0 , OUTPUT);
    initialize_pin(GPIO_A , 0 , INPUT);
	*/
	
	KEYPAD_INIT();
	LCD_INIT();
	
    while(1)
    {   
		
	  LCD_WRITE_STRING("first operand: ");
	  LCD_WRITE_COMMAND(0xC0);
	  key = GET_PRESSED();
	  LCD_WRITE_DATA(key);
	   _delay_ms(7000);
		
	  LCD_CLEAR();
	  _delay_ms(400);
	  
	  LCD_WRITE_STRING("operator: ");
	  LCD_WRITE_COMMAND(0xC0);
	  key2 = GET_PRESSED();
	  LCD_WRITE_DATA(key2);
	  _delay_ms(7000);
	  
	  LCD_CLEAR();
	  _delay_ms(400);
	  
	  LCD_WRITE_STRING("second operand: ");
	  LCD_WRITE_COMMAND(0xC0);
	  key3 = GET_PRESSED();
	  LCD_WRITE_DATA(key3);
	  _delay_ms(7000);
	  
	 
	 
	 if (GET_PRESSED() == '=')
	 {
		 
	    LCD_CLEAR();
	    _delay_ms(400);
		
		 number_one = charToint(key);
		 number_two = charToint(key3);
	   
	   if((strcmp(key2 , op1)) == 0)
	   {
		   res = number_one + number_two;
	   }	    
	   else if ((strcmp(key2 , op2)) == 0)
	   {
		   res = number_one - number_two;
	   }
	   else if ((strcmp(key2 , op3)) == 0)
	   {
		   res = number_one * number_two;	   		   
	   }
	   else if ((strcmp(key2 , op4)) == 0)
	   {
	       res = number_one / number_two;
	   }
	   else
	   {
	      LCD_WRITE_STRING("karim");
	   }
	   
		   LCD_WRITE_DATA(key);
		   LCD_WRITE_DATA(key2);
		   LCD_WRITE_DATA(key3);
		   LCD_WRITE_CHAR('=');
		   
		   _delay_ms(300);
	       LCD_WRITE_NUMBER(res);
		   _delay_ms(300);
		   
		   if (GET_PRESSED() == 'c')
		   {
			   LCD_CLEAR();
			   _delay_ms(300);
		   }
	 
	 }	 
	 
	 
		  
	}	
	
}

