class Solution {
public:
    int numTeams(vector<int>& rating) {
        if(rating.size()<3)
            return 0;
        int n = rating.size();
        int result = 0;
        for(int i=0;i<n;i++)
        {
            int less_in_left = 0;
            int less_in_right = 0;
            int more_in_left = 0;
            int more_in_right = 0;
            for(int j=0;j<i;j++)
            {
                if(rating[j]>rating[i])
                    more_in_left+=1;
                else
                    less_in_left+=1;
            }
            
            for(int j=i+1;j<n;j++)
            {
                if(rating[j]>rating[i])
                    more_in_right+=1;
                else
                    less_in_right+=1;
            }
            result += (less_in_right*more_in_left + less_in_left*more_in_right);
        }
        return result;
    }
};

// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int groups = 0;
//         if(rating.size()<3)
//             return 0;
//         for(int i=0;i<rating.size()-2;i++)
//         {
//             for(int j=i+1;j<rating.size()-1;j++)
//             {
//                 for(int k=j+1;k<rating.size();k++)
//                 {
//                 if((rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j]>rating[k]))
//                     {
//                         groups+=1;
//                     }
//                 }
//             }
//         }
//         return groups;
//     }
// };