class Solution {
    public int minCost(String colors, int[] neededTime) {
        int ans = 0;
        char prevChar = colors.charAt(0);
        int prevTime = neededTime[0];
        for (int i = 1; i < neededTime.length; i++) {
            if (prevChar == colors.charAt(i)) {
                ans += Math.min(prevTime, neededTime[i]);
                prevTime = Math.max(prevTime, neededTime[i]);
            } else {
                prevTime = neededTime[i];
                prevChar = colors.charAt(i);
            }
        }
        return ans;
    }
}
