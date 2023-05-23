class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0;
        int cows = 0;
        Map<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) 
                bulls += 1;
            else
                mp.put(secret.charAt(i), mp.getOrDefault(secret.charAt(i), 0) + 1);
        }
        System.out.println(mp);
        for (int i = 0; i < guess.length(); i++) {
            char ch = guess.charAt(i);
            if (!(secret.charAt(i) == guess.charAt(i)) && mp.containsKey(ch) && mp.get(ch) > 0) {
                cows += 1;
                mp.put(ch, mp.get(ch) - 1);
            }
        }
        return new StringBuilder().append(bulls).append('A').append(cows).append('B').toString();
    }
}
