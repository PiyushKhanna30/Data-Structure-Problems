class Solution {
    public boolean isSubsequence(String s, String t) {
        if (t.length()<s.length())
            return false;
        if (s.length()==0)
            return true;
        int j=0; 
        for(int i=0;i<t.length();i++)
        {
            if(t.charAt(i)==s.charAt(j))
            {
                j++;
                if (s.length()==j)
                    return true;
            }
        }
        return false;
    }
}