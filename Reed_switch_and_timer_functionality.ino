const int REED_PIN = 2; // Pin connected to reed switch
const int LED_PIN = 13; // LED pin - active-high

unsigned long time1;
unsigned long time2;
unsigned long total_time;

int counter=0; //counter for number of magnets passed, starts at 0
int if_killer=1; //used to exit if after magnet is no longer close to reed switch

void setup() 
{
  Serial.begin(9600);
  // Since the other end of the reed switch is connected to ground, we need
  // to pull-up the reed switch pin internally.
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{

  measure_time ();
  //To do: - measure_time must probably return a value to be able to send it to the app--> not a void function
}

void measure_time (){
  int proximity = digitalRead(REED_PIN); // Read the state of the switch

  if (proximity == LOW && if_killer==1) {
    time1 = millis(); //measure the time at first instance of magnet passing
    counter = 1;
    Serial.print("Time1 is : ");
    Serial.println(time1);
    if_killer = 0;
    while (proximity == LOW){
      proximity = digitalRead(REED_PIN); // prevents time1 from being updated constantly while near the first magnet
    }
    
  }

//must now ensure that Safestep has passed the first magnet before taking the next time measure
  if (proximity == LOW && counter==1 && if_killer == 0){
    time2 = millis(); //time when passing second magnet
    if_killer = 2; 
    Serial.print("Time2 is: ");
    Serial.println(time2);
    while (proximity == LOW){
      proximity = digitalRead(REED_PIN); //prevents time2 from being updated constantly while near the second magnet
    }
    total_time = time2-time1;
    Serial.print("Total time: ");
    Serial.println(total_time);

  }
  
  if( if_killer == 2){
    if_killer = 1; //resets condition for first if statement
    counter = 0; //resets condition for second if statement
  }
}
