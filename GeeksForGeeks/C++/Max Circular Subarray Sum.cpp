
#include <bits/stdc++.h>
using namespace std;
int circularSum(int arr[],int n)
{
    int total_arr_sum=arr[0];
    int max_arr_sum_hold=arr[0];
    int max_arr_sum=arr[0];
    int min_arr_sum_hold=arr[0];
    int min_arr_sum=arr[0];
    for(int i=1;i<n;i++)
    {
        total_arr_sum+=arr[i];
        max_arr_sum_hold+=arr[i];
        max_arr_sum_hold=max(max_arr_sum_hold,arr[i]);
        max_arr_sum=max(max_arr_sum,max_arr_sum_hold);

        min_arr_sum_hold+=arr[i];
        min_arr_sum_hold=min(min_arr_sum_hold,arr[i]);
        min_arr_sum=min(min_arr_sum,min_arr_sum_hold);
    }
    if(total_arr_sum==min_arr_sum)
        return max_arr_sum;
    return max(max_arr_sum,total_arr_sum-min_arr_sum);

}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<circularSum(arr,n)<<endl;
	}
	return 0;
}
