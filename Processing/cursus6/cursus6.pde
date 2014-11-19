PFont font;
String[] lijst = PFont.list();
int i = 0;
int tijd = 0;

void setup(){
size(500,500);
fill(0);
stroke(0);
tijd = millis();
}

void draw(){
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
