class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int w=1;
        int j=0;
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ')
                w+=1;
            if(sentence[i]==searchWord[j])
            {
                if(i!=0 && sentence[i-1]!=' ')
                    continue;
                while( j<searchWord.size() && sentence[i]==searchWord[j] )
                {
                    i++;
                    j++;
                }
                if(j==searchWord.size())
                    return w;
                j=0;
                i--;
            }
        }
        return -1;
    }
};