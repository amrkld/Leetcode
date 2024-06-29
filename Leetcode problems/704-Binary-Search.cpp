class Solution {
public:
    int helper(vector<int>& nums, int target, int l, int r){
        if (l > r) return -1; 

        int mid = l + (r - l) / 2;
        
        if (nums[mid] == target) {
            return mid; 
        } else if (nums[mid] > target) {
            return helper(nums, target, l, mid - 1);
        } else {
            return helper(nums, target, mid + 1, r);
        }
    }

    int search(vector<int>& nums, int target) {
       int l = 0;
       int r = nums.size()-1;

       return helper(nums, target, l, r);
    }
};