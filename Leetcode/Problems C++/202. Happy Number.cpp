class Solution {
public:
    bool isHappy(int n) {
        set<int>saved;
        while(1)
        {
            int sum=0;
            saved.insert(n);
            while(n)
            {
                int rem = n%10;
                sum += (rem*rem);
                n = n/10;
            }
            n=sum;
            if(n==1)
                return true;
            if(saved.find(n) != saved.end())
                return false;
        }
    }
};