#include <iostream>

using namespace std;

int boundary(int angle){
    //this simplifies the inputted angle, and puts it withing the range of 0 and 359
    
    bool limit = true;
    while(limit){
        if(angle >=0 and angle <= 359){
            limit = false;
        }
        else if(angle < 0){
            angle = angle + 360;
        }
        else if(angle > 0){
            angle = angle - 360;
        }
    }
    return angle;
}

int rotation(int initial_angle, int final_angle){
    //the motor will only spin counter-clockwise
    
    int rotation_angle;//the amount the motor will spin in the counter-clockwise direction
    
    initial_angle = boundary(initial_angle);
    final_angle = boundary(final_angle);
    
    if(final_angle - initial_angle <= 0){
        rotation_angle = abs(initial_angle - final_angle);
    }
    else if(final_angle - initial_angle > 0){
        rotation_angle = 360 - abs((initial_angle - final_angle));
    }
    
    return rotation_angle;
}