/*
 Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo myServo;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  myServo.attach(3);
}

int treatValue(int x) {
  return map(x, 0, 690, 0, 180); 
}

int i = 0; 
void loop() {
  if (radio.available()) {
 /*
    Serial.print("READING ");
    Serial.print(++i);
    Serial.print(": ");
    
    int x;
    radio.read(&x, sizeof(int));
    Serial.print(x);

    Serial.print("-->");

    Serial.println(treatValue(x));
    myServo.write(treatValue(x));
  }
}
