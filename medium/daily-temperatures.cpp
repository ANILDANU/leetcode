// Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/
// Difficulty: Medium
// Language: cpp
// Runtime: 16
// Memory: 102884000

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
      int n=temp.size();
      vector<int> ans(n,0);
      stack<int> s;
      s.push(n-1);
      for(int i=n-2;i>=0;i--)
      {
        while(!s.empty()&&temp[s.top()]<=temp[i])
          s.pop();
        if(!s.empty())
          ans[i]=s.top()-i;
        else
          ans[i]=0;
        s.push(i);
      }
      return ans;
    }
};
