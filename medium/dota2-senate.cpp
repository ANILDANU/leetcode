// Dota2 Senate
// https://leetcode.com/problems/dota2-senate/
// Difficulty: Medium
// Language: cpp
// Runtime: N/A
// Memory: 11640000

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n = senate.size();
        for(int i = 0;i<n;i++){
            if(senate[i] == 'R')
            r.push(i);
            else
            d.push(i);
        }

        while(!r.empty() && !d.empty()){
            auto i = r.front(), j = d.front();
            r.pop();
            d.pop();

            if(i<j)
                r.push(i+n);
            else
            d.push(j+n);
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};
