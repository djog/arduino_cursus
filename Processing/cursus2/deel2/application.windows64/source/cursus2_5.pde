void setup(){
 size(500,500);
 stroke(255);
}

void draw(){
 background(0); 
 if(mousePressed){
  fill(0,255,0); 
 }
 else{
  fill(0,0,255); 
 }
 ellipse(mouseX,mouseY,100,100);
}
