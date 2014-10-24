import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class arduinoGrafiek extends PApplet {



Serial myPort;  // The serial port

public void setup() {
  size(1350, 256);
  background(255);
  stroke(0);
  fill(0);
  // List all the available serial ports
  println(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
}

    int oy = 0;
    int x = 0;
public void draw() {
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
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--full-screen", "--bgcolor=#666666", "--stop-color=#cccccc", "arduinoGrafiek" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
