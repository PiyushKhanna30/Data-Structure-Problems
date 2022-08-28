class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        Map<Integer, PriorityQueue<Integer>> hashmap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hashmap.putIfAbsent(i - j, new PriorityQueue<>());
                hashmap.get(i - j).add(mat[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = hashmap.get(i - j).poll();


        return mat;
    }
}
