// Basic sketch for trying out the Adafruit DRV8871 Breakout
 
#define MOTOR_IN1 9
#define MOTOR_IN2 6


int fsrPin = 2;     // the FSR and 10K pulldown are connected to a2
int fsrReading;     // the analog reading from the FSR resistor divider
int Motor_speed; 
void setup() {
  Serial.begin(9600);
 
  Serial.println("DRV8871 test");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}
 
void loop() {
 
  // ramp up forward
  //digitalWrite(MOTOR_IN1, LOW);
  fsrReading = analogRead(fsrPin);
  Motor_speed = map(fsrReading, 0, 1023, 0, 255); //maper et tall mellom 0-1023 til et tall mellom 0-255
  Serial.println(fsrReading);
  analogWrite(MOTOR_IN1, Motor_speed); //sende trykkdata fra FSR til motor, 
  /*for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN2, i);
    delay(10);
  }
 
  // forward full speed for one second
  delay(1000);
  
  // ramp down forward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN2, i);
    delay(10);
  }
 
  // ramp up backward
  digitalWrite(MOTOR_IN2, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }
 
  // backward full speed for one second
  delay(1000);
 
  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }*/
}
