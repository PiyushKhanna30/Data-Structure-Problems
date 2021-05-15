class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=(hour*30.0)+((minutes*30.0)/60.0);
        double m=minutes*6.0;
        double angle=abs(h-m);
        return (angle<180)?angle:360-angle;
    }
};

/*
Hours = 12 
Angle subtend by hour hand   = 360/12==30 degree by each hour 

Minutes =60
Angle subtend by minute hand = 360/60==6 degree by each minute

Now deflection due to minutes in hour hand
We know eg 12-----1 the angle is 30 degree
So angle due to minute hand on hour hand is 30/60*minutes

then we calculate the absolute difference b/w the two angles and since we need to return angle <180
so if greater than 180 subtract from 360.
*/