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

public class cursus7 extends PApplet {

int d = 20;
int e;
int y = 5;
String typed = "";


public void setup() {
  size(500,500);
  background(0);
  stroke(255);  
  fill(0,255,0);
  textSize(20);
}

public void draw() {
  background(0);
  line(0,100,500,100);
  line(100,0,100,500);
  ellipse(mouseX,mouseY,d,d);
  textAlign(CENTER);
  text(e,50,60);
  text(y,50,450);
  textAlign(LEFT);
  text(typed,150,50);
  rect(25,100,50,y);
}

public void keyPressed(){
  if(key != DELETE){
   typed = typed + key;
  }
  else if(key == DELETE){
   typed = "";
  } 
  if(keyCode == UP){
    y = y-5;
  }
  else if(keyCode == DOWN){
    y = y+5;
  }
}

public void mouseClicked(){
  if(mouseButton == LEFT){
   d = d+5;
  }
  else if(mouseButton == RIGHT){
   d = d-5;
  } 
}

public void mouseWheel(MouseEvent event) {
  fill(0);
  noStroke();
  rect(0,0,90,90);
  fill(0,255,0);
  stroke(255);
  e = event.getCount();
  println(e);
}

  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--full-screen", "--bgcolor=#03FA10", "--stop-color=#FF0000", "cursus7" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
