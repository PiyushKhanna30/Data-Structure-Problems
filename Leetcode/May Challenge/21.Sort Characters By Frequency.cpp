/**
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
**/
bool cmp(pair<char,int>a,pair<char,int>b)
{
    return a.second>=b.second;
}
class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]+=1;
        }
        vector<pair<char,int>>v;
        copy(mp.begin(),mp.end(),back_inserter(v));
        sort(v.begin(),v.end(),cmp);
        string ans;
        for(auto i:v)
        {
            while(i.second>0)
            {
                ans+=i.first;
                i.second-=1;
            }
        }
        return ans;
    }
};
