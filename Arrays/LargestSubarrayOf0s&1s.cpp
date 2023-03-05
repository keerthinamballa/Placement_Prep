// Largest subarray of 0's and 1's
// Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

int maxLen(vector<int>& nums){
    int n = nums.size();
    int sum = 0, max_len = 0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        if(nums[i] == 0) sum += -1;
        else sum += nums[i];
        if(sum == 0) max_len = i+1;
        if(m.find(sum) == m.end()){
            m[sum] = i;
        }
        else if(m.find(sum) != m.end()){
            max_len = max(max_len, i - m[sum]);
        }
    }
    return max_len;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


