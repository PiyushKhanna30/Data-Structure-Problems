class Solution {
public:
    vector<int>a;
    int n;
    Solution(vector<int>& w) {
        n=w[0];
        for(int i=1;i<w.size();i++)
        {
            w[i]+=w[i-1];
            n=w[i];
        }
        a=w;
        
    }
    
    int pickIndex() {
        int r =rand();
        r=r%n;
        for(int i=0;i<a.size();i++)
        {
            if(r<a[i])
                return i;
        }
        return NULL;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */