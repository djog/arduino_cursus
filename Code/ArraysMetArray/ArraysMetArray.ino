const int pins[] = { 2,3,4,5,6,7,8,9,10,11,12 };
const int n_pins = 12;

void setup()
{
  //Naief
  pinMode(pins[ 0],OUTPUT); //C++ begint bij index nul te tellen
  pinMode(pins[ 1],OUTPUT);
  pinMode(pins[ 2],OUTPUT);
  pinMode(pins[ 3],OUTPUT);
  pinMode(pins[ 4],OUTPUT);
  pinMode(pins[ 5],OUTPUT);
  pinMode(pins[ 6],OUTPUT);
  pinMode(pins[ 7],OUTPUT);
  pinMode(pins[ 8],OUTPUT);
  pinMode(pins[ 9],OUTPUT);
  pinMode(pins[10],OUTPUT);
  pinMode(pins[11],OUTPUT);
  //pinMode(pins[12],OUTPUT); //Nee, pins[12] bestaat niet, omdat C++ bij index nul begint te tellen!
  
  //Hetzelfde, maar dan slimmer
  for (int i{0}; i!=n_pins; ++i) //Vaak in boeken: 'for(int i=0; i<n_pins; i++)'
  { 
    pinMode(pins[i],OUTPUT); 
  }
}

void loop()
{
  for (int i{0}; i!=n_pins; ++i) //Vaak in boeken: 'for(int i=0; i<n_pins; i++)'
  {
    digitalWrite(pins[i],HIGH);
  }
  delay(1000);
  for (int i{0}; i!=n_pins; ++i) //Vaak in boeken: 'for(int i=0; i<n_pins; i++)'
  {
    digitalWrite(pins[i],HIGH);
  }
  delay(1000);
}
