/*
 * display.c
 *
 *  Created on: Feb 5, 2026
 *      Author: raghu
 */

#include "display.h"

const uint8_t SEGMENT_MAP[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

void Display_Update(int number)
{
    if (number > 99) number = 99;
    if (number < 0) number = 0;


    int tens = number / 10;
    int units = number % 10;
    uint16_t packet = (SEGMENT_MAP[tens] << 8) | SEGMENT_MAP[units];

    HAL_GPIO_WritePin(SR_LATCH_GPIO_Port, SR_LATCH_Pin, 0);


    for (int i = 15; i >= 0; i--)
    {
        if ((packet >> i) & 0x01)
        {
            HAL_GPIO_WritePin(SR_DATA_GPIO_Port, SR_DATA_Pin, 1);
        }
        else
        {
            HAL_GPIO_WritePin(SR_DATA_GPIO_Port, SR_DATA_Pin, 0);
        }

        HAL_GPIO_WritePin(SR_CLK_GPIO_Port, SR_CLK_Pin, 1);
        HAL_GPIO_WritePin(SR_CLK_GPIO_Port, SR_CLK_Pin, 0);
    }

    HAL_GPIO_WritePin(SR_LATCH_GPIO_Port, SR_LATCH_Pin, 1);
    HAL_GPIO_WritePin(SR_LATCH_GPIO_Port, SR_LATCH_Pin, 0);
}
