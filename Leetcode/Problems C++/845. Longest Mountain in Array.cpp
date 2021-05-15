class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if(n<3)return 0;
        vector<int>left(A.size(),0);
        vector<int>right(A.size(),0);
        for(int i=1;i<n;i++)
            if(A[i-1]<A[i])
                left[i]=1+left[i-1];
        for(int i=n-2;i>=0;i--)
            if(A[i+1]<A[i])
                right[i]=1+right[i+1];
        
        int res = 0;
        for(int i=0;i<n;i++)
        {
            // cout<<left[i]<<" "<<right[i]<<endl;
            if(left[i]>0 && right[i]>0)
            res = max(res,left[i]+right[i]+1);
        }
        return res;
    }
};