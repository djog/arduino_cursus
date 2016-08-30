//Shape
PShape arduino = createShape(GROUP);
PShape begin = createShape(ARC, -15, 0, 20, 20, HALF_PI, PI+HALF_PI);
begin.setFill(false);
PShape end = createShape(ARC, 15, 0, 20, 20, -HALF_PI, HALF_PI);
end.setFill(false);
PShape middle = createShape();
middle.beginShape();
middle.noFill();
middle.vertex(-15, -10);
middle.bezierVertex(0, -10, 0, 10, 15, 10);
middle.endShape();
PShape middle_ = createShape();
middle_.beginShape();
middle_.noFill();
middle_.vertex(-15, 10);
middle_.bezierVertex(0, 10, 0, -10, 15, -10);
middle_.endShape();
begin.setStrokeWeight(5);
end.setStrokeWeight(5);
middle.setStrokeWeight(5);
middle_.setStrokeWeight(5);
arduino.addChild(begin);
arduino.addChild(middle_);
arduino.addChild(middle);
arduino.addChild(end);

//Colors
color[] c = new color[5];
c[0] = color(#00878F);
c[1] =  color(#62AEB2);
c[2] =  color(#E47128);
c[3] =  color(#E5AD24);
c[4] =  color(#8C7965);
//Background
PImage logo = loadImage("djoglogo.png");
size(1000, 1414);
background(255);
rectMode(CENTER);
int w = width/50;
noFill();
for (int i=w/2; i!=width+w/2; i+=w) {
  for (int o=0; o<height; o+=w) {
    pushMatrix();
    translate(i, o);
    rotate(random(TWO_PI));
    scale(map(1, 0, 50, 0, w));
    color s = c[int(random(5))];
    begin.setStroke(s);
    end.setStroke(s);
    middle.setStroke(s);
    middle_.setStroke(s);
    shape(arduino);
    popMatrix();
  }
}

//Text
fill(255,150);
noStroke();
rect(width/2, height/2, width*.75, height*.75);
fill(0);
PFont head = createFont("Source Code Pro", 32*2);
PFont font = createFont("Source Code Pro", 16*2);
PFont bold = createFont("Source Code Pro Bold", 26*2);
textFont(head);
textAlign(LEFT, TOP);
String[] text = loadStrings("file.txt");
text(text[0], width/8, height/8);
textFont(bold);
text("De Jonge Onderzoekers", width/8, height/8+32*2);
text(text[1], width/8, height/8+(3*32)*2);

text(text[5], width/8, height/8+(4*32+26+2*16)*2);
text(text[8], width/8, height/8+(5*32+2*26+4*16)*2);
text(text[11], width/8, height/8+(6*32+3*26+6*16)*2);
textFont(font);
text(text[2], width/8, height/8+(3*32+26)*2);
text(text[3], width/8, height/8+(3*32+26+16)*2);
text(text[4], width/8, height/8+(3*32+26+16+16)*2);

text(text[6], width/8, height/8+(4*32+2*26+2*16)*2);
text(text[7], width/8, height/8+(4*32+2*26+3*16)*2);
text(text[9], width/8, height/8+(5*32+3*26+4*16)*2);
text(text[10], width/8, height/8+(5*32+3*26+5*16)*2);
text(text[12], width/8, height/8+(6*32+4*26+6*16)*2);
textAlign(RIGHT, BOTTOM);
text(text[13], width*7/8, height*7/8);
image(logo, width-472, height-76);
save("poster_kleur.jpg");