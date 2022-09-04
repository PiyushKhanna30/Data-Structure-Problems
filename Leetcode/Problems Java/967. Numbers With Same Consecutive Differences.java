class Solution {
    public int[] numsSameConsecDiff(int n, int k) {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= 9; i++) queue.add(i);
        int temp = 1;
        while (temp < n) {
            temp += 1;
            Queue<Integer> newQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                int x = queue.poll();
                int y = x % 10;
                if (y + k < 10) newQueue.add((x * 10) + (y + k));
                if (k > 0 && y - k >= 0) newQueue.add((x * 10) + (y - k));
            }
            queue = newQueue;
        }
        return queue.stream().mapToInt(i -> i).toArray();
    }
}
