class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //soring number frquebcy in map
        unordered_map<int,int>mp;
        for(int num:arr)
            mp[num]+=1;
        
        //push frequency in priority queue
        priority_queue<int>q;
        for(auto it : mp)
            q.push(it.second);
        
        //Count greedyily min numbers to be removed
        int res = 0;
        int n2 = 0;
        while(arr.size()>n2*2 && !q.empty())
        {
            n2+=q.top();
            q.pop();
            res+=1;
        }
        return res;
    }
};