bool cmp(int a,int b)
    {
        return a>b;
    }
class Solution {
public:
    int toTime(string str)
    {
        int hours = ((int)str[0])*10 + (int)str[1];
        int mins = hours*60 + ((int)str[3])*10 + (int)str[4];
        return mins;
    }
    
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string,vector<int>>mp;
        vector<string>ans;
        for(int i=0;i<keyName.size();i++)
        {
            mp[keyName[i]].push_back(toTime(keyTime[i]));
        }
        for(auto it : mp)
        {
            if(it.second.size()<3)
                continue;
            
            sort(it.second.begin(),it.second.end(),cmp);
            priority_queue<int>pq;
            pq.push(it.second[0]);
            for(int i=1;i<it.second.size();i++)
            {
                while(!pq.empty() && abs(pq.top() - it.second[i])> 60)
                        pq.pop();
                    
                pq.push(it.second[i]);
                
                if(pq.size() >=3)
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};