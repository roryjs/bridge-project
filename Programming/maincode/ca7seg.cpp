/* Code to change a common-anode seven segment display connected to arduino pins 1 to 7 */

/* NB pin 1 is also used in serial writing/reading, so: 
        * Pin 1 must not be connected while uploading program to device over USB
        * The code will not work if Serial.begin() is called */
        
/* The nth element of digits[] is the pin state (of pins 0 to 7) needed to display
   the digit n on the 7segment display */
        
byte digits[10] = {B10000000, \
                  B11110010, \
                  B01001000, \
                  B01100000, \
                  B00110010, \
                  B00100100, \
                  B00000100, \
                  B11110000, \
                  B00000000, \
                  B00100000};

bool sevsegset(int num)
{
    if (num >= 0 && num <= 9)
    {
        PORTD = digits[num];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}