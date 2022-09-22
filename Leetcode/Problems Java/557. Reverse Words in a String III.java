class Solution {
    public String reverseWords(String s) {
        int n = s.length(), l = 0;
        char[] chars = s.toCharArray();
        for (int r = 0; r < n; r++) {
            if (chars[r] == ' ' || r == n - 1) {
                reverse(chars, l, r == n - 1 ? r : r - 1);
                l = r + 1;
            }
        }
        return new StringBuilder(String.valueOf(chars)).toString();
    }

    private void reverse(char[] chars, int l, int r) {
        while (l < r) {
            char temp = chars[l];
            chars[l++] = chars[r];
            chars[r--] = temp;
        }
    }
}
