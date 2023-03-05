// 53. Maximum Subarray
// Given an integer array nums, find the 
// subarray with the largest sum, and return its sum.

int maxSubarray(vector<int>& nums){
    int sum = 0, res = INT_MIN;
    for(int num: nums){
        sum += num;
        res = max(res, sum);
        if(sum < 0) sum = 0;
    }
    return res;
}

// Time Complexity: O(n)
// Space Complexity : O(1)



