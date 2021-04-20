#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>


int main(int argc, char** argv)
{
    wiringPiSetup();
    
    

    printf("wiringPi is working!\n");
    
    pinMode(14,OUTPUT);
    
    softPwmCreate(14,0,200);
    
    
    while(1)
    {

    
        softPwmWrite(14,25);
        //softPwmWrite(14,195);
        delay (10000) ;
        //pwmWrite (14, 50) ;
        softPwmWrite(14,120);
        delay (10000) ;
        
        
    }
    
    return 0;
}
