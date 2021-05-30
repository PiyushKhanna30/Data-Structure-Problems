class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int result = nums[0];
        int left_product=1,right_product=1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            left_product *= nums[i];
            right_product *= nums[n-i-1];
            result = max(result,max(left_product,right_product));
            
            if(left_product==0)
                left_product =1;
            if(right_product==0)
                right_product=1;
        }
        return result;
    }
};

/*
Consider case with even number of negative numbers without 0, then answere is product of all numbers.
Consider odd number of negatives without 0 then for maxima condition we need to leave say smaller negative number as large neagtive number into previous negatives product with be more than other.

So using above idea we can think of using 2 ptrs from both ends
In case of 0 exists then the answere can be on either left side of 0  or right side of zero or might be zero in case like [-1,0,-1]
so we can keep tack of both ptrs maximum to get answere
*/