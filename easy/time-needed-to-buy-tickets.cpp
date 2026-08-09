// Time Needed to Buy Tickets
// https://leetcode.com/problems/time-needed-to-buy-tickets/
// Difficulty: Easy
// Language: cpp
// Runtime: N/A
// Memory: 10488000

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(),x = tickets[k],ans = tickets[k];

        for(int i = 0;i<n;i++){
            if(i == k)
            continue;

            if(i<k){
                ans = ans + min(tickets[i],tickets[k]);
            }
            else
            ans = ans + min(tickets[i],tickets[k]-1);
        }
        return ans;
    }
};
