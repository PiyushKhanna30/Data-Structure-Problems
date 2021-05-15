class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int>que;
        int n=deck.size();
        sort(deck.begin(),deck.end()); //O(nLog(n))
        que.push_back(deck[n-1]);
        for(int i=n-2;i>=0;i--) //O(n)
        {
            que.push_front(que.back());
            que.pop_back();
            que.push_front(deck[i]);
        }
        
        // vector<int>result;
        // for(int a:que)
        //     result.push_back(a);
//         OR
        vector<int>result(que.begin(),que.end());
        return result;
    }
};
// Reverse process thinking
// "Neeche se nikal ke upar rakhuga, bahar se nikalke upar rakhuga"