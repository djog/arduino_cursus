// seven-segment display example code with functions

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
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
}

void loop() {
  // do some stuff over and over...
  showOne();
  showTwo();
}

int showOne(){
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  delay(1000);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  delay(1000);
}

int showTwo(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(G, LOW);
  delay(1000);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
  delay(1000);
}
