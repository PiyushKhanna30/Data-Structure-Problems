class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int array_sum=A[0];
        int max_temp=A[0];
        int max_array_sum=A[0];
        int min_temp=A[0];
        int min_array_sum=A[0];
        for(int i=1;i<A.size();i++)
        {
            array_sum+=A[i];
            max_temp=max(max_temp+A[i],A[i]);
            max_array_sum=max(max_array_sum,max_temp);
            min_temp=min(min_temp+A[i],A[i]);
            min_array_sum=min(min_array_sum,min_temp);
        }
        if(min_array_sum==array_sum)
            return max_array_sum;
        return max(max_array_sum,array_sum-min_array_sum);
    }
};
/*
EXPLANATION 

eg [3,-1,2,-1]

array_sum = 3 + (-1) + 2 + (-1)
          = 3
max_array_sum = 3 + (-1) + 2  OR   2 + (-1) + 3
              = 4
min_arr_sum = -1

So Ans considering round can be array_sum + min_arr_sum
                            ==== 3 + (-(-1))
                            ==== 4
                            
BOUNDARY CASES
1. When all negatives
eg  [-1,-2,-3]
array_sum = (-6)
max_array_sum = (-1)
min_array_sum = (-6)

So incase if array_sum == min_array_sum return max_array_sum

2. All positives
eg  [1,2,3]
array_sum = 6
max_array_sum = 6
min_array_sum = 1

Now if we return 6 + (-(1))  == 5 but ans is max_array_sum so return max of these two.
*/