
#define UpperThreshold  445
#define  LowerThreshold  425


bool BPMTime = false;
bool BeatComplete = false;
int BPM = 0;
int HRreturn;
int HRcount = 0;
bool HRvalid = false;
int hrSensor = A0;
unsigned long LastTime = 0;
int x = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(5, INPUT);
pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
HRreturn = takeHR();

if(HRreturn < 160){
  HRvalid = true;
}
else {
  HRvalid = false;
}
if (HRreturn != 0 && (HRreturn < 45 || HRreturn > 100) && HRvalid == true) {
  int lastHR = 0;
 
  if (HRreturn != lastHR) {
    HRcount++;
  }
  lastHR = HRreturn;
}
else if (HRreturn != 0 && HRvalid == true){
  if (HRcount > 0){
    HRcount--;
  }
  else if (HRvalid == false) {
    HRcount == 0;
  }
}
}

int takeHR(){
  int falseFlag = 0;
  int newTime;
  int signal = analogRead(hrSensor);
 // Serial.println(signal);
  
  

  if ( signal > UpperThreshold) {
    //Serial.println("nr 1");
    if (BeatComplete) {
     //Serial.println("nr 2");
      newTime = millis();
      BPM = newTime - LastTime;
      BPM = int(60 / (float(BPM) / 1000));
      BPMTime = false;
      BeatComplete = false;
    }
    if (BPMTime == false){
      Serial.println("nr 3");
      LastTime = newTime;
      falseFlag = 1;
      BPMTime = true;
    }
    
  }
  if (signal < LowerThreshold && (BPMTime)){
    BeatComplete = true;
   // Serial.println("nr 4");

    Serial.println(BPM);
    Serial.println(" BPM");
    x++;

    
  }
  if (falseFlag){
    //Serial.println("nr 5");
    return 0;
  }
  else {
  return BPM;
  }
}
