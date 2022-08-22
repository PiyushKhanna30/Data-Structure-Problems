class Solution {
    public boolean isPowerOfFour(int n) {
        if(n == 1)return true;
        else if(n<4 || n%4!=0)return false;
        return isPowerOfFour(n/4);
    }
    // public boolean isPowerOfFour(int n) {
    //     double res = Math.log(n) / Math.log(4);
    //     return res == (int)res;
    // }
}
