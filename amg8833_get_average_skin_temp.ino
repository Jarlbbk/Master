/***************************************************************************
  This is a library for the AMG88xx GridEYE 8x8 IR camera

  This sketch tries to read the pixels from the sensor

  Designed specifically to work with the Adafruit AMG88 breakout
  ----> http://www.adafruit.com/products/3538

  These sensors use I2C to communicate. The device's I2C address is 0x69

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
float hud_temp = 0; //to sum up all pixels with value of 30 or more
int number_of_pix = 0; //to add up the number of pixels with a value of 30 or more
float avr_temp;

void setup() {
    Serial.begin(9600);
    Serial.println(F("AMG88xx pixels"));

    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    
    Serial.println("-- Pixels Test --");

    Serial.println();

    delay(100); // let sensor boot up
}


void loop() { 
    get_skin_temp();
}


void get_skin_temp(){
   //read all the pixels
    amg.readPixels(pixels);

    Serial.print("[");
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.print(pixels[i-1]);
      Serial.print(", ");
      if(pixels[i-1]>30){ //this number is not based on anything concrete, must be chosen better
        hud_temp += pixels[i-1]; //add skin temperature value
        number_of_pix += 1; //sum up number of pixels that records skin
      }
      if( i%8 == 0 ) Serial.println();
    }
    Serial.println("]");
    Serial.println();
    avr_temp = hud_temp/number_of_pix; //calculate average skin temperature
    Serial.println(avr_temp);
    if (avr_temp > 31.9){ //this value was randomly picked, should use the average reading done in someone's home over a given time period
      Serial.println("fever detected");
    }
      else {
        Serial.println("Healthy individual");
      
      
    }
    //delay a second
    delay(1000);
}
