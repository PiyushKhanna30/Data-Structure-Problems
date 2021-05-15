#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,i,j;
    cin>>k;
    string s;
    cin>>s;
    int l=s.length();
    int ans=0;
    
    for(i=0;i<l;i++)
    {
        int h[26]={0}; 
        int dist_count=0;
        for(j=i;j<l;j++)
        {
if(h[s[j]-'a']==0) dist_count++;
            if(dist_count==k) ans++;
            h[s[j]-'a']=1;
        }
    }
    cout<<ans<<endl;
}