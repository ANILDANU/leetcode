// Jump Game VI
// https://leetcode.com/problems/jump-game-vi/
// Difficulty: Medium
// Language: cpp
// Runtime: 85
// Memory: 219140000

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
         int ans =INT_MIN;

        //vector<int> dp(nums.size(),INT_MIN);
        deque<pair<int,int>> dq;
        for(int i=0;i<nums.size();i++){
            //cout<<i<<" "<<endl;
            if(!dq.empty())
            //cout<<dq.front().first<<" "<<dq.front().second<<endl;
            while(!dq.empty() &&  i - dq.back().second > k){
                dq.pop_back();
            }
            int sum =nums[i];
            if(!dq.empty())
            sum = nums[i]+dq.back().first;
            //cout<<sum<<endl;
            while(!dq.empty() && dq.front().first <= sum){
                dq.pop_front();
            }

            dq.push_front({sum,i});
            //cout<<i<<" "<<sum<<endl;
            ans =sum;
        }
        return ans;
    }
};
