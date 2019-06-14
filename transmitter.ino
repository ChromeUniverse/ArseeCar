/*
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

int joyPinX = A0;
int joyPinY = A1;
String xAxis, yAxis;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

char xyData[32] = "";

void setup() { 
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {  
  xAxis = analogRead(A0); // Read Joysticks X-axis
  yAxis = analogRead(A1); 
  
  xAxis.toCharArray(xyData, 5); 
  radio.write(&xyData, sizeof(xyData));
  
  yAxis.toCharArray(xyData, 5);
  radio.write(&xyData, sizeof(xyData));
    
  delay(20);
}
