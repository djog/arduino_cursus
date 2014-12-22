int d = 20;
int e;
int y = 5;
String typed = "";


void setup() {
  size(500,500);
  background(0);
  stroke(255);  
  fill(0,255,0);
  textSize(20);
}

void draw() {
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

void keyPressed(){
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

void mouseClicked(){
  if(mouseButton == LEFT){
   d = d+5;
  }
  else if(mouseButton == RIGHT){
   d = d-5;
  } 
}

void mouseWheel(MouseEvent event) {
  fill(0);
  noStroke();
  rect(0,0,90,90);
  fill(0,255,0);
  stroke(255);
  e = event.getCount();
}

