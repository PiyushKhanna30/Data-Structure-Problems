/*

There is a street by the name of colorful street in the Pretty Town. The residents of the house have decided that they will paint their houses in either Pink, Orange or Yellow color and not other. They have also decided that no two adjacent houses will have the same color. For house i,  and  are the neighbors and note that the first and the last house are not neighbors.

The cost of painting a house in a particular color is different. The cost of painting the first house in color yellow maybe different than what its for painting the second house in the same color.

You have to find the minimum of cost of painting the houses which satisfy the given condition.

Input Constraints - Number of houses will contain between 1 and  elements, inclusive. - Each line of input for houses will have three values for cost of coloring in each color. Each value will be between 1 and .

Input Format - The first line will contain the number of test cases - T. - The second line will contain an integer N that will specify how many houses are there. - Each of the following N lines will contain 3 numbers separated by space that represents the cost of painting that house in either pink, orange or yellow color.

Output Format Print T lines showing the cost of painting the houses for each test case.

SAMPLE INPUT 
1
2
11 12 13
14 15 16
SAMPLE OUTPUT 
26
Explanation
The first house should be painted in pink (), the second should be painted in orange (). So the total cost becomes 



*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
	int testCase;
	cin>>testCase;
	while(testCase--)
	{
		int N;
		cin>>N;
		vector<vector<int>>colors(N,vector<int>(3));
		for(int i=0;i<N;i++)
		{
			cin>>colors[i][0]>>colors[i][1]>>colors[i][2];
		}
		for(int i=1;i<N;i++)
		{
			colors[i][0]+=min(colors[i-1][1],colors[i-1][2]);
			colors[i][1]+=min(colors[i-1][0],colors[i-1][2]);
			colors[i][2]+=min(colors[i-1][0],colors[i-1][1]);
		}
		cout<<min(colors[N-1][0],min(colors[N-1][1],colors[N-1][2]))<<endl;
	}
}