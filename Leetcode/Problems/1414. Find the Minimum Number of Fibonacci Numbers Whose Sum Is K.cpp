/*

f[2n+1]
=f[2n]+f[2n-1]
=f[2n]+f[2n-2]+f[2n-3]
=f[2n]+f[2n-2]+...+f[6]+f[5]
=...+f[6]+f[4]+f[3]
=...+f[6]+f[4]+f[2]+f[1]
=...+f[6]+f[4]+f[2]+f[0] (because f[0]==f[1])

f[2n]
=f[2n-1]+f[2n-2]
=f[2n-1]+f[2n-3]+f[2n-4]
=...+f[5]+f[4]
=...+f[5]+f[3]+f[2]
=...+f[5]+f[3]+f[1]+f[0]

*/

class Solution {
public:
    void fillFib(vector<int>&fib,int k)
    {
        fib.push_back(0);
        fib.push_back(1);
        int i=1;
        while(fib.back()<k)
        {
            fib.push_back(fib[i]+fib[i-1]);
            i++;
        }
    }
    int lessThan(vector<int>&fib,int k)
    {
        int beg =0,end = fib.size()-1;
        while(beg<=end)
        {
            int mid = (beg + end)/2;
            if(fib[mid]==k)
            {
                return k;
            }
            else if(fib[mid]<k && fib[mid+1]>k)
            {
                return fib[mid];
            }
            else if(fib[mid]<k)
            {
                beg = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return 0;
    }
    int findMinFib(vector<int>&fib,int k)
    {
        int count = 1;
        if(fib.back()==k)
            return count;
        fib.pop_back();
        
        k=k-fib.back();
        while(k)
        {
            count+=1;
            k-=lessThan(fib,k);
        }
        return count;
    }
    int findMinFibonacciNumbers(int k) {
        vector<int>fib;
        fillFib(fib,k);
        int minFibs = findMinFib(fib,k);
        return minFibs;
    }
};



// class Solution {
// public:
//     int findMinFibonacciNumbers(int k) {
//         vector<int>fib;
//         fib.push_back(1);
//         fib.push_back(1);
//         int count=0;
//         int i=2;
//         while(fib.back()<k)
//         {
//             int num=fib[i-2]+fib[i-1];
//             fib.push_back(num);
//             i++;
//             if(num==k)
//                 return 1;
//         }
//         for(int i=fib.size()-1;i>=0;i--)
//         {
//             if(fib[i]<=k)
//             {
//                 k-=fib[i];
//                 count+=1;
//             }
//             if(k==0)
//             {
//                 return count;
//             }
            
//         }
//         return count;
//     }
// };