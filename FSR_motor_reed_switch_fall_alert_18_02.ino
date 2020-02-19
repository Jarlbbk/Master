// Basic sketch for trying out the Adafruit DRV8871 Breakout
 
#define MOTOR_IN1 9
#define MOTOR_IN2 6

//FSR variables
int fsrPin = 2;     // the FSR and 10K pulldown are connected to ANALOG 2
int fsrReading;     // the analog reading from the FSR resistor divider
const int REED_PIN = 2; // Pin connected to reed switch, DIGITAL 2

//Motor variables
int Motor_speed;    //speed input to motor
int answer_measure_time;
int answer_is_walking;
void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(REED_PIN, INPUT_PULLUP);
  
}
 
void loop() {
 
  
  fsrReading = analogRead(fsrPin);
  Motor_speed = map(fsrReading, 0, 1023, 0, 255); //maps a number between 0-1023 to a number between 0-255
  //Serial.println(fsrReading);
  analogWrite(MOTOR_IN1, Motor_speed); //sends speed-signal to motor 

  answer_measure_time = measure_time (); //will return the time it has taken up or down the stairs, SEND TO APP
  
  answer_is_walking = is_walking ();
  /*Serial.print("Time passed is: ");
  Serial.println(answer_measure_time);
  Serial.print("The person is walking or not ");
  Serial.println(answer_is_walking);
*/
  int alarm = fall_alarm(fsrReading, answer_is_walking);
  Serial.println(alarm);
if (alarm == 1){
  Serial.println("the person has fallen");
  Serial.println(alarm);
  //delay(2000);
}
 //delay(1000);
  
  //To do: - må skille mellom en går opp eller ned trappa, kanskje ved hvilken trykksensor som er aktivert
  //       - Rapportere om det har oppstått et stopp midt i trappa (indikere fall)
  //         
}


//Reed switch and timer variables

unsigned long time1;
unsigned long time2;
unsigned long total_time;

int counter = 0; //counter for number of magnets passed, starts at 0
int if_killer = 1; //used to exit if after magnet is no longer close to reed switch

int measure_time (){
  
  int proximity = digitalRead(REED_PIN); // Read the state of the switch

  if (proximity == LOW && counter == 0) {
    time1 = millis(); //measure the time at first instance of magnet passing
    
    counter = 1;
    Serial.print("Time1 is : ");
    Serial.println(time1);
    //if_killer = 0;
    /*while (proximity == LOW){
      proximity = digitalRead(REED_PIN); // prevents time1 from being updated constantly while near the first magnet
    }*/
    
  }

  if (proximity == HIGH && counter == 1){
    counter = 2;
  }

//must now ensure that Safestep has passed the first magnet before taking the next time measure
  if (proximity == LOW && counter == 2){
    time2 = millis(); //time when passing second magnet
    
    //if_killer = 2; 
    Serial.print("Time2 is: ");
    Serial.println(time2);
    /*while (proximity == LOW){
      proximity = digitalRead(REED_PIN); //prevents time2 from being updated constantly while near the second magnet
    }*/
    total_time = time2-time1;
    counter = 3;
    Serial.print("Total time: ");
    Serial.println(total_time);
  }

  if (proximity == HIGH && counter == 3) {
    counter = 0;
  }
  /*if( if_killer == 2){
    if_killer = 1; //resets condition for first if statement
    counter = 0; //resets condition for second if statement
  }*/
  return total_time; //Must return the time it has taken to store it for the statistics
}

int answer = 2; //must be declared outside of is_walking, otherwise it will be set to 2 for every loop and never reach other value 
int counter2 = 0; //must be declared outside of is_walking, otherwise it will be set to 0 for every loop and never reach other value

int is_walking (){
  int passing_of_magnet = 1;
  passing_of_magnet = digitalRead(REED_PIN);
  
  if (passing_of_magnet == LOW && counter2 == 0){ //check if near the first magnet, if LOW it means the magnet is near
    counter2 = 1;
    Serial.print("counter is ");
    Serial.println(counter2);
    //delay(1000);
  }
  
  if (passing_of_magnet == HIGH && counter2 == 1){
    counter2 = 2;
    Serial.print("counter is ");
    Serial.println(counter2);
    answer = 1; //Update answer here because this is when the person has passed the first magnet. If updated when near the first magnet, then it could happen the person changes his mind
    // and does not use the stairs, then it should not alert a fall. And if the person changes his mind and goes back down after passing the first magnet, then he will pass the same magnet again
    //which will update the value for answer to 0, and that is how it should be
    //delay(1000);
  }
  
  if (passing_of_magnet == LOW && counter2 == 2){
    counter2 = 3;
    Serial.print("counter is ");
    Serial.println(counter2);
    //delay(1000);
  }
    //has now passed the second magnet
   
    if (passing_of_magnet == HIGH && counter2 == 3){
    answer = 0;
    counter2 = 0;
    Serial.print("counter is ");
    Serial.println(counter2);
    //delay(1000);
    }

  return answer; //if return 0, the person is not walking, if 1 person is still walking, if returns 2 the first time walking the stairs since staring the microcontroller has not yet happened
}

int fall_alarm(int FSR, int is_walking){
  int ans = 0;
  if (FSR < 20 && is_walking == 1){ //if FSR is not recieving pressure and the person is walking, the value FSR is less than must be based
   //on something, this one is picked at random
    ans = 1;
  }
  return ans;
}
