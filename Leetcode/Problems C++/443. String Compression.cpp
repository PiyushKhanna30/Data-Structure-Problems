class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=0;
        while(i<chars.size())
        {
            int count = 0;
            chars[j] = chars[i];
            while(i<chars.size() && chars[j]==chars[i])
            {
                count += 1;
                i += 1;
            }
            if(count == 1)
            {
                j += 1;
            }
            else
            {
                string st = to_string(count);
                j += 1;
                for(auto ch : st)
                {
                    chars[j++] = ch;
                }
            }
        }
        return j;
    }
};