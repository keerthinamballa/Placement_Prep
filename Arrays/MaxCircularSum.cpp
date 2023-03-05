// 918. Maximum Sum Circular Subarray
// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


int maxCircularSum(vector<int>& nums){
    int curr_max = 0, curr_min = 0, sum = 0, max_sum = nums[0], min_sum = nums[0];
    for(int num: nums){
        curr_max = max(curr_max, 0) + num;
        max_sum = max(max_sum, curr_max);
        curr_min = min(curr_min, 0) + num;
        min_sum = min(min_sum, curr_min);
        sum += num;
    }
    return (sum == min_sum) ? max_sum : max(max_sum, sum - min_sum);
}

// Time Complexity : O(n)
// Space Complexity : O(1)

