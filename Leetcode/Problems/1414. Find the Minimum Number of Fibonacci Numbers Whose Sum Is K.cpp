class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>fib;
        fib.push_back(1);
        fib.push_back(1);
        int count=0;
        int i=2;
        while(fib.back()<k)
        {
            int num=fib[i-2]+fib[i-1];
            fib.push_back(num);
            i++;
            if(num==k)
                return 1;
        }
        for(int i=fib.size()-1;i>=0;i--)
        {
            if(fib[i]<=k)
            {
                k-=fib[i];
                count+=1;
            }
            if(k==0)
            {
                return count;
            }
            
        }
        return count;
    }
};
//https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/585632/JavaC%2B%2BPython-Easy-Prove