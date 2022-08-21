class Solution {
    private boolean canReplace(char[] targetChars, int pos, char[] stampChars){
        for(int i = 0;i<stampChars.length;i++){
            if(targetChars[pos+i]!=stampChars[i] && targetChars[pos+i]!='?')
                return false;
        }
        return true;
    }
    private int replace(char[] targetChars, int pos, int len, int countOfQ){
        for(int i=0;i<len;i++){
            if(targetChars[i+pos]!='?'){
                targetChars[i+pos]='?';
                countOfQ+=1;
            }
        }
        return countOfQ;
    }
    public int[] movesToStamp(String stamp, String target) {
        char[] stampChars = stamp.toCharArray();
        char[] targetChars = target.toCharArray();
        boolean[] visited = new boolean[target.length()];
        int countOfQ = 0;
        List<Integer>res = new ArrayList<>();
        
        while(countOfQ!=target.length()){
            boolean changed = false;
            for(int i=0;i<=target.length()-stamp.length();i++){
                if(visited[i]==false && canReplace(targetChars, i, stampChars)){
                    countOfQ = replace(targetChars, i, stampChars.length, countOfQ);
                    visited[i] = true;
                    changed = true;
                    res.add(i);
                }
                if(countOfQ == target.length())
                    break;
            }
            if(!changed)return new int[0];
        }
        int k = res.size();
        int[] result = new int[k--];
        for(int x:res)
            result[k--] = x;
        return result;
    }
}
