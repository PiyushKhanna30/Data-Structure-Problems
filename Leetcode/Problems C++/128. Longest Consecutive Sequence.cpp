/*
Method 1:
Sort -> using for loop find longest consecutive sequence.
O(nlog(n))   O(n)   === O(nlog(n))

Method2
put all numbers in unordered_set O(n)

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>st;
        for(int num:nums)
        {
            st.insert(num);
        }
        int result =1;
        for(int num:nums)
        {
            if(st.find(num-1)==st.end() && st.find(num+1)!=st.end())
            {
                int temp = num+2;
                int count = 2;
                while(st.find(temp)!=st.end())
                {
                    count++;
                    temp++;
                }
                result = max(result,count);
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0)return 0;
//         sort(nums.begin(),nums.end());
//         int result =1;
//         int count =1;
//         int prev = nums[0];
//         for(int i=1;i<nums.size();i++)
//         {
//             if(prev == nums[i])
//                 continue;
//             if(nums[i]==prev+1)
//             {
//                 count++;
//             }
//             else
//             {
//                 result = max(result,count);
//                 count = 1;
//             }
//             prev = nums[i];
//         }
//         result = max(result,count);
//         return result;
//     }
// };