/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>result;
        for(int x=1;x<=1000;x++)
        {
            for(int y=1;y<=1000;y++)
            {
                int t = customfunction.f(x,y);
                if(t>z)
                    break;
                else if(z==t)
                {
                    vector<int>res;
                    res.push_back(x);
                    res.push_back(y);
                    result.push_back(res);
                }
            }
            if(customfunction.f(x,0)>z)
                break;
        }
        return result;
    }
};