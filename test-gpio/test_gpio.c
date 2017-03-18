#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#define GPIO_PIN     16 

int main()
{
    if(wiringPiSetupGpio() == -1) //wiringPiSetupGpio()表示使用GPIO编号，wiringPiSetup()则使用物理编号
    {
        printf("Setup wiringPi failed!");
        return -1;
    }

    pinMode(GPIO_PIN, OUTPUT); // 设置引脚为输出

    while(1) 
    {
        digitalWrite(GPIO_PIN, 1); // 设置输出高电平
        delay(1000);
        digitalWrite(GPIO_PIN, 0); // 设置输出低电平
        delay(1000);
    }

    return 0;
}
