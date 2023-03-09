// 2367. Number of Arithmetic Triplets
// You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
// ->i < j < k,
// ->nums[j] - nums[i] == diff, and
// ->nums[k] - nums[j] == diff.
// Return the number of unique arithmetic triplets.

int countTriplets(vector<int>& nums, int diff){
    vector<int>cnt(201, 0);
    int ans = 0;
    for(int n: nums){
        if(n >= 2*diff){
            ans += cnt[n-diff] && cnt[n-2*diff];
        }
        cnt[n] = 1;
    }
    return ans;
}

// Time Complexity : O(n)
// Space Complexity : O(n)



