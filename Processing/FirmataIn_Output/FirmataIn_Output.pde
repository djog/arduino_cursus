import processing.serial.*;
import org.firmata.*;
import cc.arduino.*;

int time;
boolean led = false;
color bg;

Arduino uno;

void setup(){
 size(500,500);
 noStroke();
 fill(0,0,255);
 println(Arduino.list());
 uno = new Arduino(this, Arduino.list()[0], 57600);
 uno.pinMode(13,Arduino.OUTPUT);
 time = millis(); 
}

void draw(){
  background(bg);
  
  if(millis() - time >= 1000){
    println(led);
    if(led == false){
    uno.digitalWrite(13,Arduino.HIGH);
    bg = color(0,255,0);
    led = true;
    }
    else{
    uno.digitalWrite(13,Arduino.LOW);
    bg = color(0);
    led = false;
    }
    time = millis();
  }
  
  rectMode(CENTER);
  fill(0,0,255);
  rect(width/2,height/2,map(uno.analogRead(0),0,1023,0,width),
                        map(uno.analogRead(0),0,1023,height,0));
  
}

