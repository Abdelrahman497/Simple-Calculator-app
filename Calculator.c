#include "keypad.h"
#include "lcd.h"
#include <util/delay.h>

int main (void)
{
	uint8 key ;
	float32 num1 = 0 , num2 = 0 ;
	float32 result = 0 ;
	uint8 operator = 0 ;

	LCD_init();
	LCD_displayString(" Calculator ON ");
	_delay_ms(1000);
	LCD_clearScreen();

	while(1)
	{
		key = KEYPAD_getPressedKey();

		if ( (key >=0)  && (key <= 9) )
		{
			LCD_intgerToString(key) ;
			num2 = ( (num2 * 10) + key ) ;
		}

		else if ( key == '+' || key == '-' || key == '*' || key == '/' )
		{
			LCD_displayCharacter(key);
			operator = key ;
			num1 = num2 ;
			num2 = 0 ;
		}

		else if (key == '=')
		{
			//LCD_displayCharacter(key);

			switch(operator)
			{
			case '+':
				LCD_moveCursor(1,0);
				LCD_displayString("Ans = ");
				result = num1 + num2 ;
				break;

			case '-':
				LCD_moveCursor(1,0);
				LCD_displayString("Ans = ");
				result = num1 - num2 ;
				break;

			case '*':
				LCD_moveCursor(1,0);
				LCD_displayString("Ans = ");
				result = num1 * num2 ;
				break;

			case '/':
				if(num2 != 0 )
				{
					LCD_moveCursor(1,0);
					LCD_displayString("Ans = ");
					result = num1 / num2 ;
				}
				else
				{
					LCD_moveCursor(1,0);
					LCD_displayString("MATH ERROR");
				}
				break;

			default:
				LCD_moveCursor(1,0);
				LCD_displayString("NO operator");
				continue;
				break;

			}
			if(num2 != 0 )
			{
				if(operator == '/')
				{
					LCD_floatToString(result);
				}
				else
				{
					LCD_floatToString(result);
				}
			}
		}

		else if (key == 'c')
		{
			LCD_clearScreen();
			num1 = num2 = 0 ;
			operator = 0 ;
		}

		_delay_ms(500);
	}

}
