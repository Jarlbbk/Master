#include <Bluetooth.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

Bluetooth::Bluetooth(int tx, int rx, float* arr): bluetoothTx{tx}, bluetoothRx{rx}, bluetooth(tx,rx), arr{arr}
{
}

void Bluetooth::setup(){
    //the following was copied from project from https://learn.sparkfun.com/tutorials/using-the-bluesmirf/example-code-using-command-mode
    //not sure if needed
    bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
    bluetooth.print("$");  // Print three times individually
    bluetooth.print("$");
    bluetooth.print("$");  // Enter command mode
    delay(100);  // Short delay, wait for the Mate to send back CMD
    bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
    // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
    bluetooth.begin(9600);  // Start bluetooth serial at 9600
}

void Bluetooth::loop(){
    for (int i=0; i<3;i++){ //loop the amount of elements in arr
        bluetooth.println(arr[i]);
    }
}

Bluetooth::~Bluetooth()
{
}



