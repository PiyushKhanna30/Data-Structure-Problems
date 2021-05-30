/*

Consider arr = [1,2,3,4,5]
here size ie n = 5 and let index i = 1
All possible subarrays with 2 as element are

[1,2]
[1,2,3]
[1,2,3,4]
[1,2,3,4,5]
[2]
[2,3]
[2,3,4]
[2,3,4,5]
Total = 8

Formula to find these is (i+1)*(n-i) ie how many times arr[i] ie 2 appears in sub arrays. Logic(how many numbers before including it can be starting numbers in subarray * how many numbers including it and ahead can mark as ending of sub array)

now see the list it has 8/2 ie 4 sub arrays with odd length and 4 with even.
(you can see that number of odd length is 1+ in case of odd)

so total number of times 2 sum in odd length is = 2*4.


Similarly considering above procedure for all we find

i    i+1   n-i    (i+1)*(n-i)    ceil((i+1)*(n-i)/2.0)    sum
0    1     5      5              3                        1*3 = 3
1    2     4      8              4                        2*4 = 8
2    3     3      9              5                        3*5 = 15
3    4     2      8              4                        4*4 = 16
4    5     1      5              3                        5*3 = 15
ans = 57
*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
        int n =arr.size();
        for(int i=0;i<n;i++)
        {
            result += ceil((i+1)*(n-i)/2.0)*arr[i];
        }
        return result;
    }
};


// Naive Approach
// class Solution {
// public:
//     int sumOddLengthSubarrays(vector<int>& arr) {
//         int result= 0;
//         int odd = 1;
//         int n=arr.size();
//         while(odd<=n)
//         {
//             for(int i=0;i<=n-odd;i++)
//             {
//                 int odd_counter = odd;
//                 int j=i;
//                 while(odd_counter--)
//                 {
//                     cout<<arr[j]<<" ";
//                     result+=arr[j++];
//                 }
//                 cout<<endl;
//             }
//             odd+=2;
//         }
//         return result;
//     }
// };