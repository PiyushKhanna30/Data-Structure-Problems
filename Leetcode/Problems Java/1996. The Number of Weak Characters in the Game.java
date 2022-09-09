class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
//        [[5, 5],[6, 3],[3, 6],[1, 1],[1, 2],[2, 5]]
        Arrays.sort(properties, (p1, p2) -> p1[0] != p2[0] ? (p2[0] - p1[0]) : (p1[1] - p2[1]));
//        Arrays.stream(properties).forEach(x -> System.out.print("[" + x[0] + "," + x[1] + "], "));
//        [[6, 3], [5, 5], [3, 6], [2, 5], [1, 1], [1, 2]]
        int maxDefence = 0;
        int result = 0;
        for (int[] property : properties) {
            if (property[1] < maxDefence)
                result += 1;
            maxDefence = Math.max(maxDefence, property[1]);
        }
        return result;

    }
}
