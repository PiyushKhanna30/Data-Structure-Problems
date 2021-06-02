class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        // return recur(s1,s2,s3,0,0,0);
        boolean dp[][] = new boolean[s1.length()][s2.length()];
        return recur(s1,s2,s3,0,0,0, dp);
    }
    
    private boolean recur(String s1,String s2,String s3, int i,int j,int k){
        if(k==s3.length())return true;
        
        boolean takeS1 = false;
        if(i<s1.length() && s1.charAt(i)==s3.charAt(k))
            takeS1 = recur(s1,s2,s3,i+1,j,k+1);
        
        boolean takeS2 = false;
        if(j<s2.length() && s2.charAt(j)==s3.charAt(k))
            takeS2 = recur(s1,s2,s3,i,j+1,k+1);
        
        return takeS1 || takeS2;
    }
    
    private boolean recur(String s1,String s2,String s3, int i,int j,int k, boolean dp[][]){
        if(i==s1.length())return s2.substring(j).equals(s3.substring(k));
        if(j==s2.length())return s1.substring(i).equals(s3.substring(k));
        
        if(dp[i][j])return true;
        
        if((s1.charAt(i)==s3.charAt(k) && recur(s1,s2,s3,i+1,j,k+1,dp)) || (s2.charAt(j)==s3.charAt(k) && recur(s1,s2,s3,i,j+1,k+1,dp)))
            dp[i][j]=true;
        
        return dp[i][j];
    }
}
