// seven-segment display example code

int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int H = 9;

void setup() {
  // set some stuff up
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
}

void loop() {
  // do some stuff over and over...
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  delay(1000);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  delay(1000);
}
