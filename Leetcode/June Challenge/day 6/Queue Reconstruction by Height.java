class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people,new Comparator<int[]>()
        { 
            public int compare(int []a,int []b)
            {
                if(a[0]==b[0])
                {
                    if(a[1]>b[1])
                        return 1;
                    return -1;
                }
                if(a[0]>b[0])
                    return 1;
                return -1;
            }
        });
        int [][]ans=new int[people.length][2];
        for(int i=0;i<people.length;i++)
        {
            // System.out.println(people[i][0]+" "+people[i][1]);
            ans[i][0]=-1;
            ans[i][1]=-1;
        }
        for(int i=0;i<people.length;i++)
        {
            int counter=people[i][1];
            for(int j=0;j<people.length;j++)
            {
                if(ans[j][0]==-1 && counter==0)
                {
                    ans[j][0]=people[i][0];
                    ans[j][1]=people[i][1];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>=people[i][0])
                {
                    counter-=1;
                }
            }
        }
        return ans;
    }
}