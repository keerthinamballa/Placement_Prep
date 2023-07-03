// 992. Subarrays with K Different Integers
// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.


int atmost(vector<int> &nums, int k){
    int n = nums.size();
    int left = 0, right = 0;
    int res = 0;
    unordered_map<int, int> m;
    while(right < n){
        m[nums[right]]++;
        while(m.size() > k){
            m[nums[left]]--;
            if(m[nums[left]] == 0) m.erase(nums[left]);
            left++;
        }
        res += right-left+1;
        right++;
    }
    return res;
}

int subarrayWithKDistinct(vector<int> &nums, int k){
    return atmost(nums, k) - atmost(nums, k-1);
}

// Time Complexity : O(n)
// Space Complexity : O(n)



