#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

int main(int argc, char** argv)
{
    wiringPiSetup();
    

    printf("wiringPi is working!\n");
    
    softPwmCreate(14,0,100);
    
    softPwmWrite(14,5);
    

    return 0;
}
