/**
 * @file main.c
 * @author Prateek Chandra,Pawan,Pavan
 * @brief Project
 * @version 1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "MyStm32f407xx.h"

#define pushbutton ENABLE
#define high          1
#define low           0

int count = 0;

void P1(int);                                  //P1=Push button will be pressed single time
void P2(int);                                  //P2=Push button will be pressed Two   times
void P3(int);                                  //P3=Push button will be pressed Three time
void P4(int);                                  //P4=Push button will be pressed Four time

void delay(){
    for(int i=0; i<6000000; i++);
}

void main(){
    //LED Initialization
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Handle_t GpioLED1;
    GpioLED1.pGPIOx = GPIOD;
    GpioLED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED1);

    GPIO_Handle_t GpioLED2;
    GpioLED2.pGPIOx = GPIOD;
    GpioLED2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioLED2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLED2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED2);

    GPIO_Handle_t GpioLED3;
    GpioLED3.pGPIOx = GPIOD;
    GpioLED3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GpioLED3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLED3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED3);

    GPIO_Handle_t GpioLED4;
    GpioLED4.pGPIOx = GPIOD;
    GpioLED4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GpioLED4.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLED4.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED4.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED4);

    //Push Button Initialization
    GPIO_Handle_t Gpiobtn;
    Gpiobtn.pGPIOx = GPIOA;
    Gpiobtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    Gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&Gpiobtn);

    while(1){
    if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) ==pushbutton)
    {
        delay();
        count += 1;
    }

    if (count == 1){
        delay(); //Debounce
        P1(count - 1);                //P1=Push button will be pressed single time
    }

    if (count == 5){
        delay(); //Debounce
        P2(count - 1);                //P2=Push button will be pressed Two   times
    }

    if (count == 10){
        delay(); //Debounce
        P3(count - 1);                //P3=Push button will be pressed Three times
    }

    if (count == 13){
        delay(); //Debounce
        P4(count - 1);                 //P4=Push button will be pressed Four times

    }

    }


}

void P1(int nums)                            //P1=Push button will be pressed single time
{                                     
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, high);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, high);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, high);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, high);
}

void P2(int nums)                              //P2=Push button will be pressed Two   times
{
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, low);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, low);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, low);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, low);
}

void P3(int nums)                               //P3=Push button will be pressed Three times

{
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
    delay();
    delay();
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
    delay();
    delay();
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
    delay();
    delay();
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
    delay();
    delay();
}

void P4(int nums)                                //P4=Push button will be pressed Four times



{ 
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
    delay();
    delay();
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
    delay();
    delay();
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
    delay();
    delay();
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
    delay();
    delay();
}