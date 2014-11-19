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

public class cursus6 extends PApplet {

PFont font;
String[] lijst = PFont.list();
int i = 0;
int tijd = 0;

public void setup(){
size(500,500);
fill(0);
stroke(0);
tijd = millis();
}

public void draw(){
 background(255);
 font = createFont(lijst[i],30);
 textFont(font);
 text("Allemaal verschillende lettertypes!",0,30,500,500);
 if(millis()-tijd >= 100){
   ++i;
   println(i);
   if(i >= lijst.length){
     i=0;
   }
   tijd = millis();
 }
 
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--full-screen", "--bgcolor=#21FF00", "--stop-color=#FFFFFF", "cursus6" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
