// Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Difficulty: Medium
// Language: cpp
// Runtime: 7
// Memory: 19536000

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        for(int i = 2;i<n;i++){
            if(nums[i] == nums[i-2])
            nums[i-2] = -100000;

        }

        for(int i = 0;i<n;i++){
        //cout<<nums[i]<<" ";
        if(nums[i] == -100000)
        cur++;

        }

        int left = 0;
        for(int i = 0;i<n;i++){

            if(nums[i] != -100000){
                swap(nums[i],nums[left]);
                left++;
            }

        }
        return n - cur;
    }
};
