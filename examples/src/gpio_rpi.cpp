#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

int main(int argc, char** argv)
{
    wiringPiSetup();
    

    printf("wiringPi is working!\n");
    
    softPwmCreate(14,0,100);
    
    
    while(1)
    {

    
        softPwmWrite(14,94);
        
        delay(5000);
        
        
        softPwmWrite(14,75);
        
        delay(5000);
        
        
    }
    
    return 0;
}
