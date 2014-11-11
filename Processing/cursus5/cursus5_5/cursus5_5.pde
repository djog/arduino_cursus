PImage plaatje;

void setup(){
 size(500,650);
 plaatje = loadImage("arduino.png"); 
 //background(plaatje);
}

void draw(){ 
 tint(0,150,0);
 image(plaatje,0,0);
}
