import processing.serial.*;

Serial myPort;

void setup() {
  size(1350, 256);
  background(255);
  stroke(0);
  fill(0);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
}

    int oy = 0;
    int x = 0;
void draw() {
  while (myPort.available() >0) {
    int ny = myPort.read();
    println(ny);
    
    line(x, oy, x+5, ny);
    oy = ny;
    x=x+5;
    
    if(x == width){
     x = 0;
     background(255); 
    }
  }
 
}
