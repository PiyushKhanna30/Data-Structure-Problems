class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>counts(101,0),countSum(101);
        for(int i:nums)
            counts[i]+=1;
        countSum[0]=0;
        for(int i=1;i<101;i++)
        {
            countSum[i] = counts[i-1]+countSum[i-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = countSum[nums[i]];
        }
        return nums;
    }
};

// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int>sorted(nums),result(nums.size());
//         sort(sorted.begin(),sorted.end());
//         auto it =sorted.begin();
//         for(int i=0;i<nums.size();i++)
//         {
//             it = find(sorted.begin(),sorted.end(),nums[i]);
//             result[i] = it-sorted.begin();
//         }
//         return result;
//     }
// };

// // class Solution {
// // public:
// //     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
// //         vector<int>result(nums.size());
// //         int n = nums.size();
// //         for(int i=0;i<n;i++)
// //         {
// //             int count =0;
// //             for(int j=0;j<n;j++)
// //             {
// //                 if(i!=j && nums[i]>nums[j])
// //                     count+=1;
// //             }
// //             result[i]=count;
// //         }
// //         return result;
// //     }
// // };

// // class Solution {
// // public:
// //     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
// //         vector<int>result(nums.size());
// //         int n = nums.size();
// //         for(int i =0;i<n;i++)
// //         {
// //             int count =0;
// //             for(int j=i+1;j<n;j++)
// //             {
// //                 if(nums[i]<nums[j])
// //                 {
// //                     result[j]+=1;
// //                 }
// //                 else if(nums[i]>nums[j])
// //                 {
// //                     count+=1;
// //                 }
// //             }
// //             result[i]+=count;
// //         }
// //         return result;
// //     }
// // };