// Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Language: cpp
// Runtime: N/A
// Memory: 22640000

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;

        
        for(int r = 1;r<nums.size();r++){
            // if(nums[r]== nums[r-1])
            // continue;
            if(nums[r] != nums[r-1]){
                nums[l] = nums[r];
                l++;
            }
        }

        return l;
    }
};
