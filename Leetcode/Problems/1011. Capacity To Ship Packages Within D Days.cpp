class Solution {
public:
    bool isValid(vector<int>&weights, int mid,int D)
    {
        int k=D,sum=0;
        for(int weight : weights)
        {
            if(sum+weight <= mid)
            {
                sum+=weight;
            }
            else
            {
                sum=weight;
                k--;
                if(k==0)
                    return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int maxElement = INT_MIN;
        int result = -1;
        int sum = 0;
        
        for(int weight:weights)
        {
            maxElement = max(maxElement,weight);
            sum+=weight;
        }
        
        int beg = maxElement;
        int end = sum;
        
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2 ;
            if(isValid(weights,mid,D))
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