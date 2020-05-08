/**
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

You may assume that both strings contain only lowercase letters.
**/
#include<unordered_map>
class Solution {
public:

    bool canConstruct(string ransomNote, string magazine) {
        ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
        unordered_map<char,int>mp;
        for(int i=0;magazine[i]!='\0';i++)
        {
            mp[magazine[i]]+=1;
        }
        for(int i=0;ransomNote[i]!='\0';i++)
        {
            if(mp.find(ransomNote[i])==mp.end())
                return false;
            else
            {
                if(mp[ransomNote[i]]==1)
                    mp.erase(ransomNote[i]);
                else
                    mp[ransomNote[i]]-=1;
            }
        }
        return true;

    }
};
