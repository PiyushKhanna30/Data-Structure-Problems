/**You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.


Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10


Note: Your solution should run in O(log n) time and O(1) space.
**/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        for(int i=0;i<nums.size()-1;i+=2)
        {
            if(nums[i]!=nums[i+1])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};
/**
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int x=nums[0];
        for(int i=1;i<nums.size();i++)
            x=x^nums[i];
        return x;
    }
};
**/
/**
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }
        if (nums[0]!=nums[1]) {
            return nums[0];
        }
        int n=nums.size();
        if (nums[n-1] != nums[n-2]) {
            return nums[n-1];
        }
        int left=0;
        int right=nums.size()-1;
        while (left<=right) {
            int mid=left+(right-left)/2;
            if (nums[mid]!=nums[mid+1] && nums[mid] != nums[mid-1]) {
                return nums[mid];
            }
            //element has only one single non duplicate
            //even-odd size zone
            if (mid%2==0 and nums[mid]==nums[mid+1]) {
                //mid%2==0, means even index, so left size has even number of elements
                left=mid+1;
            } else if (mid%2==1 and nums[mid]==nums[mid-1]) {
                //mid%2==1 means odd index, so left size has even number of elements
                //including mid
                left=mid+1;
            } else {
                right=mid-1;
            }
        }
        return -1;
    }
};
**/
