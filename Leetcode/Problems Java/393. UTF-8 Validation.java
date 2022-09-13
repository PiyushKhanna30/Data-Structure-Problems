class Solution {
    public boolean validUtf8(int[] data) {
        int remaining = 0;
        for (int number : data) {
            if (remaining == 0) {
                if ((number >> 5) == 0b110) remaining = 1;
                else if ((number >> 4) == 0b1110) remaining = 2;
                else if ((number >> 3) == 0b11110) remaining = 3;
                else if ((number >> 7) != 0) return false;
            } else {
                if ((number >> 6) != 0b10) return false;
                else remaining -= 1;
            }
        }
        return remaining == 0;
    }
}
