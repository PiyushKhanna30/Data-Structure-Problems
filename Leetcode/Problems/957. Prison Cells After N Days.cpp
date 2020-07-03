class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> temp=cells;
        int n=cells.size();
        int x=temp[0];
        for(int i=1;i<n-1;i++)
        {
            int m=temp[i];
            temp[i]=x^temp[i+1]==0?1:0;
            x=m;
        }
        temp[0]=temp[n-1]=0;
        N-=1;
        while(N--)
        {
            N=N%14;
            x=0;
            for(int i=1;i<n-1;i++)
            {
                int m=temp[i];
                temp[i]=x^temp[i+1]==0?1:0;
                x=m;
            }
        }
        return temp;
    }
};
/*
LOGIC
1. Perform 1st day task just after copying elements and replace first and last cell with 0 and decrement N by 1
2. if both (i-1) && (i+1) are same then fill it..can be achieved using XNOR or !XOR
3. Note the result repeats itself after 14 days so we do N%=14 else for large N Time Limit Exceed
*/