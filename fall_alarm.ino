//function that checks if the person has started walking and if he has 
//lost his grip

int fall_alarm(int FSR, int is_walking){
  int ans = 0;
  if (FSR < 20 && is_walking == 1){
    ans = 1;
  }
  return ans;
}

//to do:
// - If the person lets go of Safestep but then regains his grip,
// if a fall alram has been sent, then a new message needs to be sent 
//informing that the person is okay
