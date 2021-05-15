class Solution {
public:
    int good(int x,int y,int z,int a,int b,int c)
    {
        return abs(x-y)<=a && abs(y-z)<=b && abs(z-x)<=c;
    }
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int result = 0;
        for(int i=0;i<arr.size()-2;i++)
        {
            for(int j=i+1;j<arr.size()-1;j++)
            {
                for(int k=j+1;k<arr.size();k++)
                {
                    if(good(arr[i],arr[j],arr[k],a,b,c))
                        result+=1;
                }
            }
        }
        return result;
    }
};