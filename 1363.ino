/* 
Hex values for universal remote buttons, on the setting for TV Acer 1363
Each button is represented as 2-element array, containing the 3rd and 4th bytes
of the IR data (since first two bytes are same for every button)
Compare received data to these values to find which button was pressed
*/
/* note Mon 13/6/16 - OK button not yet known, test in next lab session? */

const char B_MUTE[2] =    {0xE8, 0x17};
const char B_POWER[2] =   {0xF8, 0x7};
const char B_1[2] =       {0x8, 0xF7};
const char B_2[2] =       {0x88, 0x77};
const char B_3[2] =       {0x48, 0xB7};
const char B_4[2] =       {0x30, 0xB7};
const char B_5[2] =       {0xB0, 0x4F};
const char B_6[2] =       {0x70, 0x8F};
const char B_7[2] =       {0x10, 0xEF};
const char B_8[2] =       {0x90, 0x6F};
const char B_9[2] =       {0x50, 0xAF};
const char B_0[2] =       {0x60, 0x9F};
const char B_AV[2] =      {0x18, 0xE7};
const char B_MENU[2] =    {0xA8, 0x57};
const char B_UP[2] =      {0x0, 0xFF};
const char B_DOWN[2] =    {0x80, 0x7F};
const char B_LEFT[2] =    {0xC0, 0x3F};
const char B_RIGHT[2] =   {0x40, 0xBF};
const char B_PPLUS[2] =   {0xD0, 0x2F};
const char B_PMINUS[2] =  {0xE0, 0x1F};
const char B_VPLUS[2] =   {0xF0, 0xF};
const char B_VMINUS =     {0xC8, 0x37};
const char B_OK[2] =      {0xA0, 0x5F}; // need to find this one still
const char B_BB[2] =      {0x78, 0x87};
const char B_FF[2] =      {0xB8, 0x47};
const char B_REC[2] =     {0xD8, 0x27};
const char B_PLAY[2] =    {0x38, 0xC7};