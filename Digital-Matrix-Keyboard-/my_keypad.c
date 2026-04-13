/*
 * my_keypad.c
 *
 *  Created on: Feb 4, 2026
 *      Author: raghu
 */

#include "my_keypad.h"

GPIO_TypeDef* ROW_PORTS[KEYPAD_ROWS] = {GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA};
uint16_t ROW_PINS[KEYPAD_ROWS] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5};

GPIO_TypeDef* COL_PORTS[KEYPAD_COLS] = {GPIOB, GPIOB, GPIOB, GPIOB, GPIOB};
uint16_t COL_PINS[KEYPAD_COLS] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4};

char KEY_MAP[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'J'},
    {'K', 'L', 'M', 'N', 'O'},
    {'P', 'Q', 'R', 'S', 'T'},
    {'U', 'V', 'W', 'X', 'Y'},
    {'Z', '0', '1', '2', '3'}
};

char Scan(void)
{


	//setting all column pins low
    for(int i=0; i<KEYPAD_COLS; i++)
    {
        HAL_GPIO_WritePin(COL_PORTS[i], COL_PINS[i], 0);
    }

    for(int i=0; i<KEYPAD_ROWS; i++)
       {
           HAL_GPIO_WritePin(ROW_PORTS[i], ROW_PINS[i], 0);
       }




// starting the loop to check all rows for each column
    for(int col=0; col<KEYPAD_COLS; col++)
    {
        HAL_GPIO_WritePin(COL_PORTS[col], COL_PINS[col], 1);

        HAL_Delay(3000);

      //  for(int row=0; row<KEYPAD_ROWS; row++)
        //{
            if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)
            {
               // while(HAL_GPIO_ReadPin(ROW_PORTS[row], ROW_PINS[row]) == GPIO_PIN_SET);

            	//HAL_Delay(20);

                HAL_GPIO_WritePin(COL_PORTS[col], COL_PINS[col], 0);

                return 'A';
              //  return KEY_MAP[row][col];

            }
       // }

      //  HAL_Delay(20);

        // C. Turn THIS column back LOW before moving to the next
        HAL_GPIO_WritePin(COL_PORTS[col], COL_PINS[col], 0);
    }

    return 'Z'; // Return 0 (Null) if no key is pressed
}

