// Maximum difference between two elements such that larger element appears after the smaller number

int maxDifference(vector<int>& nums){
    int n = nums.size();
    int max_diff = nums[1] - nums[0];
    int min_ele = nums[0];
    for(int i = 1; i<n; i++){
        if(nums[i] - min_ele > max_diff){
            max_diff = nums[i] - min_ele;
        }
        if(nums[i] < min_ele){
            min_ele = nums[i];
        }
    }
    return max_diff;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

