//InPlace solution
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i=0;i<A.size();i++)
        {
            if(i%2!=A[i]%2)
            {
                int index = i+1;
                while(index<A.size())
                {
                    if(index%2!=A[index]%2)
                    {
                        swap(A[i],A[index]);
                        break;
                    }
                    index+=2;
                }
            }
        }
        return A;
    }
};

// Using extra space
// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& A) {
//         vector<int>result(A.size());
//         int e =0,o=1;
//         for(int i=0;i<A.size();i++)
//         {
//             if(A[i]%2==0)
//             {
//                 result[e]=A[i];
//                 e+=2;
//             }
//             else
//             {
//                 result[o]=A[i];
//                 o+=2;
//             }
//         }
//         return result;
//     }
// };