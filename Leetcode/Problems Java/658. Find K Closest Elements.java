class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> result = new ArrayList<>();
        int left = 0, right = arr.length - 1;
        while (right - left >= k) {
            if (Math.abs(arr[left] - x) > Math.abs(arr[right] - x))//when left value diff > than right one, don't include left value
                left++;
            else
                right--;
        }
        for (int i = left; i <= right; i++)
            result.add(arr[i]);
        return result;
    }
    /*
        public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int[][] map = new int[arr.length][2];
        for (int i = 0; i < arr.length; i++) {
            map[i][0] = arr[i];
            map[i][1] = Math.abs(arr[i] - x);
        }

        Arrays.sort(map, (a, b) -> a[1] < b[1] ? -1 : a[1] == b[1] ? a[0] - b[0] : 1);

        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < k; i++)
            res.add(map[i][0]);
        Collections.sort(res);
        return res;
    }
     */
}
