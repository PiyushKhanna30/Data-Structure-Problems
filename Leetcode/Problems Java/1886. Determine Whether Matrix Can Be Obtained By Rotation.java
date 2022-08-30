class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        for (int i = 1; i <= 4; i++) {
            if (isSame(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }

    private boolean isSame(int[][] mat, int[][] target) {
        int n = target.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }

    private void rotate(int[][] matrix) {
        transpose(matrix);
        reverseRows(matrix);
    }

    private void reverseRows(int[][] matrix) {
        int n = matrix.length;
        for (int row = 0; row < n; row++) {
            int l = 0;
            int r = n - 1;
            while (l < r) {
                int temp = matrix[row][l];
                matrix[row][l] = matrix[row][r];
                matrix[row][r] = temp;
                l += 1;
                r -= 1;
            }
        }
    }

    private void transpose(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}
