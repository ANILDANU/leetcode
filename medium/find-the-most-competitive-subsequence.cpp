// Find the Most Competitive Subsequence
// https://leetcode.com/problems/find-the-most-competitive-subsequence/
// Difficulty: Medium
// Language: cpp
// Runtime: 9
// Memory: 114188000

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      vector<int> s;
      s.push_back(nums[0]);
      int n=nums.size();
      for(int i=1;i<n;i++)
      {
        if(!s.empty()&&s.back()<nums[i]&&s.size()<k)
        {
          s.push_back(nums[i]);
        }
        else
        {
          while(!s.empty()&&s.back()>nums[i]&&s.size()+n-i>k)
          {
            s.pop_back();
          }
          if(s.size() < k)
          s.push_back(nums[i]);
        }
      }
      return s;
        
    }
};
