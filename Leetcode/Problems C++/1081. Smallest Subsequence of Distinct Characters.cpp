class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>occ(26,0);
        vector<bool>done(26,false);
        for(char c:s)
            occ[c-'a']+=1;
        
        string result;
        int len=0;
        for(char c:s)
        {
            if(done[c-'a'])
            {
                occ[c-'a']-=1;
                continue;
            }

            while(len!=0 && occ[result[len-1]-'a']>0 && result[len-1]>c)
            {
                done[result[len-1]-'a'] = false;
                len--;
                result.pop_back();
            }
            done[c-'a']=true;
            occ[c-'a']-=1;
            len+=1;
            result.push_back(c);
        }
        return result;
    }
};