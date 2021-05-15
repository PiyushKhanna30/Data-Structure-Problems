class Solution {
public:
    bool isValid(vector<int>& bloomDay, int m, int k,int mid)
    {
        int c = k;
        for(int i = 0; i<bloomDay.size();i++)
        {
            if(bloomDay[i] <= mid)
            {
                c--;
                if(c==0)
                {
                    m--;
                    c = k;
                    if(m==0)
                        return true;
                    
                }
            }
            else
            {
                c=k;
                if(bloomDay.size()-i -1 < m*k)return false;
            }
        }
        if(m>0)return false;
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size())return -1;
        int beg = 1;
        int end = INT_MIN;
        for(int b: bloomDay)
        {
            end = max(end,b);
        }
        int result = -1;
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2;
            if(isValid(bloomDay,m,k,mid))
            {
                result = mid;
                end = mid-1;
            }
            else
            {
                beg = mid+1;
            }
        }
        return result;
    }
};