class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for(int i=0;i<n;i++)
        {
            int num = 2*i +start;
            result = result ^ num;
        }
        return result;
    }
};