class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            while(isalnum(s[i])==false && i<j)
                i++;
            while(isalnum(s[j])==false && i<j)
                j--;
            if(toupper(s[i])==toupper(s[j]))
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};
//Memory O(1)
//Time O(n/2)

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int l=s.size();
//         string s2;
//         for(int i=0;i<l;i++)
//         {
//             if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))
//             {
//                 s2+=toupper(s[i]);
//             }
//         }
//         for(int i=0;i<s2.size()/2;i++)
//         {
//             if((s2[i]>='A' && s2[i]<='Z') || (s2[i]>='0' && s2[i]<='9'))
//             {
//                 if(s2[i]!=s2[s2.size()-1-i])
//                     return false;
//             }
//         }
//         return true;
//     }
// };
//Memory O(n)
//Time O(n)