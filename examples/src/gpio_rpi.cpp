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

    
        pwmWrite (1, 10) ;
        delay (10) ;
        
      
        
        
    }
    
    return 0;
}
