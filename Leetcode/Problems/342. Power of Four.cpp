class Solution {
public:
    bool isPowerOfFour(int num) {
        double ans = log10(num)/log10(4);
        return fmod(ans,1)==0?true:false;
    }
};