/*

RgbMatrix

(C) 2015 Richel Bilderbeek

Verbind:
 * pin_anode[0] met matrix pin 1
 * pin_anode[1] met matrix pin 2
 * pin_anode[2] met matrix pin 3
 * pin_anode[3] met matrix pin 4
 * pin_green[0] met matrix pin 5
 * pin_green[1] met matrix pin 6
 * pin_green[2] met matrix pin 7
 * pin_green[3] met matrix pin 8

*/

const int pin_anode[] = { 2,3,4,5 };
const int n_anodes = 4;

const int pin_green[] = { 8,9,10,11 };
const int n_greens = 4;

const int width  = 4;
const int height = 4;

//The RGB intensities of the green LEDs
int greens[width][height];

void setup()
{
  Serial.begin(9600);
  for (int i=0; i!=n_anodes; ++i) 
  { 
    pinMode(pin_anode[i],OUTPUT);
  }
  for (int i=0; i!=n_greens; ++i) 
  { 
    pinMode(pin_green[i],OUTPUT);
  }
  Serial.println("Start");
  for (int x=0; x!=width; ++x)
  {
    for (int y=0; y!=height; ++y)
    {
      digitalWrite(pin_anode[y],LOW);
      digitalWrite(pin_green[x],HIGH);
    }
  }
}

void SetGreen(const int x, const int y, const int intensity)
{
  const int x_index = x;
  const int y_index = height - 1 - y;
  if (x_index < 0) { Serial.println("x_index < 0"); delay(10000); }
  if (y_index < 0) { Serial.println("y_index < 0"); delay(10000); }
  if (x_index > width) { Serial.println("x_index > width"); delay(10000); }
  if (y_index > height) { Serial.println("y_index < height"); delay(10000); }
  greens[x_index][y_index] = intensity; 
}

int GetGreen(const int x, const int y)
{
  return greens[x][height - 1 - y];
}

void ShowGreen()
{
  for (int x=0; x!=width; ++x)
  {
    for (int y=0; y!=height; ++y)
    {
      if (pin_anode[x],greens[x][y] > 0)
      {
        digitalWrite(pin_anode[y],HIGH);
        digitalWrite(pin_green[x],LOW);
        
        digitalWrite(pin_anode[y],LOW);
        digitalWrite(pin_green[x],HIGH);
      }

    }
  }
}

long int last_time = -1000;

void loop()
{
  const long this_time = millis();
  if (this_time - last_time > 100)
  {
    static int cnt = 0;
    const int x = cnt % 4;//rand() % width;
    const int y = (cnt / 4) % 4; //rand() % height;
    SetGreen(x,y,GetGreen(x,y) == 0 ? 255 : 0);
    last_time = this_time;
    ++cnt;
  }
  ShowGreen();
}
