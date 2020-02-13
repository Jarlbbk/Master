// Basic sketch for trying out the Adafruit DRV8871 Breakout
 
#define MOTOR_IN1 9
#define MOTOR_IN2 6


int fsrPin = 2;     // the FSR and 10K pulldown are connected to a2
int fsrReading;     // the analog reading from the FSR resistor divider
int Motor_speed;    //speed input to motor
void setup() {
  Serial.begin(9600);
 
  Serial.println("DRV8871 test");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}
 
void loop() {
 
  
  fsrReading = analogRead(fsrPin);
  Motor_speed = map(fsrReading, 0, 1023, 0, 255); //maps a number between 0-1023 to a number between 0-255
  Serial.println(fsrReading);
  analogWrite(MOTOR_IN1, Motor_speed); //sends speed-signal to motor  
  //To do: - må skille mellom en går opp eller ned trappa, kanskje ved hvilken trykksensor som er aktivert
  //       - Rapportere om det har oppstått et stopp midt i trappa (indikere fall)
  // 
}
