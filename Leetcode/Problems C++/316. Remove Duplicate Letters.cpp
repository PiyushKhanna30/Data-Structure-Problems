class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>occ(26,0);
        vector<bool>done(26,false);
        vector<char>res;
        for(char c:s)
            occ[c-'a']+=1;
        
        string result;
        
        for(char c:s)
        {
            if(done[c-'a'])
            {
                occ[c-'a']-=1;
                continue;
            }

            while(res.size()!=0 && occ[res.back()-'a']>0 && res.back()>c)
            {
                done[res.back()-'a'] = false;
                res.pop_back();
                result.pop_back();
            }
            done[c-'a']=true;
            occ[c-'a']-=1;
            res.push_back(c);
            result.push_back(c);
        }
        return result;
    }
};
