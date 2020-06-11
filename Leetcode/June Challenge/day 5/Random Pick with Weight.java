class Solution {
    int []arr;
    int n;
    public Solution(int[] w) {
        arr=new int [w.length];
        arr[0]=w[0];
        for(int i=1;i<w.length;i++)
        {
            w[i]=w[i-1]+w[i];
            arr[i]=w[i];
        }
        int index=w.length-1;
        n=arr[index];
    }
    
    public int pickIndex() {
        double rand=Math.random()*n;
        for(int i=0;i<arr.length;i++)
        {
            if(rand<arr[i])
            {
                return i;
            }
        }
        return arr.length-1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */