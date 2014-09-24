/*************************************************** 
  Adafruit Trinket-based Room Occupancy sensor and display
  
  Featuring a Trinket 5V and the
  8x8 Bi-color LED Matrix and I2C Backpack
  
  For Trinket, this program is within 100 bytes of the maximum
    code size of 5,310 bytes.  Adding significantly more
    functionality may not be possible.  Both Adafruit
    libraries are currently required.
 ****************************************************/

#include <TinyWireM.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

const int lightPin = 1;    // photoresistor on Trinket Pin #1
boolean occupied = 0;

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

unsigned long elapsedTime; // time tracking

void setup() {
  
  pinMode(lightPin, INPUT); // Initial state is low
  matrix.begin(0x70);     // pass in the address
}

static const uint8_t PROGMEM   // X and square bitmaps
  x_bmp[] =
  { B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00100100,
    B01000010,
    B10000001 },
    
  circle_bmp[] =
  { B00111100,
    B01000010,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01000010,
    B00111100 },
    
  exclamation_bmp[] =
  { B00000000,
    B00000000,
    B00000000,
    B11011111,
    B11011111,
    B00000000,
    B00000000,
    B00000000 };
    

void loop() {
  
  elapsedTime = millis();
  
  if (elapsedTime < 3000) {
    
    matrix.clear();
    matrix.drawBitmap(0, 0, exclamation_bmp, 8, 8, LED_YELLOW);
    matrix.writeDisplay();
    
    
  } else if (millis() < 6000) {

    //int sense = analogRead(lightPin);  // Read light Sensor
  
    matrix.clear();
    matrix.drawBitmap(0, 0, circle_bmp, 8, 8, LED_GREEN);
    matrix.writeDisplay();
    
  }
  
  
  

//  if(sense <= 200) {     // If high and it was low, sensor tripped
//    if(occupied == false) { //   and we display a red X
//      matrix.clear();
//      matrix.drawBitmap(0, 0, x_bmp, 8, 8, LED_RED);
//      matrix.writeDisplay();
//      occupied = true;
//    }
//  } else {
//    if(occupied == false) {  // If low and state was high, sensor set
//      matrix.clear();       //  and we sisplay a green box
//      matrix.drawBitmap(0, 0, box_bmp, 8, 8, LED_GREEN);
//      matrix.writeDisplay();
//      occupied = false;
//    }
//  }

}
