/*

Approach 1:
start from last and set carry =1. with each iteration change digit at the index. at last if carry exist then copy to new vector.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int num = digits[i]+carry;
            digits[i] = num%10;
            carry = num/10;
        }
        if(carry != 0)
        {
            vector<int>dig;
            dig.push_back(carry);
            for(int num : digits)
                dig.push_back(num);
            return dig;
        }
        return digits;
    }
};
Memory O(n)
Space O(n)
*/
//Approach 2 Better
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]==9)            //if digit is 9, so 9+1 = 10 ie 0 and carry 1 or add 1 in i-1
            {
                digits[i]=0;
            }
            else
            {
                digits[i]+=1;           //if digit <9 then +1 will not be greater than or equal to 10 so carry =0 and no need to check prev digits;
                return digits;
            }
        }
        //eg 9,9,9 -> 0,0,0
        digits[0]=1;
        digits.push_back(0);
        return digits;
    }
};
//Space O(1)
//Memory O(n)