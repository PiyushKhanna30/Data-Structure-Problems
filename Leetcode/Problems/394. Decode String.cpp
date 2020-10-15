class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        stack<string>st;
        string result,temp;
        stack<int>nums;
        
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                result+=s[i];
            }
            else if(isdigit(s[i]))
            {
                num = num*10 + (s[i]-'0');
            }
            else if(s[i]=='[')
            {
                st.push(result);
                st.push("[");
                result="";
                nums.push(num);
                num=0;
            }
            else
            {
                st.pop();
                num = nums.top();
                nums.pop();
                temp = result;
                result="";
                while(num--)
                {
                    result += temp;
                }
                num=0;
                if(!st.empty())
                {
                    temp = st.top();
                    st.pop();
                    result = temp+result;
                }
            }
        }
        return result;
    }
};
//LOGIC
/*
eg x3[a2[c]]
  num=0         result=""       temp=""         st=[]           nums=[]

0.num=0         result="x"       temp=""         st=[]           nums=[]

1.num=3         result="x"       temp=""         st=[]           nums=[]

2.num=0         result=""       temp=""         st=[[,x]           nums=[3]

3.num=0         result="a"       temp=""       st=[[,x]           nums=[3]

4.num=2         result="a"       temp=""       st=[[,x]           nums=[3]

5.num=0         result=""       temp=""       st=[[,a,[,x]        nums=[2,3]

6.num=0         result="c"      temp=""        st=[[,a,[,x]       nums=[2,3]

7.num=0         result="acc"      temp="a"        st=[[,x]       nums=[3]

8.num=0         result="xaccaccacc"      temp="x"      st=[]     nums=[]

*/