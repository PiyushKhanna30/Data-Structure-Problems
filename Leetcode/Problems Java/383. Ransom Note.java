class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] chars = new int[26];
        for (char ch : magazine.toCharArray())
            chars[ch - 'a'] += 1;

        for (char ch : ransomNote.toCharArray()) {
            if (chars[ch - 'a'] == 0) return false;
            chars[ch - 'a'] -= 1;
        }
        return true;
    }
}