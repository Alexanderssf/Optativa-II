int i=0;
int j=0;
int k=0;
int y1=1000;
int y2=600;
void setup (){
  background(255);
  size(1700,800);
}
void draw() {
  background(255);
  fill(0);
  
  {
    if (j<0){
      j=j+20;
    }
      else
     {
       dino0();
     }
  }
    
  fill(255,0,0);
  ellipse(600,y1,50,50);
  if(y1>0){
  y1=y1-5;
  }
  else
  y1=800;
  

  
  fill(255,0,0);
  ellipse(1200,y2,50,50);
  if(y2>0){
  y2=y2-5;
  }
  else
  y2=800;
  
}
void keyPressed() {
 
  switch (keyCode) {
  case 37:    //Izquierda
    i=i-10;
    break;

  case 39:      //Derecha
    i=i+10;
    break;
  }
}


void dino0()
{
  beginShape();     //Inicia el vertice
  noStroke();
  vertex(300+i,50+j);
  vertex(300+i,65+j);
  vertex(285+i,65+j);
  vertex(285+i,155+j);
  vertex(270+i,155+j);
  vertex(270+i,170+j);
  vertex(255+i,170+j);
  vertex(255+i,185+j);
  vertex(240+i,185+j);
  vertex(240+i,200+j);
  vertex(225+i,200+j);
  vertex(225+i,215+j);
  vertex(195+i,215+j);
  vertex(195+i,200+j);
  vertex(180+i,200+j);
  vertex(180+i,185+j);
  vertex(165+i,185+j);
  vertex(165+i,155+j);
  vertex(150+i,155+j);
  vertex(150+i,230+j);
  vertex(165+i,230+j);
  vertex(165+i,245+j);
  vertex(180+i,245+j);
  vertex(180+i,260+j);
  vertex(195+i,260+j);
  vertex(195+i,275+j);
  vertex(210+i,275+j);
  vertex(210+i,290+j);
  vertex(225+i,290+j);
  vertex(225+i,350+j);
  vertex(255+i,350+j);
  vertex(255+i,335+j);
  vertex(240+i,335+j);
  vertex(240+i,320+j);
  vertex(255+i,320+j);
  vertex(255+i,305+j);
  vertex(270+i,305+j);
  vertex(270+i,290+j);
  vertex(285+i,290+j);
  vertex(285+i,305+j);
  vertex(300+i,305+j);
  vertex(300+i,350+j);
  vertex(330+i,350+j);
  vertex(330+i,335+j);
  vertex(315+i,335+j);
  vertex(315+i,275+j);
  vertex(330+i,275+j);
  vertex(330+i,260+j);
  vertex(345+i,260+j);
  vertex(345+i,245+j);
  vertex(360+i,245+j);
  vertex(360+i,200+j);
  vertex(375+i,200+j);
  vertex(375+i,215+j);
  vertex(390+i,215+j);
  vertex(390+i,185+j);
  vertex(360+i,185+j);
  vertex(360+i,155+j);
  vertex(420+i,155+j);
  vertex(420+i,140+j);
  vertex(375+i,140+j);
  vertex(375+i,125+j);
  vertex(450+i,125+j);
  vertex(450+i,65+j);
  vertex(435+i,65+j);
  vertex(435+i,50+j);
  vertex(300+i,50+j);
 endShape();
 
 fill(255,255,255);
 beginShape();
  vertex(315+i,75+j);
  vertex(315+i,90+j);
  vertex(330+i,90+j);
  vertex(330+i,75+j);
  vertex(315+i,75+j);
 endShape(); 
 
 }


  