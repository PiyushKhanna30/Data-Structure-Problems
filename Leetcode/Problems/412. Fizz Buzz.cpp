class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0 && i%5==0)
            {
                ans.push_back("FizzBuzz");
            }
            else if(i%5==0)
            {
                ans.push_back("Buzz");
            }
            else if(i%3==0)
            {
                ans.push_back("Fizz");
            }
            else
            {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};

/*

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i=1; i<=n; i++){result.push_back(to_string(i));}
        for(int i=2; i<n; i=i+3){result[i] = "Fizz";}
        for(int i=4; i<n; i=i+5){result[i] = "Buzz";}
        for(int i=14; i<n; i=i+15){result[i] = "FizzBuzz";}
        return result;
    }
};

*/