
int x=0;
int y=0;

void setup () {
  size (650, 650 );
  background(255);
  
  
}
void draw() {
  background(255);
  fill(0);
  figura();
 
 
 
}
void keyPressed() {
  switch(keyCode) {
  
  //izquierda
  case 37:
  
   if ((y>110&&y<318&&x==175)||(y>300&&y<480&&x==505))
    {
      background(255, 0, 0);
    } else
    {
      if (x>5)
      {
        x=x-5;
      }
    }
    break;
  

  //arriba
  case 38:
  if ((x>130&&x<318&&y==175)||(x>300&&x<510&&y==505))
    {
       background(255, 0, 0);
    }
    else
    {
    if (y>5)
    {
      y=y-5;
    }
    }
    break;

    //derecha
  case 39:
  if ((y>110&&y<312&&x==100)||(y>300&&y<500&&x==430))
    {
      background(255, 0, 0);
    } else
    {
      if (x<600)
      {
        x=x+5;
      }
    }
    break;

    //abajo
  case 40:
  if ((x>104&&x<320&&y==110)||(x>300&&x<500&&y==430))
    {
      background(255, 0, 0);
    } else
    {
      if (y<600)
      {
        y=y+5;
      }
    }
   
    break;
  }
}


void figura() {

beginShape(); //Trabajar en un lugar en especifico para unir puntos

beginShape();
strokeWeight(1);
fill(255,0,0);
vertex(10+x,20+y);
vertex(15+x,20+y);
vertex(15+x,15+y);
vertex(20+x,15+y);
vertex(20+x,10+y);
vertex(45+x,10+y);
vertex(45+x,15+y);
vertex(50+x,15+y);
vertex(50+x,20+y);
vertex(55+x,20+y);
vertex(55+x,30+y);
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(10+x,30+y);
vertex(10+x,20+y);
endShape();

beginShape();
strokeWeight(1);
fill(255,235,205);
vertex(15+x,30+y);
vertex(15+x,40+y);
vertex(20+x,40+y);
vertex(20+x,45+y);
vertex(45+x,45+y);
vertex(45+x,40+y);
vertex(50+x,40+y);
vertex(50+x,30+y);
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(15+x,30+y);
endShape();

 fill(0);
 rect(25+x,25+y,5,7);
 rect(35+x,25+y,5,7); 
 
 
 stroke(#D0D2D8);     
  strokeWeight(30);    
  line(170, 170, 320, 170);
  line(170, 170, 170, 310);  
  line(500, 500, 350, 500);
  line(500, 500, 500, 350);
  
  stroke(#D0D2D8);
  strokeWeight(20);
  line(0, 0, 650, 0);
  line(0, 0, 0, 650);
  line(0, 650, 650, 650);
  line(650, 0, 650, 650);
 
 
}