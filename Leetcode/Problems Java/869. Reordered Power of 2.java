class Solution {
    public boolean reorderedPowerOf2(int n) {
        int[] countOfNums = getNumsMap(n);
        int powerOf2 = 1;
        for (int i = 0; i < 31; i++) {
            int[] countOfNumsP2 = getNumsMap(powerOf2);
            if (equalCounts(countOfNums, countOfNumsP2)) return true;
            powerOf2 = powerOf2 << 1;
        }
        return false;
    }

    private int[] getNumsMap(int n) {
        int[] count = new int[10];
        while (n > 0) {
            count[n % 10] += 1;
            n /= 10;
        }
        return count;
    }

    private boolean equalCounts(int[] countOfNums, int[] countOfNumsP2) {
        for (int i = 0; i < 10; i++) {
            if (countOfNums[i] != countOfNumsP2[i]) return false;
        }
        return true;
    }
}
