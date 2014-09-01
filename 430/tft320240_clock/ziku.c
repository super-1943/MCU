//ASCII Font for TFT/CSTN
const unsigned char ascii_font[][16] =
{
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//- -
        {0x0, 0x0, 0x18, 0x3C, 0x3C, 0x3C, 0x18, 0x18, 0x18, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0},//-!-
        {0x0, 0x66, 0x66, 0x66, 0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-"-
        {0x0, 0x0, 0x0, 0x6C, 0x6C, 0xFE, 0x6C, 0x6C, 0x6C, 0xFE, 0x6C, 0x6C, 0x0, 0x0, 0x0, 0x0},//-#-
        {0x18, 0x18, 0x7C, 0xC6, 0xC2, 0xC0, 0x7C, 0x6, 0x86, 0xC6, 0x7C, 0x18,0x18, 0x0, 0x0, 0x0},//-$-
        {0x0, 0x0, 0x0, 0x0, 0xC2, 0xC6, 0xC, 0x18, 0x30, 0x60, 0xC6, 0x86, 0x0, 0x0, 0x0, 0x0},//-%-
        {0x0, 0x0, 0x38, 0x6C, 0x6C, 0x38, 0x76, 0xDC, 0xCC, 0xCC, 0xCC, 0x76, 0x0, 0x0, 0x0, 0x0},//-&-
        {0x0, 0x30, 0x30, 0x30, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-'-
        {0x0, 0x0, 0xC, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0xC, 0x0, 0x0, 0x0, 0x0},//-(-
        {0x0, 0x0, 0x30, 0x18, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x18, 0x30, 0x0, 0x0, 0x0, 0x0},//-)-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-*-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-+-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x18, 0x18, 0x30, 0x0, 0x0, 0x0},//-,-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFE, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,0x0, 0x0},//---
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0},//-.-
        {0x0, 0x0, 0x0, 0x0, 0x2, 0x6, 0xC, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x0, 0x0, 0x0, 0x0},//-/-
        {0x0, 0x0, 0x7C, 0xC6, 0xC6, 0xCE, 0xD6, 0xD6, 0xE6, 0xC6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-0-
        {0x0, 0x0, 0x18, 0x38, 0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x0, 0x0, 0x0, 0x0},//-1-
        {0x0, 0x0, 0x7C, 0xC6, 0x6, 0xC, 0x18, 0x30, 0x60, 0xC0, 0xC6, 0xFE, 0x0, 0x0, 0x0, 0x0},//-2-
        {0x0, 0x0, 0x7C, 0xC6, 0x6, 0x6, 0x3C, 0x6, 0x6, 0x6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-3-
        {0x0, 0x0, 0xC, 0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0xC, 0xC, 0xC, 0x1E, 0x0,0x0, 0x0, 0x0},//-4-
        {0x0, 0x0, 0xFE, 0xC0, 0xC0, 0xC0, 0xFC, 0xE, 0x6, 0x6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-5-
        {0x0, 0x0, 0x38, 0x60, 0xC0, 0xC0, 0xFC, 0xC6, 0xC6, 0xC6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-6-
        {0x0, 0x0, 0xFE, 0xC6, 0x6, 0x6, 0xC, 0x18, 0x30, 0x30, 0x30, 0x30, 0x0, 0x0, 0x0, 0x0},//-7-
        {0x0, 0x0, 0x7C, 0xC6, 0xC6, 0xC6, 0x7C, 0xC6, 0xC6, 0xC6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-8-
        {0x0, 0x0, 0x7C, 0xC6, 0xC6, 0xC6, 0x7E, 0x6, 0x6, 0x6, 0xC, 0x78, 0x0, 0x0, 0x0, 0x0},//-9-
        {0x0, 0x0, 0x0, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0},//-:-
        {0x0, 0x0, 0x0, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0, 0x18, 0x18, 0x30, 0x0, 0x0, 0x0, 0x0},//-;-
        {0x0, 0x0, 0x0, 0x6, 0xC, 0x18, 0x30, 0x60, 0x30, 0x18, 0xC, 0x6, 0x0, 0x0, 0x0, 0x0},//-<-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFE, 0x0, 0x0, 0xFE, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-=-
        {0x0, 0x0, 0x0, 0x60, 0x30, 0x18, 0xC, 0x6, 0xC, 0x18, 0x30, 0x60, 0x0, 0x0, 0x0, 0x0},//->-
        {0x0, 0x0, 0x7C, 0xC6, 0xC6, 0xC, 0x18, 0x18, 0x18, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0},//-?-
        {0x0, 0x0, 0x0, 0x7C, 0xC6, 0xC6, 0xDE, 0xDE, 0xDE, 0xDC, 0xC0, 0x7C, 0x0, 0x0, 0x0, 0x0},//-@-
        {0x0, 0x0, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0x0, 0x0, 0x0, 0x0},//-A-
        {0x0, 0x0, 0xFC, 0x66, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x66, 0x66, 0xFC, 0x0, 0x0, 0x0, 0x0},//-B-
        {0x0, 0x0, 0x3C, 0x66, 0xC2, 0xC0, 0xC0, 0xC0, 0xC0, 0xC2, 0x66, 0x3C, 0x0, 0x0, 0x0, 0x0},//-C-
        {0x0, 0x0, 0xF8, 0x6C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x6C, 0xF8, 0x0, 0x0, 0x0, 0x0},//-D-
        {0x0, 0x0, 0xFE, 0x66, 0x62, 0x68, 0x78, 0x68, 0x60, 0x62, 0x66, 0xFE, 0x0, 0x0, 0x0, 0x0},//-E-
        {0x0, 0x0, 0xFE, 0x66, 0x62, 0x68, 0x78, 0x68, 0x60, 0x60, 0x60, 0xF0, 0x0, 0x0, 0x0, 0x0},//-F-
        {0x0, 0x0, 0x3C, 0x66, 0xC2, 0xC0, 0xC0, 0xDE, 0xC6, 0xC6, 0x66, 0x3A, 0x0, 0x0, 0x0, 0x0},//-G-
        {0x0, 0x0, 0xC6, 0xC6, 0xC6, 0xC6, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x0, 0x0, 0x0, 0x0},//-H-
        {0x0, 0x0, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x0, 0x0, 0x0, 0x0},//-I-
        {0x0, 0x0, 0x1E, 0xC, 0xC, 0xC, 0xC, 0xC, 0xCC, 0xCC, 0xCC, 0x78, 0x0, 0x0, 0x0, 0x0},//-J-
        {0x0, 0x0, 0xE6, 0x66, 0x6C, 0x6C, 0x78, 0x78, 0x6C, 0x66, 0x66, 0xE6, 0x0, 0x0, 0x0, 0x0},//-K-
        {0x0, 0x0, 0xF0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x62, 0x66, 0xFE, 0x0, 0x0, 0x0, 0x0},//-L-
        {0x0, 0x0, 0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x0, 0x0, 0x0, 0x0},//-M-
        {0x0, 0x0, 0xC6, 0xE6, 0xF6, 0xFE, 0xDE, 0xCE, 0xC6, 0xC6, 0xC6, 0xC6, 0x0, 0x0, 0x0, 0x0},//-N-
        {0x0, 0x0, 0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x0, 0x0, 0x0, 0x0},//-O-
        {0x0, 0x0, 0xFC, 0x66, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x60, 0x60, 0xF0, 0x0, 0x0, 0x0, 0x0},//-P-
        {0x0, 0x0, 0x7C, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xD6, 0xDE, 0x7C, 0xC, 0xE, 0x0, 0x0},//-Q-
        {0x0, 0x0, 0xFC, 0x66, 0x66, 0x66, 0x7C, 0x6C, 0x66, 0x66, 0x66, 0xE6, 0x0, 0x0, 0x0, 0x0},//-R-
        {0x0, 0x0, 0x7C, 0xC6, 0xC6, 0x60, 0x38, 0xC, 0x6, 0xC6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-S-
        {0x0, 0x0, 0x7E, 0x7E, 0x5A, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x0, 0x0, 0x0, 0x0},//-T-
        {0x0, 0x0, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-U-
        {0x0, 0x0, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x10, 0x0, 0x0, 0x0, 0x0},//-V-
        {0x0, 0x0, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xD6, 0xD6, 0xFE, 0x6C, 0x6C, 0x0, 0x0, 0x0, 0x0},//-W-
        {0x0, 0x0, 0xC6, 0xC6, 0x6C, 0x6C, 0x38, 0x38, 0x6C, 0x6C, 0xC6, 0xC6, 0x0, 0x0, 0x0, 0x0},//-X-
        {0x0, 0x0, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x0, 0x0, 0x0, 0x0},//-Y-
        {0x0, 0x0, 0xFE, 0xC6, 0x86, 0xC, 0x18, 0x30, 0x60, 0xC2, 0xC6, 0xFE, 0x0, 0x0, 0x0, 0x0},//-Z-
        {0x0, 0x0, 0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x0, 0x0, 0x0, 0x0},//-[-
        {0x0, 0x0, 0x0, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0xE, 0x6, 0x2, 0x0, 0x0, 0x0, 0x0},//-\-
        {0x0, 0x0, 0x3C, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x3C, 0x0, 0x0, 0x0, 0x0},//-]-
        {0x10, 0x38, 0x6C, 0xC6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-^-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0},//-_-
        {0x30, 0x30, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-`-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0xC, 0x7C, 0xCC, 0xCC, 0xCC, 0x76, 0x0, 0x0, 0x0, 0x0},//-a-
        {0x0, 0x0, 0xE0, 0x60, 0x60, 0x78, 0x6C, 0x66, 0x66, 0x66, 0x66, 0xDC, 0x0, 0x0, 0x0, 0x0},//-b-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x7C, 0xC6, 0xC0, 0xC0, 0xC0, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-c-
        {0x0, 0x0, 0x1C, 0xC, 0xC, 0x3C, 0x6C, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x0, 0x0, 0x0, 0x0},//-d-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x7C, 0xC6, 0xFE, 0xC0, 0xC0, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-e-
        {0x0, 0x0, 0x38, 0x6C, 0x64, 0x60, 0xF0, 0x60, 0x60, 0x60, 0x60, 0xF0, 0x0, 0x0, 0x0, 0x0},//-f-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x76, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x7C, 0xC, 0xCC, 0x78, 0x0},//-g-
        {0x0, 0x0, 0xE0, 0x60, 0x60, 0x6C, 0x76, 0x66, 0x66, 0x66, 0x66, 0xE6, 0x0, 0x0, 0x0, 0x0},//-h-
        {0x0, 0x0, 0x18, 0x18, 0x0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x0, 0x0, 0x0, 0x0},//-i-
        {0x0, 0x0, 0x6, 0x6, 0x0, 0xE, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x66, 0x66, 0x3C, 0x0},//-j-
        {0x0, 0x0, 0xE0, 0x60, 0x60, 0x66, 0x6C, 0x78, 0x78, 0x6C, 0x66, 0xE6, 0x0, 0x0, 0x0, 0x0},//-k-
        {0x0, 0x0, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x0, 0x0, 0x0, 0x0},//-l-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xEC, 0xFE, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0x0, 0x0, 0x0, 0x0},//-m-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xDC, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x0, 0x0, 0x0, 0x0},//-n-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x7C, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-o-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xDC, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x60, 0x60, 0xF0, 0x0},//-p-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x76, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x7C, 0xC, 0xC, 0x1E, 0x0},//-q-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xDC, 0x76, 0x62, 0x60, 0x60, 0x60, 0xF0, 0x0, 0x0, 0x0, 0x0},//-r-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x7C, 0xC6, 0x60, 0x38, 0xC, 0xC6, 0x7C, 0x0, 0x0, 0x0, 0x0},//-s-
        {0x0, 0x0, 0x10, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x30, 0x30, 0x36, 0x1C, 0x0, 0x0, 0x0, 0x0},//-t-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x0, 0x0, 0x0, 0x0},//-u-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x0, 0x0, 0x0, 0x0},//-v-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xC6, 0xC6, 0xC6, 0xD6, 0xD6, 0xFE, 0x6C, 0x0, 0x0, 0x0, 0x0},//-w-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xC6, 0x6C, 0x38, 0x38, 0x38, 0x6C, 0xC6, 0x0, 0x0, 0x0, 0x0},//-x-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x7E, 0x6, 0xC, 0xF8, 0x0},//-y-
        {0x0, 0x0, 0x0, 0x0, 0x0, 0xFE, 0xCC, 0x18, 0x30, 0x60, 0xC6, 0xFE, 0x0, 0x0, 0x0, 0x0},//-z-
        {0x0, 0x0, 0xE, 0x18, 0x18, 0x18, 0x70, 0x18, 0x18, 0x18, 0x18, 0xE, 0x0, 0x0, 0x0, 0x0},//-{-
        {0x0, 0x0, 0x18, 0x18, 0x18, 0x18, 0x0, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0},//-|-
        {0x0, 0x0, 0x70, 0x18, 0x18, 0x18, 0xE, 0x18, 0x18, 0x18, 0x18, 0x70, 0x0, 0x0, 0x0, 0x0},//-}-
        {0x0, 0x0, 0x76, 0xDC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},//-~-
        {0x0, 0x0, 0x0, 0x0, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0xFE, 0x0, 0x0, 0x0, 0x0, 0x0}//--
};

const unsigned char Hanzi[]=
{
/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x08,0x20,0x49,0x30,0x2A,0x20,0x1C,0x20,0xFF,0x7E,0x1C,0x44,0x2B,0x44,0x48,0xC4,
0x08,0x28,0xFF,0x28,0x12,0x10,0x34,0x10,0x0C,0x28,0x32,0x4E,0xC0,0x84,0x00,0x00,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x02,0x00,0x01,0x00,0x3F,0xFC,0x20,0x04,0x40,0x08,0x1F,0xE0,0x00,0x40,0x00,0x80,
0x01,0x00,0x7F,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,

/*--  ����:  ָ  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x11,0x00,0x11,0x38,0x11,0xC0,0x11,0x04,0xFD,0x04,0x11,0xFC,0x14,0x00,0x19,0xFC,
0x31,0x04,0xD1,0x04,0x11,0xFC,0x11,0x04,0x11,0x04,0x11,0x04,0x51,0xFC,0x20,0x00,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x10,0x20,0x10,0x20,0x20,0x20,0x3E,0x20,0x40,0x20,0x7C,0x20,0x91,0xFE,0x10,0x20,
0xFE,0x20,0x10,0x20,0x10,0x20,0x12,0x20,0x14,0x20,0x18,0x20,0x10,0x20,0x00,0x20,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x01,0x00,0x01,0x00,0x01,0x00,0x3F,0xF8,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,
0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,0x01,0x02,0x01,0x02,0x00,0xFE,0x00,0x00,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x00,0x00,0x3F,0xF0,0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x00,0x01,0x00,0x01,0x04,
0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x10,0x20,0x10,0x20,0x20,0x20,0x3D,0xFC,0x41,0x24,0x7D,0x24,0x91,0x24,0x11,0x24,
0xFD,0xFC,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x14,0x20,0x18,0x20,0x10,0x20,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x08,0x00,0x08,0x00,0x08,0x04,0x7E,0x84,0x08,0x48,0x08,0x28,0xFF,0x10,0x08,0x10,
0x28,0x28,0x2F,0x28,0x28,0x44,0x28,0x84,0x58,0x00,0x48,0x00,0x87,0xFE,0x00,0x00,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x02,0x00,0x01,0x80,0x00,0x80,0x1F,0x00,0x01,0x08,0x01,0x18,0x7D,0xA0,0x05,0x40,
0x09,0x20,0x09,0x20,0x11,0x10,0x11,0x08,0x21,0x06,0xC1,0x00,0x05,0x00,0x02,0x00,

/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x06,0x08,0x78,0x88,0x08,0x48,0x08,0x48,0xFE,0x08,0x18,0x88,0x1C,0x48,0x2A,0x48,
0x28,0x0E,0x48,0x78,0x8B,0x88,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
};