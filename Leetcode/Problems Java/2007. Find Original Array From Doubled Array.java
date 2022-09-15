class Solution {
    public int[] findOriginalArray(int[] changed) {
        //if length of array not even
        if (changed.length % 2 != 0) return new int[0];

        int[] res = new int[changed.length / 2];
        int i = 0;
        //Sort Array
        Arrays.sort(changed);
        Map<Integer, Integer> map = new HashMap<>();
        //Map of values and there counts
        Arrays.stream(changed).forEach(n -> map.put(n, map.getOrDefault(n, 0) + 1));

        for (int n : changed) {
            if (map.get(n) <= 0) continue;
            if (map.getOrDefault(n * 2, 0) <= 0) return new int[0];

            map.put(n, map.get(n) - 1);
            map.put(n * 2, map.get(2 * n) - 1);
            res[i++] = n;
        }
        return res;
    }
}
