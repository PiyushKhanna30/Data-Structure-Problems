class Solution {
public:
    void swap(int* x,int* y)
    {
        int t = *x;
        *x = *y;
        *y = t;
    }
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(&matrix[i][j],&matrix[j][i]);
            }
        }
    }
};
/*
METHOD 2
class Solution {
public:
    void swap(int* x,int* y)
    {
        int t = *x;
        *x = *y;
        *y = t;
    }
    void rotate(vector<vector<int>>& matrix) {
        int b = matrix.size();
        b-=1;
        int a=0;
        while(a<b)
        {
            for(int i=0;i<(b-a);i++)
            {
                swap(&matrix[a][a+i],&matrix[a+i][b]);
                swap(&matrix[a][a+i],&matrix[b][b-i]);
                swap(&matrix[a][a+i],&matrix[b-i][a]);
            }
            a++;
            b--;
        }
    }
    
};
*/
/*
CLOCK WISE ROTATION
Method 1 : 
1 2 3       7 8 9       7 4 1
4 5 6  ->   4 5 6   ->  8 5 2
7 8 9       1 2 3       9 6 3

step1 : reverse vector
step2 : swap along symetry

Method 2 :
Note when rotating 1st element goes to last element in same rows pos
so we need to run till a < n

also in second row we do this in inner matrix (think like gears for locker) so in each iteration of outer loop we decrease size of matrix
*/
/*
ANTI CLOCKWISE
Method 1 : 
1 2 3       3 2 1       3 6 9
4 5 6  ->   6 5 4   ->  2 5 8
7 8 9       9 8 7       1 4 7
step1 : reverse each vector individually
step2 : swap along symetry
*/