#include <stdio.h>
#include <wiringPi.h>


int main(int argc, char** argv)
{
    wiringPiSetup();
    

    printf("wiringPi is working!\n");
    
    // set pin 1 to PWM
    pinMode (14, PWM_OUTPUT) ;
    
    
    while(1)
    {

    
        pwmWrite (14, 10) ;
        delay (5000) ;
        pwmWrite (14, 100) ;
      
        
        
    }
    
    return 0;
}
