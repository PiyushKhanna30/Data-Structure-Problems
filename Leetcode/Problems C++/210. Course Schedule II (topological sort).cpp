class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;                                     ///output array
        vector<vector<int>>edge(numCourses);                ///to store edges.We have each course as an vertex
        vector<int>inDegree(numCourses,0);                  ///to count how many indegree a course/vertex has
        
        ///Loop to input the course [a,b] so b->a so in vertex b add a  and increase inDegree for a so that when we process b then reduce inDegree by 1 . 
        for(int i=0;i<prerequisites.size();i++)              
        {
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]+=1;
        }
        
        queue<int>q;
        /// Find courses that do not require any other course to be done and push into q.
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int n=q.front();                    ///Pop and add to ans vector.
            q.pop();
            ans.push_back(n);
            
            for(int i=0;i<edge[n].size();i++)   ///for every course that required this course to be done decrement the inDegree and if inDegree  0 i.e. no further requirement then push to q. 
            {
                inDegree[edge[n][i]]-=1;
                if(inDegree[edge[n][i]]==0)
                {
                    q.push(edge[n][i]);
                }
            }
        }
        ///If all courses added then return ans else return empty array.
        if(ans.size()==numCourses)
            return ans;
        ///Empty arr eg. [[0,1],[1,0],[1,2]]
        return vector<int>();
    }
};