#include "M5Core2.h"
#include "bin.h"

#define gray 0xC618
#define blue 0x0311
#define green 0x046C
#define red 0xFB63
#define darkred 0xFB63

int fromLeft=20;
int space=6;
int r=30;
int x[8]={};
bool b[8]={0};
int colors[2]={darkred,blue};
int y=210;
int start=128;
int selected=0;
int tselected=0;
byte number=0;
byte tnumber=0;



void setup()
    {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setSwapBytes(true);
  M5.Lcd.pushImage(134,6,180,70,BINa);
  for(int i=0;i<8;i++)
    {
      x[i]=fromLeft+(r*i)+(space*i);
      M5.Lcd.fillCircle(x[i]+14,y,r/2,red);
      
      M5.Lcd.drawRect(x[i],y-60,r,r+2,gray);
      M5.Lcd.drawString(String(start),x[i],y-70,1);
      M5.Lcd.drawString("0",x[i]+8,y-55,4);
      M5.Lcd.drawString(String(number),20,y-130,7);
      start=start/2;
    }
  M5.Lcd.drawCircle(x[0]+14,y,(r/2)+5,WHITE);
  M5.Lcd.drawCircle(x[0]+14,y,(r/2)+4,WHITE);
  
  M5.Lcd.drawLine(140,4,140,128,gray);
  M5.Lcd.drawLine(140,128,300,128,gray);

  M5.Lcd.fillRect(20,50,110,20,blue);
  M5.Lcd.fillRect(20,4,110,20,darkred);
  M5.Lcd.setTextColor(WHITE,blue);
  M5.Lcd.drawString("DECIMAL",40,52,2);
  M5.Lcd.setTextColor(BLACK,darkred);
  M5.Lcd.drawString("HEXADECIMAL",30,6,2);
  M5.Lcd.setTextColor(WHITE,BLACK);
  M5.Lcd.drawString("0x0",28,30,2);
  
}

void loop() {

  if(tselected!=selected)
  {
  M5.Lcd.drawCircle(x[tselected]+14,y,(r/2)+5,BLACK);
  M5.Lcd.drawCircle(x[tselected]+14,y,(r/2)+4,BLACK);
  M5.Lcd.drawCircle(x[selected]+14,y,(r/2)+5,WHITE);
  M5.Lcd.drawCircle(x[selected]+14,y,(r/2)+4,WHITE);
  tselected=selected;
  
  }
  if(M5.BtnA.wasPressed())
    {
    selected=selected-1;
    if(selected<0)
    selected=7;
    }
    if(M5.BtnC.wasPressed())
    {
    selected=selected+1;
    if(selected>7)
    selected=0;
    }

     if(M5.BtnB.wasPressed())
    {
   b[selected]=!b[selected];
   M5.Lcd.fillCircle(x[selected]+14,y,r/2,colors[b[selected]]);
   M5.Lcd.drawString(String(b[selected]),x[selected]+8,y-55,4);
    bitWrite(number, 7-selected, b[selected]);
    }

if(tnumber!=number)
  {
  M5.Lcd.drawString("0x",28,30,2);
  M5.Lcd.fillRect(15,74,110,58,BLACK);
  M5.Lcd.setCursor(42,30,2);
  M5.Lcd.print(number,HEX);
  M5.Lcd.drawString(String(number),24,y-130,7);
 
  tnumber=number;
  }
    
M5.update();
}
