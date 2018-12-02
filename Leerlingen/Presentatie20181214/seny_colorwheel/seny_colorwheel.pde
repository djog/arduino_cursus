void setup()
{
  size(256, 256);
}

void draw()
{
  stroke(mouseX, mouseY, mouseX + mouseY);
  line(128, 128, mouseX, mouseY);

  if(mousePressed) 
  {
    background(mouseX, mouseY, mouseX + mouseY);
  }
  
}
