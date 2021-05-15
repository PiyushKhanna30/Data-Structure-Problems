class Solution {
public:
    bool buddyStrings(string A, string B) {
        int lenA = A.size();
        int lenB = B.size();
        vector<int>arr(26,0);
        int m=0;
        if(lenA!=lenB || lenA==0)return false;
        
        vector<char>sw;
        for(int i=0;i<lenA;i++)
        {
            if(A[i]!=B[i])
            {
                sw.push_back(i);
                if(sw.size()>2)return false;
            }
            else
            {
                arr[A[i]-'a']+=1;
                m = max(m,arr[A[i]-'a']);
            }
        }
        if(sw.size()==2 && A[sw[0]] == B[sw[1]] && A[sw[1]] == B[sw[0]])return true;
        if(sw.size()==0 && m>1)return true;
        return false;
    }
};