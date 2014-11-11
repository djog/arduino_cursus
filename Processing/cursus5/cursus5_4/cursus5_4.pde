PrintWriter writer;
void setup(){
 writer = createWriter("bestand.txt");
 size(500,500); 
}

void draw(){
  writer.print(mouseX + " en ");
  writer.println(mouseY);
  if(mousePressed == true){
   writer.flush();
   writer.close();
   exit(); 
  }
}
