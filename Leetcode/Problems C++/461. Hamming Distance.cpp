/*
// Approch 1
// 1.Take vector of size 32 all initial values as 0
// 2.Represent x in bits in the vector using xor. So when bit in x ==1 xor of 1^0==1.
// 3.Represent y in bits in the vector using xor. So when bit in y ==1 and bit in vector==0 then 1 else 0.
// 5 loop over vector and count 1's.

// eg 2,6
// bits=[0,0,0,0]

// put 2
// bits=[0,1,0,0]

// put 6
// bits=[0,0,1,0]

// counting 1's ==1

class Solution {
public:
    void setBits(vector<int>&bits,int x)        
    {
        int i=0;
        while(x)
        {
            if(x==1)
            {
                bits[i]=bits[i]^1;
                break;
            }
            if(x%2==0)
            {
                x=x/2;
                bits[i]=bits[i]^0;
            }
            else
            {
                x=x/2;
                bits[i]=bits[i]^1;
            }
            i++;
        }
    }
    int hammingDistance(int x, int y) {
        vector<int>bits(32,0);
        setBits(bits,x);
        setBits(bits,y);
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(bits[i]==1)
                ans+=1;
        }
        return ans;
    }
};
*/
/*
Approach 2
1. take xor of x ^ y=z;
2. take and with 1 of z untill 0 and shift left in each step and count the 1's 
eg. 2,6
2=010
6=110
z=100
    -->100&1==0
    -->010&1==0
    -->001&1==1
    -->000 break loop
ans =1

*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y;
        int ans=0;
        while(z)
        {
            ans+=z&1;
            z=z>>1;
        }
        return ans;
    }
};
