class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>output;//for output
        if(n<3)//if less than 3 elements return empty
            return output;
        vector<int>temp(3,0);//to store triplet
        sort(nums.begin(),nums.end());//sorting nums
        for(int i=0;i<n-1;i++)            //loop over nums till n-1 as k=n-1
        {
            int a=nums[i];                //first number for triplet
            if(i!=0 && nums[i-1]==nums[i])//checking if pairs have been found for this number then continue
            {
                continue;
            }                              
            
            //since we want sum 0 and array is sorted so if greatet than 0                                              //then j , k also results greater than 0
            if(a>0)
            {
                break;
            }
            
            temp[0]=a;//put 1st number in temp vector
            int j=i+1;//set j pointer
            int k=n-1;//set k pointer
            while(j<k)
            {
                if(a+nums[j]+nums[k]==0)    //if sum==0 so push in out array and increment j and decrement k
                {
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    output.push_back(temp);
                    j++;
                    k--;
                    ///Using while loop till previous were same so to avoid duplicates
                    while(j<k && nums[j-1]==nums[j])
                        j++;
                    while(j<k && nums[k+1]==nums[k])
                        k--;
                }
                if(a+nums[j]+nums[k]>0)
                {
                    k--;
                    while(j<k && nums[k+1]==nums[k])
                        k--;
                }
                if(a+nums[j]+nums[k]<0)
                {
                    j++;
                    while(j<k && nums[j-1]==nums[j])
                        j++;
                }
            }
        }
        return output;
    }
};
/*
1. Sort the input array.
2. Find three indexes from the array i, j and k where A[i]+A[j]+A[k] = given sum value.
3. Fix the first element as A[i] and iterate i from 0 to array size – 2.
4. For each iteration of i, take j to be index of the first element in the remaining elements and k to be index of the last element.
5. Check for the triplet combination A[i]+A[j]+A[k] = given sum value.
6. If triplet is obtained (ie., A[i]+A[j]+A[k] = given sum value)
    6.1. Add all the triplet in a TreeSet with “:” separated value to get the unique triplets.
    6.2. increment the second value index
    6.3. decrement the third value index.
    6.4. repeat step 4 & 5 till j < k
7. Else if, A[i]+A[j]+A[k] < given sum value, increment the second value index
7. Else if, A[i]+A[j]+A[k] > given sum value, decrement the third value index
*/