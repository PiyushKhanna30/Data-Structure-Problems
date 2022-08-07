import java.util.HashMap;
import java.util.Map;

class Solution {
    Map<Character, char[]> map;
    Map<Character, int[]> dp;
    int mod = (int) (Math.pow(10, 9) + 7);

    public Solution() {
        map = new HashMap<>();
        dp = new HashMap<>();
        map.put('s', new char[]{'a', 'e', 'i', 'o', 'u'});
        map.put('a', new char[]{'e'});
        map.put('e', new char[]{'a', 'i'});
        map.put('i', new char[]{'a', 'e', 'o', 'u'});
        map.put('o', new char[]{'i', 'u'});
        map.put('u', new char[]{'a'});
    }

    public int countVowelPermutation(int n) {
//        return countHelperRecursive('s', n);

//        dp.put('s', new int[n + 1]);
//        dp.put('a', new int[n + 1]);
//        dp.put('e', new int[n + 1]);
//        dp.put('i', new int[n + 1]);
//        dp.put('o', new int[n + 1]);
//        dp.put('u', new int[n + 1]);
//        return countHelperDP('s', n, dp);
        return countVowelPermutationDP(n);
    }

    private int countVowelPermutationDP(int n) {

        long[][] dp = new long[5][n + 1];

        dp[0][1] = 1;
        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[3][1] = 1;
        dp[4][1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[0][i] = dp[1][i - 1];
            dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % mod;
            dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % mod;
            dp[3][i] = (dp[2][i - 1] + dp[4][i - 1]) % mod;
            dp[4][i] = dp[0][i - 1];
        }
        int ans = 0;
        for (int i = 0; i < 5; i++)
            ans = (int) ((ans + dp[i][n]) % mod);
        return ans;
    }

    private int countHelperDP(char prev, int rem, Map<Character, int[]> dp) {
        if (rem == 0)
            return 1;
        if (dp.get(prev)[rem] != 0)
            return dp.get(prev)[rem];
        for (char ch : map.get(prev))
            dp.get(prev)[rem] = (dp.get(prev)[rem] + countHelperDP(ch, rem - 1, dp)) % mod;

        return dp.get(prev)[rem];
    }

    private int countHelperRecursive(char prev, int rem) {
        if (rem == 0)
            return 1;
        int count = 0;
        for (char ch : map.get(prev)) {
            count += countHelperRecursive(ch, rem - 1);
        }
        return count;
    }
}
