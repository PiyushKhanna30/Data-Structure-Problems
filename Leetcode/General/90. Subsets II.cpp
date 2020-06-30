#include <bits/stdc++.h>
using namespace std;
void findSubsets(int index,vector<int>&nums,vector<int>&small_subset,set<vector<int>>&ans_subsets)
{
    vector<int>temp=small_subset;
    sort(temp.begin(),temp.end());
    ans_subsets.insert(temp);
    for(int i=index;i<nums.size();i++)
    {
        small_subset.push_back(nums[i]);
        findSubsets(i+1,nums,small_subset,ans_subsets);
        small_subset.pop_back();
    }
}

void subsets(vector<int>& nums) {
    set<vector<int>>ans_subsets;
    int index=0;
    vector<int>small_subset;
    findSubsets(index,nums,small_subset,ans_subsets);
    for(auto i:ans_subsets)
    {
        int x=0;
        cout<<"(";
        for(auto j:i)
        {
            if(x==0)
            {
                cout<<j;
                x=1;
            }
            else
            {
                cout<<" "<<j;
            }
        }
        cout<<")";
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>nums(n);
	    for(int i=0;i<n;i++)
	        cin>>nums[i];
	    subsets(nums);
	    cout<<endl;

	}
	return 0;
}
