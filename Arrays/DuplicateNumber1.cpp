// Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

int duplicate(vector<int>& nums){
    int n = nums.size();
    for(int num: nums){
        int idx = abs(num);
        if(nums[idx] < 0){
            return idx;
        }
        nums[idx] = -nums[idx];
    }
    return n;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

