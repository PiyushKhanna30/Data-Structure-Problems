class Solution {
public:
    int maxDivisible(long num,int x)          
    {
        while(num%x==0)
        {
            num=num/x;
        }
        return num;
    }
    bool isUgly(long num)
    {
        if(num==0)
            return false;
        num=maxDivisible(num,2);
        num=maxDivisible(num,3);
        num=maxDivisible(num,5);
        return (num==1)?true:false;         //eg 10%2==0  ->  10/2  ->  5%2!=0  ->  5%3!=0   ->  5%5==0  -> 1
    }
};