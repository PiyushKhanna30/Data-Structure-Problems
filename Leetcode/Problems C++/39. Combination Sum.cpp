class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& candidates, int target,vector<int>sma,int index)
    {
        if(target == 0)
        {
            ans.push_back(sma);
            return;
        }
        if(target <0)
            return;
        for(int i=index;i<candidates.size();i++)
        {
            sma.push_back(candidates[i]);
            help(candidates,target-candidates[i],sma,i);
            sma.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>sma;
        help(candidates,target,sma,0);
        return ans;
    }
};