class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>s;
        vector<string>c={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i=0;i<words.size();i++)
        {
            string ans;
            for(int j=0;j<words[i].size();j++)
            {
                ans=ans+c[words[i][j]-97];
            }
            s.insert(ans);
        }
        return s.size();
    }
};