// 1004. Max Consecutive Ones III
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

int longestOnes(vector<int>& nums, int k){
    int n = nums.size();
    int max_len = 0, count = 0;
    int left = 0;
    for(int right = 0; right < n; right++){
        if(nums[right] == 0) count++;
        while(count > k){
            if(nums[left] == 0) count--;
            left++;
        }
        max_len = max(max_len, right-left+1);
    }
    return max_len;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

