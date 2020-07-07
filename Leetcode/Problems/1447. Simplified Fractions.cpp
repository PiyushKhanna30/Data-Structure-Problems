class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        if(n<=1)
            return ans;
        for(int i=1;i<n;i++)                        //for every i<j do i/j if greatest common divisor == 1 push
        {
            for(int j=i+1;j<=n;j++)
            {
                if(__gcd(i,j)==1)
                {
                    string s=to_string(i)+"/"+to_string(j);
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};