// 1248. Count Number of Nice Subarrays
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

int countNiceSubarrays(vector<int> &nums, int k){
    return atmost(nums, k) - atmost(nums, k-1);
}

int atmost(vector<int> &nums, int k){
    int n = nums.size();
    int left = 0, right = 0, count = 0, res = 0;
    while(right < n){
        if(nums[right]%2) count++;
        while(count > k){
            if(nums[left]%2) count--;
            left++;
        }
        res += right-left+1;
        right++;
    }
    return res;
}

// T.C = O(N)
// S.C = O(1)

