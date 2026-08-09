// Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium
// Language: cpp
// Runtime: N/A
// Memory: 42276000

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n =nums.size();
      if(n<=1)
        return nums;
      vector<int> leftproduct(n,0);
      vector<int> rightproduct(n,0);
      vector<int> ans(n,0);
      leftproduct[0]=1;
      rightproduct[n-1]=1;
      for(int i=1;i<n;i++)
      {
        leftproduct[i]=leftproduct[i-1]*nums[i-1];
        rightproduct[n-i-1]=rightproduct[n-i]*nums[n-i];
        //cout<<rightproduct[n-i]<<" ";
      }
      //rightproduct[0]=rightproduct[1]*nums[1];
      ans[0]=rightproduct[0];
      ans[n-1]=leftproduct[n-1];
      for(int i=1;i<n-1;i++)
      {
        //cout<<leftproduct[i]<<" "<<rightproduct[i]<<endl;
        ans[i]=leftproduct[i]*rightproduct[i];
      }
      return ans;
    }
};
