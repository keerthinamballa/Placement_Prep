// 1004. Max Consecutive Ones III
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

int maxConsecutive(vector<int> &nums, int k){
    int n = nums.size();
    int left = 0, right = 0, count = 0, res = 0;
    while(right < n){
        if(nums[right] == 0) count++;
        while(count > k){
            if(nums[left] == 0) count--;
            left++;
        }
        res = max(res, right-left+1);
        right++;
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

