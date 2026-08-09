// Reveal Cards In Increasing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Difficulty: Medium
// Language: cpp
// Runtime: N/A
// Memory: 12572000

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());

        int n  = deck.size();

        deque<int> dq;

        for(int i = n-1; i>=0; i--){
            if(dq.empty())
            dq.push_back(deck[i]);
            else
            {
                int x = dq.back();
                dq.pop_back();
                dq.push_front(x);
                dq.push_front(deck[i]);
            }
        }

        vector<int> ans;

        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};
