/*

Hash is a lazy dog. His master decided to put it on a behavioral test for two months (60 days). On 1st day the owner keeps a ration of 1 cookie, each day the ration will be doubled. If hash is active on ith day he will be given all the cookies in the ration that day, otherwise, he is given zero cookies.
Given the total number of cookies Hash ate, find the number of days he was active?


Input Format:
The first line of input contain the number of test cases T < 105 .
Followed by T lines each containing an Integer denoting the total number of cookies hash ate N < 10 18.


Output Format:
For each test case print the number of days hash is active in a newline.
SAMPLE INPUT 
2
5
8
SAMPLE OUTPUT 
2
1
Explanation
Test Case 1:
To eat a total of 5 cookies Hash behaved normally 1st day and on the 3rd day.
Test Case 2:
To eat a total of 8 cookies he behaved normally only on the 4th day.


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int test;
	cin>>test;
	while(test--)
	{
		long long int n;
		cin>>n;
		int ans=0;
		
		//See problem when 2^(i) then only one day active else that day + some another day
		while(n!=0)
		{
			if(n%2==0)
			{
				n=n/2;
			}
			else
			{
				ans+=1;
				n=n/2;
			}
		}
		cout<<ans<<endl;
	}
}