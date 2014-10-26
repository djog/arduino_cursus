int time;
int x = 0;
int delay = 50;

void setup(){
 size(500,500);
 time = millis(); 
}

void draw(){
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

