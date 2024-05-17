class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        if(piles.length > h )return -1;
        int maxBan = 0;
        for(int pile:piles)
            maxBan = Math.max(maxBan, pile);
        int start = 1;
        int end = maxBan;
        int k = end;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(isValidK(piles, mid, h)){
                k = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return k;
    }
    private boolean isValidK(int[] piles, int k, int h){
        int time = 0;
        for(int i=0; i<piles.length; i++){
            if(piles[i]%k ==  0)
                time+=(piles[i]/k);
            else
                time+=((piles[i]/k)+1);
            if(time>h)return false;
        }
        return true;
    }
}
