class Solution {
public:
    bool isSubsequence(string s, string t) {
        int subSeqSize=s.size();
        int stringSize=t.size();
        //If substring size > string size
        if(subSeqSize>stringSize)
            return false;
        //If sub string size 0 then it is subsequence
        if(subSeqSize==0)
            return true;
        
        //loop over string and check if matches then increment sub string
        int j=0;
        for(int i=0;i<stringSize;i++)
        {
            if(t[i]==s[j])
            {
                j++;
                //check if all substring iterated stop and return true
                if(j==subSeqSize)
                    return true;
            }
        }
        return false;
    }
};