class Solution {
public:
    void compute(vector<int>&lps,string s,int size)
    {
        int i=0,j=0;
        lps[0]=0;
        i++;
        while(i<size)
        {
            if(s[i]==s[j])
            {
                j++;
                lps[i]=j;
                i++;
            }
            else
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        int size=s.size();
        vector<int>lps(size,0);
        compute(lps,s,size);
        if(lps[size-1]>0 && size%(size-lps[size-1])==0)
            return true;
        return false;
    }
};