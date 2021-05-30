//Intution
//1.To find the diff between x cordinates and y cordinates
//2.Then to find min dif int x or y dir and move this much steps diagonally.
//3.for the other max diff move max -min steps vertically or horizontally.
//eg
//[[1,1],[3,4],[-1,0]]
//diffx = abs(1-3) = 2
//diffy = abs(1-4) = 3
//so move 2 steps (min(2,3)) diagonally and remaining ie 1 step (3-2) horizontally/vertically.
//
//diffx = abs(3-(-1)) = 4
//diffy = abs(4 - 0)  = 4
//so move 4 steps min(4,4) diagonally and 0 steps (4-4) vertically/horizontally.


//IMPROVEMENTS
//We see total movement is max of diff

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result =0;
        for(int i=1;i<points.size();i++)
        {
            result += max(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
        }
        return result;
    }
};

// class Solution {
// public:
//     int minTimeToVisitAllPoints(vector<vector<int>>& points) {
//         int result = 0;
//         int x = points[0][0];
//         int y = points[0][1];
//         for(int i=0;i<points.size();i++)
//         {
//             int x2 = points[i][0];
//             int y2 = points[i][1];
//             int d1 = abs(x2-x);
//             int d2 = abs(y2-y);
//             if( d1 < d2 )
//             {
//                 result+=d1;
//                 result+=(d2-d1);
//             }
//             else
//             {
//                 result+=d2;
//                 result+=(d1-d2);
//             }
//             x = x2;
//             y = y2;
//         }
//         return result;
//     }
// };