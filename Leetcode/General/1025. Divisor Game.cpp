class Solution {
public:
    bool divisorGame(int N) {
        return N%2==0?true:false;
    }
};
/*
if Alice will lose for N, then Alice will must win for N+1, since Alice can first just make N decrease 1.
for any odd number N, it only has odd factor, so after the first move, it will be an even number
eg

4 
person N  options x
Alice  4  [1,2]   1	(To make N-x an odd number)
Bob    3  [1]     1
Alice  2  [1]     1
Bob    1  []      -  LOSE
*/