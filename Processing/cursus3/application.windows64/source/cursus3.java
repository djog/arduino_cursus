import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class cursus3 extends PApplet {

int time;
int x = 0;
int delay = 50;

public void setup(){
 size(500,500);
 time = millis(); 
}

public void draw(){
 background(255);
 fill(0,255,0);
 rect(x,200,100,100);
 
 if(millis() - time >= delay)
  {
   ++x;
   
   println(millis() - time);
   time = millis();
  }
  
}

  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--full-screen", "--bgcolor=#666666", "--stop-color=#cccccc", "cursus3" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
