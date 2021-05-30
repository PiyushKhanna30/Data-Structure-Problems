// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Number of bits to represent int
#define INT_BITS 32
int maxSubarrayXOR(int [], int n);
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
      scanf("%d",&n);

        for(int i=0;i<n;i++)
            {
            scanf("%d",&a[i]);
            }



printf("%d\n",maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;


    }
}// } Driver Code Ends

int find(int A[],int n,int i,int ans)
{

    if(i==n)
    {
        return ans;
    }
    return max(find(A,n,i+1,ans^A[i]),find(A,n,i+1,ans));
}
// Function to return maximum XOR subset in set[]
int maxSubarrayXOR(int A[], int n)
{
    //Your code here
    return find(A,n,0,0);
}
