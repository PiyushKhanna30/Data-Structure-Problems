class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if(k>n || n==0)
            return 0;
        int result = 0;
        int sum = 0;
        for(int i=0;i<k;i++)
            sum+=arr[i];
        
        if(sum/k >= threshold)
                result+=1;
        
        for(int i=k;i<n;i++)
        {
            sum-=arr[i-k];
            sum+=arr[i];
            if(sum/k >= threshold)
                result+=1;
        }
        return result;
    }
};