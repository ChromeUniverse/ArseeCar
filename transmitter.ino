
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/

int joyPinX = A0;
int joyPinY = A1;
int valueX = 0;
int valueY = 0;

int treatValue(int data) {
  return data;
}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
void setup() { 
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {  
  valueX = analogRead(joyPinX);  
  radio.write(&valueX, sizeof(int));
  delay(50);
}
