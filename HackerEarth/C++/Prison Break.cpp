/*

Alfie was a prisoner in mythland. Though Alfie was a witty and intelligent guy.He was confident of escaping prison.After few days of observation,He figured out that the prison consists of () cells.i.e The shape of prison was () matrix. Few of the cells of the prison contained motion detectors.So Alfie planned that while escaping the prison he will avoid those cells containing motion detectors.Yet before executing his plan,Alfie wants to know the total number of unique possible paths which he can take to escape the prison.Initially Alfie is in cell
() while the exit of the cell ().

note:->Alfie can move in all four direction{ if his current location is (), he can move to either
(), (), (), () }. If the first cell () and the last cell() contain motion detectors,then Alfie can't break out of the prison.

INPUT:

The first line contain number of test cases "T".T test cases follow.The first line of each test case contains an integer "N",(i.e the size of the () matrix).The next n lines contain N space separated values either 0 or 1."1" represents a cell containing motion detectors.

OUTPUT:

output total number of unique possible paths which he can take to escape the prison.

Constraint:



SAMPLE INPUT 
3
4
0 1 1 0 
0 0 1 0 
0 0 0 0 
0 1 1 0 
4
0 0 0 1 
0 0 0 0 
1 1 1 0 
1 0 0 0 
4
0 1 1 0 
0 0 1 1 
0 0 0 0 
0 1 0 0 
 


SAMPLE OUTPUT 
2
4
4

*/


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&matrix,vector<vector<bool>>&visited,int x, int y,int &count)
{
	int n = matrix.size();
	if (x >= n-1 && y >= n-1)
	{
		count++;
		return;
	}
	visited[x][y] = 1;
	if (x+1 <= n-1 && matrix[x+1][y] == 0 && visited[x + 1][y] == 0)
		dfs(matrix,visited,x+1, y,count);
	if (x-1 >= 0 && matrix[x-1][y] == 0 && visited[x - 1][y] == 0)
		dfs(matrix,visited,x-1, y,count);
	if (y+1 <= n-1 && matrix[x][y+1] == 0 && visited[x][y + 1] == 0)
		dfs(matrix,visited,x, y+1,count);
	if (y-1 >= 0 && matrix[x][y-1] == 0 && visited[x][y - 1] == 0)
		dfs(matrix,visited,x, y-1,count);
	visited[x][y] = 0;
	return;
}
int main()
{
	int testCases;
	cin>>testCases;
	while(testCases--)
	{
		int n;
		cin>>n;
		int count=0;
		vector<vector<int>>matrix(n,vector<int>(n));
		vector<vector<bool>>visited(n,vector<bool>(n));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>matrix[i][j];
				visited[i][j]=false;
			}
		}
		if(n==0)
		{
			cout<<"0"<<endl;
		}
		else
		{
			dfs(matrix,visited,0,0,count);
			cout<<count<<endl;
		}

	}
}