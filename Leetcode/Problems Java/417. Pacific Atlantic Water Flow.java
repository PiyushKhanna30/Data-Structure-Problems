import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        boolean[][] pacific = new boolean[n][m];
        boolean[][] atlantic = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            fill(heights, pacific, i, 1, heights[i][0]);
            atlantic[i][m - 1] = true;
            fill(heights, atlantic, i, m - 2, heights[i][m - 1]);
        }
        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            fill(heights, pacific, 1, j, heights[0][j]);
            atlantic[n - 1][j] = true;
            fill(heights, atlantic, n - 2, j, heights[n - 1][j]);
        }


        List<List<Integer>> res = new ArrayList<>();
        List<Integer> subAns;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] == true && atlantic[i][j] == true) {
                    subAns = new ArrayList<>();
                    subAns.add(i);
                    subAns.add(j);
                    res.add(subAns);
                }
            }
        }
        return res;
    }

    private void display(boolean[][] ocean, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(ocean[i][j] + " ");
            }
            System.out.println();
        }
    }

    private void fill(int[][] heights, boolean[][] ocean, int i, int j, int prevHeight) {
        int n = heights.length;
        int m = heights[0].length;
        if (i < 0 || i == n || j < 0 || j == m) return;
        if (heights[i][j] < prevHeight) return;
        if (ocean[i][j]) return;
        ocean[i][j] = true;
        fill(heights, ocean, i - 1, j, heights[i][j]);
        fill(heights, ocean, i, j + 1, heights[i][j]);
        fill(heights, ocean, i + 1, j, heights[i][j]);
        fill(heights, ocean, i, j - 1, heights[i][j]);
    }
}
