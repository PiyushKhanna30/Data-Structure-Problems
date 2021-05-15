/*

It is very important to understand relationship between variables to draw the right conclusion from a statistical analysis. The relationship between variables determines how the right conclusions are reached. Without an understanding of this, you can fall into many pitfalls that accompany statistical analysis and infer wrong results from your data.

Linear programming (LP; also called linear optimization) is a method to achieve the best outcome (such as maximum profit or lowest cost) in a mathematical model whose requirements are represented by linear relationships. More formally, linear programming is a technique for the optimization of a linear objective function, subject to linear equality and linear inequality constraints.

We are not going to present some LP theory, but let's have a look at combinatorial problem related to this theory. Suppose you have a set of N variables. There are M relationships of some pairs of these variables. More formally, you have M relationships of type ai, bi, ci which means that variables ai and bi are in a relationship with quantitative coefficient ci. Quantitative coefficient of a connected set S of variables is a product of all relationship quantitative coefficients in this set.

Set S of variables is called connected if any two variables in this set are connected. Variables x and y are called connected if at least one of the following conditions is satisfied:

x and y are put in relationship directly
there is such a variable z that x and z are connected and y and z are connected too.
You are given a connected set S of N variables and M relationships. Your task is to leave some of these relationships in such a way that S is still connected and its quantitative coefficient is minimal possible.

Input

The first line contains one integer T denoting the number of test cases.
Each test case starts with a line containing 2 space-separated integer: N and M. Each of the following M lines contain description of one relationship: three different space-separated integers: a, b and c. a and b are different and from 1 to N each and denote numbers of vertices that are connected by this edge. c denotes quantitative coefficient of this relationship. It's guaranteed that the given set is initially connected.

Output

For each test case output one integer - minimal possible quantitative coefficient. As the the answer can be very big output it modulo 109 + 7.

Constraints

1 <= T <= 20
1 <= N <= 1500
1 <= M <= 31313
1 <= ai, bi <= N
1 <= ci <= 109
SAMPLE INPUT 
1
3 3
1 2 1234567
2 3 2345678
1 3 3456789

SAMPLE OUTPUT 
896631161


*/




#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int source;
    int destination;
    int weight;
};
bool compare(Edge a,Edge b)
{
    return a.weight<b.weight;
}
int findParent(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    return findParent(parent[v],parent);
}
void kruskal(Edge *input,int v,int e)
{
    sort(input,input+e,compare);

    Edge *output=new Edge[v-1];
    int cou=0;
    int i=0;
    int *parent=new int[v];
    for(int i=0;i<v;i++)
        parent[i]=i;
    while(cou!=v-1)
    {
        Edge current_edge=input[i];
        int sourceParent=findParent(current_edge.source,parent);
        int destParent=findParent(current_edge.destination,parent);
        if(sourceParent!=destParent)
        {
            output[cou]=current_edge;
            cou++;
            parent[sourceParent]=destParent;
        }
        i++;
    }

	long long  ans =1;
	long long  mod = pow(10,9)+7;
    for(int i=0;i<v-1;i++)
    {
            ans *= output[i].weight;
			ans%=mod;
    }
	cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
		int v,e;
		cin>>v>>e;
		Edge *input=new Edge[e];
		for(int i=0;i<e;i++)
		{
			int s,d;
			long long w;
			cin>>s>>d>>w;
			input[i].source=s-1;
			input[i].destination=d-1;
			input[i].weight=w;
		}
		kruskal(input,v,e);
	}
}