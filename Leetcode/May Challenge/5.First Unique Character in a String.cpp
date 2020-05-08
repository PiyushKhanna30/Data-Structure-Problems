/**
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
**/
public:
    int firstUniqChar(string s) {
        int *arr;
        arr=new int [26];
        for(int i=0;i<26;i++)
            arr[i]=0;
        for(int i=0;s[i]!='\0';i++)
            arr[s[i]-'a']+=1;
        for(int i=0;s[i]!='\0';i++)
        {
            if(arr[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
