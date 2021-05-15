class Solution {
public:
    int findComplement(int N) {
        if(N==0)
            return 1;
        int full_num = 0;
        int N_copy = N;
        while(N_copy)
        {
            full_num = full_num<<1;
            full_num = full_num|1;
            N_copy/=2;
        }
        return full_num^N;
    }
};