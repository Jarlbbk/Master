//This code is for bluetooth comunication between the Bluetooth mate silver from Sparkfun, using the RN-42. This 
//is a class 2 Bluetooth, meaning it can transmit up to 10 meters (class 1 can transmit 
// 100 meters, but is uneccessary for this project), class 2 also consumes less power than class 1
#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h> //allows for serial comunication on other 
//digital pins than 0 and 1


class Bluetooth
{
private:
    int bluetoothTx; // TX-O pin of bluetooth mate
    int bluetoothRx; // RX-I pin of bluetooth mate
    SoftwareSerial bluetooth;
    float* arr;
public:
    Bluetooth(int tx, int rx, float* arr); //the array is a pointer 
    //ti its first elemnt, must be declared in main loop function
    //it will contain all values that are to be sent
    ~Bluetooth();
    void setup();
    void loop();
};
//data package:
//temp: average temp after passing magnet second time, otherwise 0
//time: 0 during negotiation, time after passing magnet
//pulse: average after passing second magnet, otherwise 0
//fall alarm: only value that is measured and sent during negotiation
//IR camera: average after passing second magnet,  otherwise 0

/* if(Serial.available())  //this might be something to add, check if there is any data to send over bluetooth
  {
    
    bluetooth.print((char)Serial.read());
   
}*/




