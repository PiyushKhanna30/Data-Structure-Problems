class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=2*n-2;i>0;i--)
        {
            int k = i;
            do
            {
                if(k%2==1)
                    k=k/2 +n;
                else
                    k=k/2;
            }while(k>i);
            swap(nums[i],nums[k]);
        }
        return nums;
    }
};

// O(n) memory O(1)space
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         int j = n-1;
//         for(int i=2*n-1;i>=n;i--,j--)
//         {
//             nums[i] = nums[i]<<10;
//             nums[i] = nums[i]|nums[j];
//         }
        
//         //1023 == 1111111111
//         j=0;
//         for(int i=n;i<2*n;i++)
//         {
//             int num1 = nums[i]&1023;
//             int num2 = nums[i]>>10;
//             nums[j] = num1;
//             nums[j+1] = num2;
//             j+=2;
//         }
//         return nums;
//     }
// };

// O(n) Space O(n) Memory
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int>arr(2*n);
//         int j=0;
//         for(int i=0;i<n;i++)
//         {
//             arr[j++] = nums[i];
//             arr[j++] = nums[i+n];
//         }
//         return arr;
//     }
// };