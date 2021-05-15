// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n==1)
//             return false;
//         while(n % 3 == 0)
//         {
//             n/=3;
//         }
        
//         return n==1?true:false;
//     }
// };
class Solution {
public:
    bool isPowerOfThree(int n) {
        //n = 3^i
        //log(n) = i*log(3)
        //log(n)/log(3) = i
        //If log term is integer then true else false
        //so to check float pt remainder is int then true else false
        double ans = log10(n)/log10(3);
        return fmod(ans,1)==0?true:false;
    }
};
