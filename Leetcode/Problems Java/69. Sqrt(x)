class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;
        int left = 0;
        int right = x / 2 + 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;

            if (mid == x / mid) return mid;
            else if (mid > x / mid) right = mid - 1;
            else {
                mid += 1;
                if (mid > x / mid) return mid - 1;
                left = mid;
            }
        }
        return mid;
    }
}
