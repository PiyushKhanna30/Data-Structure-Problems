class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int left = 0;
        int right = tokens.length - 1;
        int tempScore = 0;
        int score = 0;
        Arrays.sort(tokens);
        while (left <= right) {
            if (power >= tokens[left]) {
                tempScore += 1;
                power -= tokens[left++];
                score = Math.max(score, tempScore);
            } else if (tempScore > 0) {
                power += tokens[right--];
                tempScore -= 1;
            } else
                break;
        }
        return score;
    }
}
