class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>bits(num+1);
        bits[0]=0;
        if(num==0)
            return bits;
        bits[1]=1;
        for(int i=2;i<=num;i++)
        {
            if(i%2==0)
            {
                bits[i]=bits[i/2];
            }
            else
            {
                bits[i]=bits[i/2]+1;
            }
            //or
            //bits[i]=i%2==0?bits[i/2]:bits[i/2]+1;
        }
        return bits;
    }
};

/*
TO FIND NUMBER OF BITS AS 1 IN NUMBER
eg 2 == 010   ans 1
eg 3 == 011   ans=2

How to find?
eg 
 n=5
 int ans=0
 while(n>1)
 {
    if(n%2!=0)
        ans+=1;
    n=n/2;
 }
 return ans+1       (+1 as in number 1 there is one activated bit)
 
  5%2!=0  ans=1    n=2   (5/2)
  2%2==0  ans=1    n=1   (2/2)
  as n==1  ans=2
 
 So we can see to find for n we call n/2 and if n%2==0  we take it else 1+bits for it
*/