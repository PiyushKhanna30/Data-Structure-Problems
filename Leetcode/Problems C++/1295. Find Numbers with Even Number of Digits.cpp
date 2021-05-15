//See range of inputs,10^5 so 
//10<100;1000<10,000;100,000
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int num:nums)
        {
            if((num>=10 && num<100)||(num>=1000 && num<10000)||num==100000)
                result+=1;
        }
        return result;
    }
};