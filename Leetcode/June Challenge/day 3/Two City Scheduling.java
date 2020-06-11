class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs,new Comparator<int[]>()
        { 
            public int compare(int []a,int []b)
            {
                return (Math.abs(b[0]-b[1])-Math.abs(a[0]-a[1]));
            }
        });
        int a=costs.length/2;
        int b=a;
        int ans=0;
        for(int i=0;i<costs.length;i++)
        {
            if(a>0 && b>0)
            {
                if(costs[i][0]<costs[i][1])
                {
                    ans+=costs[i][0];
                    a-=1;
                }
                else
                {
                    ans+=costs[i][1];
                    b-=1;
                }
            }
            else if(a>0)
            {
                ans+=costs[i][0];
                a-=1;
            }
            else
            {
                ans+=costs[i][1];
                b-=1;
            }
            
        }
        return ans;
    }
}