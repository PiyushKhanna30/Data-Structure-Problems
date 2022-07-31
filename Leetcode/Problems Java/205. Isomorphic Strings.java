class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] sTot = new int[256];
        int[] tTos = new int[256];
        Arrays.fill(sTot,-1);
        Arrays.fill(tTos,-1);
        for(int i=0;i<s.length();i++){
            char a = s.charAt(i);
            char b = t.charAt(i);
            
            if(sTot[a] == b && tTos[b] == a){
                continue;
            }
            else if(sTot[a] == -1 && tTos[b] == -1){
                sTot[a] = b;
                tTos[b] = a;
            }
            else{
                return false;
            }
        }
        return true;
    }
}
