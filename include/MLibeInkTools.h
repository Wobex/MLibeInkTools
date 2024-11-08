#include <Arduino.h>
#include <GxEPD.h>
#include <GxDEPG0213BN/GxDEPG0213BN.h>

/// @brief Clear a rectangular area of the e-ink display
/// @param display e-ink device
/// @param x,y top-left corner of rectangle
/// @param w, h width and height of rectangle
/// @param col color to use for deletion = background color
/// @param updt update display if true
void clearEInk(GxDEPG0213BN &display, int16_t x, int16_t y, int16_t w, int16_t h, int16_t col = GxEPD_WHITE, bool updt = true);

/// @brief Clear a string area of the e-ink display
/// @param display e-ink device
/// @param s string that defines the area by string::length
/// @param x, y bottom-left location of string
/// @param col color to use for deletion = background color
/// @param updt update display if true
void clearEInk(GxDEPG0213BN &display, const String &s, int16_t curx, int16_t cury, int16_t col = GxEPD_WHITE, bool updt = true);

void writeEInk(GxDEPG0213BN &display, const String &s, int16_t curx, int16_t cury, int16_t fcol, bool updt = true);
void replaceTextEInk(GxDEPG0213BN &display, const String &olds, const String &news, int16_t curx, int16_t cury, 
     int16_t bkcol = GxEPD_WHITE, int16_t fcol = GxEPD_BLACK, bool updt = true);
void setFont(GxDEPG0213BN &display, const GFXfont *font);
void drawFrame(GxDEPG0213BN &display, uint16_t pt, uint16_t x_left, uint16_t y_top, uint16_t w, uint16_t h, uint16_t col, bool updt = true);