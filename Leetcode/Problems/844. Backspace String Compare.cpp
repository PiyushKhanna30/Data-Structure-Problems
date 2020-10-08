class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char>st1,st2;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='#' && !st1.empty())
                st1.pop();
            else if(S[i]!='#')
                st1.push(S[i]);
        }
        
        for(int i=0;i<T.size();i++)
        {
            if(T[i]=='#' && !st2.empty())
                st2.pop();
            else if(T[i]!='#')
                st2.push(T[i]);
        }
        
        if(st1.size()!=st2.size())
            return false;
        while(!st1.empty())
        {
            if(st1.top()==st2.top())
            {
                st1.pop();
                st2.pop();
            }
            else 
                return false;
        }
        return true;
    }
};