int baseSpeed = 70;
int blackThreshold = 400;
int defaultDelay = 50;
double kp = 0.5;

// Back Left
#define BLP 45
#define BL1 37
#define BL2 35

// Front Left
#define FLP 44
#define FL1 39
#define FL2 41

// Back Right
#define BRP 4
#define BR1 36
#define BR2 34

// Front Right
#define FRP 46
#define FR1 40
#define FR2 38

// Infrared
#define IRL A7
#define IRC A6
#define IRR A5

// Color Sensor Left
#define CSL0 22
#define CSL1 23
#define CSL2 9
#define CSL3 8
#define CSLO 10

// Color Sensor Right
#define CSR0 52
#define CSR1 53
#define CSR2 5
#define CSR3 7
#define CSRO 6


void setup() {
    pinMode(FRP, OUTPUT);
    pinMode(FLP, OUTPUT);
    pinMode(BRP, OUTPUT);
    pinMode(BLP, OUTPUT);

    pinMode(FR1, OUTPUT);
    pinMode(FR2, OUTPUT);

    pinMode(FL1, OUTPUT);
    pinMode(FL2, OUTPUT);

    pinMode(BR1, OUTPUT);
    pinMode(BR2, OUTPUT);

    pinMode(BL1, OUTPUT);
    pinMode(BL2, OUTPUT);

    pinMode(IRL, INPUT);
    pinMode(IRC, INPUT);
    pinMode(IRR, INPUT);

    Serial.begin(9600);

/* COLOR SENSORS
    pinMode(CSL0, OUTPUT);
    pinMode(CSL1, OUTPUT);
    pinMode(CSL2, OUTPUT);
    pinMode(CSL3, OUTPUT);
    pinMode(CSLO, INPUT);

    pinMode(CSR0, OUTPUT);
    pinMode(CSR1, OUTPUT);
    pinMode(CSR2, OUTPUT);
    pinMode(CSR3, OUTPUT);
    pinMode(CSRO, INPUT);
*/
}

int FRS = 255;
int FLS = 255;
int BRS = 255;
int BLS = 255;

int valIRL = 0;
int valIRR = 0;
int valIRC = 0;

void updateIR() {
    valIRL = analogRead(IRL);
    valIRC = analogRead(IRC);
    valIRR = analogRead(IRR);

    Serial.print("Updated IR sensors (L - C - R): ");
    Serial.print(IRL);
    Serial.print(" - ");
    Serial.print(IRC);
    Serial.println(" - " );
}

/*
    LEFT = -1
    AHEAD = 0
    RIGHT = +1
*/

void setMotorDirection(int direction) {

    // All Ahead
    digitalWrite(FR1, HIGH);
    digitalWrite(FR2, LOW);
    digitalWrite(FL1, HIGH);
    digitalWrite(FL2, LOW);
    digitalWrite(BR1, HIGH);
    digitalWrite(BR2, LOW);
    digitalWrite(BL1, HIGH);
    digitalWrite(BL2, LOW);

    if (direction == -1) {

        // Revert Left
        digitalWrite(FL1, LOW);
        digitalWrite(FL2, HIGH);
        digitalWrite(BL1, LOW);
        digitalWrite(BL2, HIGH);
    } else if (direction == 1) {

        // Revert Right
        digitalWrite(FR1, LOW);
        digitalWrite(FR2, HIGH);
        digitalWrite(BR1, LOW);
        digitalWrite(BR2, HIGH);
    }
}

void setMotorSpeed(int motorID, int motorSpeed) {
    if (motorSpeed < 0) motorSpeed = 0;
    if (motorSpeed > 255) motorSpeed = 255;

    analogWrite(motorID, motorSpeed);
}

void setAllMotorSpeed(int BLS, int BRS, int FLS, int FRS) {
    setMotorSpeed(BLP, BLS);
    setMotorSpeed(BRP, BRS);
    setMotorSpeed(BLP, FLS);
    setMotorSpeed(BLP, FRS);
}

bool isOnTrack() {
    if (valIRC >= blackThreshold) return true;
    return false; 
}

int getError() { return IRL-IRR; }

void move(int turnDirection, int motorSpeed, int moveDelay=defaultDelay) {

/*
    if (turnDirection < 0) setMotorDirection(-1);
    else if (turnDirection == 0) setMotorDirection(0);
    else (turnDirection > 0) setMotorDirection(1);
*/

    int rightSpeed = motorSpeed - kp*turnDirection;
    int leftSpeed = motorSpeed + kp*turnDirection;

    setMotorSpeed(leftSpeed, rightSpeed, leftSpeed, rightSpeed);

    delay(moveDelay);
}

void followLine() {
    int turnDirection = -getError();
    move(turnDirection, turnSpeed);
}

void loop() {
    updateIR();    
    followLine();
}
