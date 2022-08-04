// room_extension * p = no_reflections * q
// (1+_)                (1+_)
class Solution {
    public int mirrorReflection(int p, int q) {
        int ext = q;
        int ref = p;

        while (ext % 2 == 0 && ref % 2 == 0) {
            ext /= 2;
            ref /= 2;
        }

        if (ext % 2 == 0 && ref % 2 != 0) return 0;
        else if (ext % 2 != 0 && ref % 2 == 0) return 2;
        else if (ext % 2 != 0 && ref % 2 != 0) return 1;
        return -1;
    }
}
