#include "Arduino.h"
#include "Falling.h"
#include "FSR.h"
#include "Timer_Func_And_Reed_Switch.h"

Falling::Falling(FSR* f, Timer_Func_And_Reed_Switch* TF): fsr{f}, TFRS{TF}, counter{0}, answer{2}, passing_of_magnet{1}, FSR_reading{0}, walking{0} 
{
}


int Falling:: is_walking()
{
   
   passing_of_magnet = TFRS->proximity();
  
    if (passing_of_magnet == LOW && counter == 0){ //check if near the first magnet, if LOW it means the magnet is near
        counter = 1;
    }
  
    if (passing_of_magnet == HIGH && counter == 1){
        counter = 2;
        answer = 1; //Update answer here because this is when the person has passed the first magnet. If updated when near the first magnet, then it could happen the person changes his mind
        // and does not use the stairs, then it should not alert a fall. And if the person changes his mind and goes back down after passing the first magnet, then he will pass the same magnet again
        //which will update the value for answer to 0, and that is how it should be
    
    }
  
    if (passing_of_magnet == LOW && counter == 2){
        counter = 3;
    
    }
    //has now passed the second magnet
   
    if (passing_of_magnet == HIGH && counter == 3){
        answer = 0;
        counter = 0;
    
    }

  return answer; //if return 0, the person is not walking, if 1 person is still walking, if returns 2 the first time walking the stairs since staring the microcontroller has not yet happened
 
}

int Falling::loop() 
{
    FSR_reading = fsr->loop();
    walking = this->is_walking();
    if (FSR_reading <20 && walking == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

Falling::~Falling() 
{

}