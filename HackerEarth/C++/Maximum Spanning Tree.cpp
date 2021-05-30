/*

You are given a weighted graph with N vertices and M edges. Find the total weight of its maximum spanning tree.

Input

The first line contains one integer T denoting the number of test cases. Each test case starts with a line containing 2 space-separated integer: N and M. Each of the following M lines contain description of one edge: three different space-separated integers: a, b and c. a and b are different and from 1 to N each and denote numbers of vertices that are connected by this edge. c denotes weight of this edge.

Output

For each test case output one integer - the total weight of its maximum spanning tree.

Constraints

1 <= T <= 20
1 <= N <= 5000
1 <= M <= 100 000
1 <= c <= 10 000
SAMPLE INPUT 
1
3 3
1 2 2
2 3 3
1 3 4
SAMPLE OUTPUT 
7

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
    return a.weight>b.weight;
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
	long long ans=0;
    while(cou!=v-1)
    {
        Edge current_edge=input[i];
        int sourceParent=findParent(current_edge.source,parent);
        int destParent=findParent(current_edge.destination,parent);
        if(sourceParent!=destParent)
        {
			ans+=current_edge.weight;
            output[cou]=current_edge;
            cou++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
	cout<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
{		int v,e;
		cin>>v>>e;
		Edge *input=new Edge[e];
		for(int i=0;i<e;i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			input[i].source=s-1;
			input[i].destination=d-1;
			input[i].weight=w;
		}
		kruskal(input,v,e);}
}