class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int result = 0;
        int maxBulbNoSeen = -1;
        for(int i=0;i<light.size();i++)
        {
            maxBulbNoSeen = max(maxBulbNoSeen,light[i]);
            if(maxBulbNoSeen == i+1)
                result+=1;
        }
        return result;
    }
};