int x = 0;

void setup(){
 size(500,500);
 fill(0,255,200);
 stroke(200,0,170);
 strokeWeight(5); 
}

void draw(){
 background(0);
 rect(x,200,100,100);
 saveFrame("blokje-##.jpg");
 x=x+4;
 if(x+100 > width){
  exit();
 } 
}
