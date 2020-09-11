class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int x = tasks.size();
        unordered_map<char,int>m;
        int max_count=0;
        for(int i=0;i<x;i++)
        {
            m[tasks[i]]+=1;
            max_count = max(max_count,m[tasks[i]]);
        }
        int ans = (max_count-1)*(n+1);
        for(auto i : m)
        {
            if(i.second == max_count)
                ans+=1;
        }
        return max(ans,x);
    }
};
/*
First count the number of occurrences of each element.
Let the max frequency seen be M for element E
We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.
*/