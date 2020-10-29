class Solution {
public:
    bool isValid(vector<int>& piles,int mid, int H)
    {
        int h=0;
        for(int pile:piles)
        {
            if(pile%mid==0)
                h+=(pile/mid);
            else
                h = h + (pile/mid) + 1;
            if(h>H)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int beg = 1;
        int end = INT_MIN;
        for(int pile : piles)
        {
            end = max(end,pile);
        }
        
        int result = -1;
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2;
            if(isValid(piles,mid,H))
            {
                result = mid;
                end=mid-1;
            }
            else
            {
                beg = mid+1;
            }
        }
        return result;
    }
};