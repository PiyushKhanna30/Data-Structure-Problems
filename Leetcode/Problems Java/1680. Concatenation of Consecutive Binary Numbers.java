class Solution {
    public int concatenatedBinary(int n) {
        int mod = (int) Math.pow(10, 9) + 7;
        long res = 0L;
        int bits = 0;
        for (int i = 1; i <= n; i++) {
            bits += (i & (i - 1)) == 0 ? 1 : 0;
            res = ((res << bits) + i) % mod;
        }
        return (int) res;
    }
}
