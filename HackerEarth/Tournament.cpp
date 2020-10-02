/*

Lord Paul of the Seven Kingdoms has organized a fighting tournament between all the warriors of the kingdom. He finally gets the match summary of the entire tournament, which states which warrior fought with which warrior. Lord Paul wants you to find out the number of warriors who participated in maximum number of matches. (Which means they survived these many matches!) If there are warriors with equal number of matches, print all of them in lexicographical order (sorted order).

Input:

First line of input contains number of matches N.
Next N lines contains two names of worriers who fought with each other.

Output:

Print number of worriers who participated in maximum numbers of matches. If there are warriors with equal number of matches, print all of them in lexicographical order (sorted order).

Constraints:

1 = N = 105
1 = |length of team name| = 20

Note:

All team names will be in Uppercase only.

SAMPLE INPUT 
5
GER JAP
IND JAP
GER JAP
IND BRZ
IND POL

SAMPLE OUTPUT 
2
IND
JAP


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int>mp;
	long long int n;
	cin>>n;
	int max_count = 0;
	for(int i=0;i<n;i++)
	{
		string str1,str2;
		cin>>str1>>str2;
		mp[str1]+=1;
		mp[str2]+=1;
		max_count = max(max_count,max(mp[str1],mp[str2]));
	}
	vector<string>ans;
	long long int counter=0;
	for(auto names : mp)
	{
		if(names.second == max_count)
		{
			counter+=1;
			ans.push_back(names.first);
		}
	}
	cout<<counter<<endl;
	for(auto name : ans)
		cout<<name<<"\n";
}
