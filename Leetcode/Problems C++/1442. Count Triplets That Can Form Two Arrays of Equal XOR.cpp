class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>prefix(arr.size()+1);
        prefix[0]=0;
        int i=0;
        for(i=0;i<arr.size();i++)
        {
            prefix[i+1]=prefix[i]^arr[i];
        }
        int result =0;
        for(i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<prefix.size();j++)
            {
                if(prefix[i]==prefix[j])
                    result+=(j-i-1);
            }
        }
        return result;           
    }
};

//Why k-i-1 not k-i
//So consider [4(0),1(1),2(2),3(3)]  so we hve seen 4 at index 0 and marked. again we see it at index 3 so we know i<j<=k so values of j can be k-i but here that i need to begin from index 1 so we add additional -1 ie 3 - 0 -1 =2

// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         unordered_map<int,pair<int,int>>mp;
//         //mp [number] [count] [sum of indexes]
        
//         mp[0] = make_pair(1,-1);
//         int result = 0;
//         int x=0;
//         for(int i=0;i<arr.size();i++)
//         {
//             x = x^arr[i];
//             if(mp.find(x)!=mp.end())
//             {
//                 result += i*mp[x].first - mp[x].second - mp[x].first;
//             }
//             mp[x].first+=1;
//             mp[x].second +=i;
//         }
//         return result;
//     }
// };

//LOGIC
//4 1 2 3
//[0 : [1 -1]]
//[4 : [1  0]]
//[5 : [1  1]]
//[7 : [1  2]]
//              result = 3 * 1 - 0 - 1 ([4 :[1 0]) = 2


// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         int n = arr.size();
//         if(n<2)
//             return 0;
//         int a = 0,b=0;
//         int result = 0;
//         for(int k=0;k<=n-2;k++)
//         {
//             for(int i=k;i<=n-2;i++)
//             {
//                 a = a^arr[i];
//                 // cout<<a<<" ";
//                 for(int j=i+1;j<=n-1;j++)
//                 {
//                     b = b^arr[j];
//                     if(a==b)
//                         result+=1;
//                     // cout<<arr[j]<<" ";
//                 }
//                 // cout<<endl;
//                 b=0;
//             }
//             a=0;
//         }
//         return result; 
//     }
// };


