class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>result;
        if(n<=1)return result;

        sort(arr.begin(),arr.end());
        int min = INT_MAX;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1] < min)
            {
                min = arr[i]-arr[i-1];
                result.clear();
                result.push_back({arr[i-1],arr[i]});
            }
            else if(min==arr[i]-arr[i-1])
            {
                result.push_back({arr[i-1],arr[i]});
            }
            
        }
        return result;
    }
};