//i-j is unique so in one iteration push in map of priority que and in second assign values
//O(MNLog(Diag = min(N,M)))
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,priority_queue<int, vector<int>, greater<int>>>mp;// min priority queue
        for(int i=0;i<mat.size();i++)
        {
           for(int j=0;j<mat[i].size();j++)
           {
               mp[i-j].push(mat[i][j]);
           }
        }        
        
        for(int i=0;i<mat.size();i++)
        {
           for(int j=0;j<mat[i].size();j++)
           {
               mat[i][j] = mp[i-j].top();
               mp[i-j].pop();
           }
        }
        return mat;
    }
};