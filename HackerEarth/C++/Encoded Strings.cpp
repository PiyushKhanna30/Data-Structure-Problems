/*
You are given a string S, consisting of only lowercase Latin letters and the string is encoded. Each letters has numerical equivalent corresponding to it's position in the Alphabetical order, i.e 'a' corresponds to 1, 'b' corresponds to 2 and so on till 'i' which corresponds to 9.

You have to tell, when the string is decoded into a number by replacing the characters with numbers, if it is divisible by 6.

Input:
The first line contains a string consisting of only Lowercase Latin letters ( 'a'-'i' ).

Output:
Print "YES" (without the quotes) if the decoded number is divisible by 6, "NO" (without the quotes) otherwise.

Constraints:
String will not contain more than 105 characters
1 = |S| = 105

SAMPLE INPUT 
abbd
SAMPLE OUTPUT 
YES
Explanation
The decoded number is 1224, which is divisible by 6.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<char,int>mp;
	mp['a']=1;
	mp['b']=2;
	mp['c']=3;
	mp['d']=4;
	mp['e']=5;
	mp['f']=6;
	mp['g']=7;
	mp['h']=8;
	mp['i']=9;

	string str;
	cin>>str;
	int last;
	int sum=0;
	int n=str.size();
	for(int i=0;i<n;i++)
	{
		sum+=mp[str[i]];
	}
	if(sum%3==0 && str[n-1]%2==0)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}