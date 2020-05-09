/**
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
**/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2)
            return true;
        float x=coordinates[0][0];
        float y=coordinates[0][1];
        float x2=coordinates[1][0];
        float y2=coordinates[1][1];
        float m=(y2-y)/(x2-x);
        for(int i=2;i<coordinates.size();i++)
        {
            if((coordinates[i][1]-y)/(coordinates[i][0]-x)==m)
                continue;
            return false;
        }
        return true;
    }
};
