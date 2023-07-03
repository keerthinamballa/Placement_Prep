// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


int minSizeSum(int target, vector<int>& nums){
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0, res = INT_MAX;
    while(right < n){
        sum += nums[right];
        if(sum >= target){
            res = min(res, right-left+1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    if(res == INT_MAX) return 0;
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
