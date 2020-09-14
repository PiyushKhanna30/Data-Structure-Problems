class Solution {
public:
    vector<int> partitionLabels(string S) {
        int  len=S.size();
        vector<int>result;//to return ans
        unordered_map<char,int>mp;//stores the index of last occurence of character
        int i;
        for(i=0;i<len;i++)//assigning the last occurence index
            mp[S[i]]=i;
        i=0;
        int end,j;//end points to where is last occurence 
        //Idea
        //we will traverse string and find last occurence of the character
        //and update it with end. next we use j from front and increment one by one.
        //we try to find max index of any character between j to end.
        while(i<len)
        {
            end=mp[S[i]];
            j=i;
            while(j<end)
            {
                end = end>mp[S[j]]?end:mp[S[j]];
                j++;
            }
            result.push_back(end-i+1);
            i=end+1;
        }
        return result;
    }
};