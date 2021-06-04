class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String>locked = new HashSet<>();
        for(String deadend:deadends)
            locked.add(deadend);
        if(locked.contains(target) || locked.contains("0000"))return -1;
        if(target.equals("0000"))return 0;
        
        Queue<String>q = new LinkedList<>();
        
        q.add("0000");
        locked.add("0000");
        int count = 0;
        while(q.size()!=0){
            int len = q.size();
            while(len!=0){
                len-=1;
                String str = q.poll();
                StringBuilder temp = new StringBuilder(str);
                for(int k=0;k<4;k++){
                    char ch = temp.charAt(k);
                    String t1 = temp.substring(0,k)+ (ch=='0'?9:ch-'0'-1) + temp.substring(k+1);
                    String t2 = temp.substring(0,k)+ (ch=='9'?0:ch-'0'+1) + temp.substring(k+1);
                    
                    if(t1.equals(target)||t2.equals(target))return count+1;
                    
                    if(!locked.contains(t1)){
                        q.add(t1);
                        locked.add(t1);
                    }
                    if(!locked.contains(t2)){
                        q.add(t2);
                        locked.add(t2);
                    } 
                }
            }
            count+=1;
        }
        return -1;
    }
}
