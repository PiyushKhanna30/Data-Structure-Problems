//Loop through A
//for every row traverse till n/2 and keep swaping j & n-1-j th elements and take not before swapping.
//if the matrix is of odd size then the middle of every row need to be toggled so check using if condition.
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(),j,i;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n/2;j++)
            {
                A[i][j] = !A[i][j];
                A[i][n-1-j] = !A[i][n-1-j];
                swap(A[i][n-1-j],A[i][j]);
            }
            if(n%2!=0)
            {
                A[i][j]=!A[i][j];
            }
        }
        return A;
    }
};