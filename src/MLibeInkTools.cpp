#include<MLibeInkTools.h>


void clearEInk(GxDEPG0213BN &display, int16_t x, int16_t y, int16_t w, int16_t h, int16_t col, bool updt)
{
  display.fillRect(x, y, w, h, col);
  if (updt) display.updateWindow(x,y,w,h);  
}

void clearEInk(GxDEPG0213BN &display, const String &s, int16_t curx, int16_t cury, int16_t col, bool updt)
{
  int16_t x, y;
  uint16_t w, h;
  display.getTextBounds(s, curx, cury, &x, &y, &w, &h);
  clearEInk(display, x-1, y-1, w+2, h+2, col, false);  
  if (updt) display.updateWindow(x-1,y-1,w+2,h+2);  
}

void writeEInk(GxDEPG0213BN &display, const String &s, int16_t curx, int16_t cury, int16_t fcol, bool updt)
{
  int16_t x, y;
  uint16_t w, h;  
  display.setTextColor(fcol);
  display.setCursor(curx, cury);
  display.println(s);
  if (updt) 
  {
    display.getTextBounds(s, curx, cury, &x, &y, &w, &h);
    display.updateWindow(x,y,w,h);     
  }  
}

void replaceTextEInk(GxDEPG0213BN &display, const String &olds, const String &news, int16_t curx, int16_t cury, 
     int16_t bkcol, int16_t fcol, bool updt)
{
  int16_t x, y;
  uint16_t w, h;  
  // Delete old string
  clearEInk(display, olds, curx, cury, bkcol, false);
  display.setCursor(curx, cury);
  display.setTextColor(fcol);
  // write new string
  display.println(news);
  if (updt) // display.updateWindow(0,0, display.width(), display.height());  
  {
    display.getTextBounds(olds, curx, cury, &x, &y, &w, &h);
    display.updateWindow(x,y,w,h);     
  }
}

void drawFrame(GxDEPG0213BN &display, uint16_t pt, uint16_t x_left, uint16_t y_top, uint16_t w, uint16_t h, uint16_t col, bool updt)
{
    // x= left point, y = top point
    for (int i = 0; i<pt; i++) display.drawRect(x_left + i, y_top + i, w-2*i, h-2*i, col);
    if (updt) display.updateWindow(x_left, y_top, w, h);     
}
 
void setFont(GxDEPG0213BN &display, const GFXfont *font)
{
  display.setFont(font);
}