class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        if (N == 0)                 
            return 0;
        int start = 0;              
        int end = N-1;
        int h = 0;
        while (start <= end){
            int cur = start + (end - start)/2;
            if (citations[cur] >= N-cur)
	    {      
                h = N-cur;
                end = cur-1;           
            } else 
                start = cur+1;        
        }
        return h;
    }
};