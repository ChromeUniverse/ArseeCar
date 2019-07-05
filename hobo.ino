// Back Left
#define BLP 45
#define BL1 35
#define BL2 37

// Front Left
#define FLP 44
#define FL1 41
#define FL2 39

// Back Right
#define BRP 4
#define BR1 34
#define BR2 36

// Front Right
#define FRP 46
#define FR1 40
#define FR2 38

// Infrared
#define IRR A5
#define IRL A6
#define IRC A7

// CSL
#define CSL0 22
#define CSL1 23
#define CSL2 9
#define CSL3 8
#define CSLO 10

// CSR
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
}

int FRS = 255;
int FLS = 255;
int BRS = 255;
int BLS = 255;

void loop() {
  digitalWrite(FR1, HIGH);
  digitalWrite(FR2, LOW);
  digitalWrite(FL1, HIGH);
  digitalWrite(FL2, LOW);
  digitalWrite(BR1, HIGH);
  digitalWrite(BR2, LOW);
  digitalWrite(BL1, HIGH);
  digitalWrite(BL2, LOW);
 
  analogWrite(FRP, FRS);
  analogWrite(FLP, FLS);
  analogWrite(BRP, BRS);
  analogWrite(BLP, BLS);
}
