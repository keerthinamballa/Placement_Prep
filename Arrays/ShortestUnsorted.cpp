// 581. Shortest Unsorted Continuous Subarray
// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
// Return the shortest such subarray and output its length.


int shortestWindow(vector<int>& nums){
    int n = nums.size();
    int left = -1, right = -1;
    int min_ele = INT_MAX;
    for(int i=n-1; i>=0; i--){
        if(nums[i] < min_ele) min_ele = nums[i];
        else if(nums[i] > min_ele) left = i;
    }
    if(left == -1) return 0;
    int max_ele = INT_MIN;
    for(int i=0; i<n; i++){
        if(nums[i] > max_ele) max_ele = nums[i];
        else if(nums[i] < max_ele) right = i;
    }
    return right - left + 1;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

