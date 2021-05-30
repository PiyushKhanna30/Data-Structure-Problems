class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int len = A.size();
        string ans = "";
        if(len!=4)
            return ans;
        int maximum=INT_MIN;
        int temp=0;
        int hour1=-1,hour2=-1,min1=-1,min2=-1;
        for(int i=0;i<4;i++)
        {
            if(A[i]>2)
                continue;
            for(int j=0;j<4;j++)
            {
                if(i==j)
                    continue;
                if(A[i]==2 && A[j]>3)
                    continue;
                for(int k=0;k<4;k++)
                {
                    if(i==k || j==k)
                        continue;
                    if(A[k]>5)
                        continue;
                    for(int l=0;l<4;l++)
                    {
                        if(l==i||l==j||l==k)
                            continue;
                        temp = A[i]*1000 + A[j]*100 + A[k]*10 +A[l];
                        if(maximum<temp)
                        {
                            maximum=temp;
                            hour1=A[i];
                            hour2=A[j];
                            min1=A[k];
                            min2=A[l];
                        }
                    }
                }
            }
        }
        if(hour1==-1 ||hour2==-1 ||min1==-1 ||min2==-1)
            return ans;
        ans = to_string(hour1)+to_string(hour2)+":"+to_string(min1)+to_string(min2);
        return ans;
    }
};