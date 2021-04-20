#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>


int main(int argc, char** argv)
{
    if(wiringPiSetupGpio()==-1)
   {
       cout<<"Setup wiring pi failed";
       return 1;
   }
    
    

    printf("wiringPi is working!\n");
    
    pinMode(14,OUTPUT);
    
    softPwmCreate(14,0,200);
    
    
    while(1)
    {

    
        softPwmWrite(14,5);
        //softPwmWrite(14,195);
        delay (10000) ;
        //pwmWrite (14, 50) ;
        //softPwmWrite(14,120);
        delay (10000) ;
        
        
    }
    
    return 0;
}
