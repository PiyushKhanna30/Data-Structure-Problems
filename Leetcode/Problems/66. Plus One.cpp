class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();            //Size of vector
        vector<int>ans(n+1,0);          //Result vector of size +1 for case like 9+1=10
        int carry=1;                    //Since +1 so got carry =1
        for(int i=n-1;i>=0;i--)         //loop thrugh digits add carry and put in ans
        {
            int t=0;
            t=carry+digits[i];
            int m=t/10;
            t=t%10;
            ans[i+1]=t;
            carry=m;
        }
        if(carry!=0)                    //eg 9+1 carry here 1
        {
            ans[0]=carry;
            return ans;
        }
        ans.erase(ans.begin());         //eg 1+1 carry =0 so remve 1st space
        return ans;
        
    }
};

