class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size();
        if(m==0)return false;
        int n = matrix[0].size();
        if(n==0)return false;
        int beg =0,end =n*m-1;
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2;
            if(matrix[mid/n][mid%n]==target)
            {
                return true;
            }
            else if(matrix[mid/n][mid%n]<target)
            {
                beg = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return false;
    }
};

// O(m+n)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m =matrix.size();
//         if(m==0)return false;
//         int n = matrix[0].size();
//         if(n==0)return false;
        
//         int i=0,j=n-1;
//         while(j>=0 && i<m)
//         {
//             if(matrix[i][j]==target)
//             {
//                 return true;
//             }
//             else if(matrix[i][j]<target)
//             {
//                 i++;
//             }
//             else
//             {
//                 j--;
//             }
//         }
//         return false;
        
//     }
// };

//O(m*n)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m =matrix.size();
//         if(m==0)return false;
//         int n = matrix[0].size();
//         if(n==0)return false;
        
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(matrix[i][j]==target)
//                     return true;
//             }
//         }
//         return false;
//     }
// }; 