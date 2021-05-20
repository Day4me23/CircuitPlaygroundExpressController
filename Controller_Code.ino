#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>
#include <Keyboard.h>
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>
#define CAP_THRESHOLD   900
#define DEBOUNCE        250
//variables
uint8_t pads[] = {1, 2, 3, 6};
uint8_t numberOfPads = sizeof(pads)/sizeof(uint8_t);
bool slideSwitch;
bool isPressed = false;
int counter = 0;

boolean capButton(uint8_t pad) {
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;  
  } else {
    return false;
  } //end else
} //end capButton

void snakeController(uint8_t pad) {
  switch (pad) {
    case 1:
      Keyboard.write(87);
      Serial.println("Key Value W");
      
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.playTone(262, 100);
          break;
    case 2:
      Serial.println("Key Value A");
      Keyboard.write(65); //65
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.playTone(294, 100);
      break;
    case 3:
      Serial.println("Key Value S");
      Keyboard.write(83);
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.playTone(330, 100);
      break;
    case 6:
      Serial.println("Key Value D");
      Keyboard.write(68);
      CircuitPlayground.setPixelColor(6, 255,   0,   0);
      CircuitPlayground.playTone(349, 100);
      break;
    default:
      Serial.println("error");
  } //end switch
} //end snakeController

void pongController(uint8_t pad) {
  switch (pad) {
    case 1:
      Serial.println("Key Value F");
      Keyboard.write(70);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.playTone(392, 100);
          break;
    case 2:
      Serial.println("Key Value C");
      Keyboard.write(67);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.playTone(440, 100);
      break;
    case 3:
      Serial.println("Key Value M");
      Keyboard.write(77);
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.playTone(494, 100);
      break;
    case 6:
      Serial.println("Key Value J");
      Keyboard.write(74);
      CircuitPlayground.setPixelColor(6, 255,   0,   0);
      CircuitPlayground.playTone(523, 100);
      break;
    default:
      Serial.println("error");
  } //end switch
} //end snakeController

void setup() {
  Serial.begin(9600); 
  CircuitPlayground.begin();
  Keyboard.begin();
}

void loop() {
  slideSwitch = CircuitPlayground.slideSwitch();
  if (slideSwitch) {
    //Current Game: Snake
  CircuitPlayground.setPixelColor(0, 0,   255,   0);
  CircuitPlayground.setPixelColor(1, 0, 255,   0);
  CircuitPlayground.setPixelColor(2, 0, 255,   0);
  CircuitPlayground.setPixelColor(3, 0, 255, 0);
  CircuitPlayground.setPixelColor(4, 0,   255, 0); 
  CircuitPlayground.setPixelColor(5, 0, 255, 0);
  CircuitPlayground.setPixelColor(6, 0, 255, 0);
  CircuitPlayground.setPixelColor(7, 0, 255, 0);
  CircuitPlayground.setPixelColor(8, 0, 255, 0);
  CircuitPlayground.setPixelColor(9, 0, 255, 0);
      
    for (int i=0; i<numberOfPads; i++) {
    if (capButton(pads[i])) {
      //Send to snakeController method
      snakeController(pads[i]);
      delay(10);
    } //end if
} //end for
  } else {
    //Current Game: Pong
  CircuitPlayground.setPixelColor(0, 0,   0,   255);
  CircuitPlayground.setPixelColor(1, 0, 0,   255);
  CircuitPlayground.setPixelColor(2, 0, 0,   255);
  CircuitPlayground.setPixelColor(3, 0, 0, 255);
  CircuitPlayground.setPixelColor(4, 0,   0, 255);
  CircuitPlayground.setPixelColor(5, 0, 0, 255);
  CircuitPlayground.setPixelColor(6, 0, 0, 255);
  CircuitPlayground.setPixelColor(7, 0, 0, 255);
  CircuitPlayground.setPixelColor(8, 0, 0, 255);
  CircuitPlayground.setPixelColor(9, 0, 0, 255);
  
    for (int i=0; i<numberOfPads; i++) {
    if (capButton(pads[i])) {
      //Send to takeAction method
      pongController(pads[i]);
      delay(10);
    } //end if
} //end for
  } //end else
} //end loop
