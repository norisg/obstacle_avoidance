#include <iostream>        // Include all needed libraries here
#include <wiringPi.h>

using namespace std;        // No need to keep using “std”

int main()
{

    if(wiringPiSetupGpio()==-1)
   {
       cout<<"Setup wiring pi failed";
       return 1;
   }           // Setup the library
    pinMode(11, OUTPUT);        // Configure GPIO11 as an output
    
    int dutycycle = 2.5
    softPwmCreate(11,0,50);
    // Main program loop
    while(1)
    {
        if (dutycycle = 2.5) {
            softPwmWrite(11,dutycycle)
            dutycycle = 10
        }
        else {
            softPwmWrite(11,dutycycle)
            dutycycle = 2.5
        }
        delay(5000)
    }
    return 0;
}
