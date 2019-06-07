int joyPinX = A0;
int joyPinY = A1;
int valueX = 0;
int valueY = 0;

void setup() {
  Serial.begin(9600);
}

int treatValue(int data) {
  return data;
}

void loop() {
  valueX = analogRead(joyPinX);
  delay(100);
  valueY = analogRead(joyPinY);

  Serial.print(treatValue(valueX));
  Serial.print(" ");
  Serial.println(treatValue(valueY));
}
