// Find the index of 0 to be replaced to get the maximum length sequence of continuous ones
// Given a binary array, find the index of 0 to be replaced with 1 to get the maximum length sequence of continuous ones.

int zeroIndex(vector<int>& nums){
    int n = nums.size();
    int max_count = 0, count = 0;
    int prev_zero_idx = -1,max_idx = -1;
    for(int i=0; i<n; i++){
        if(nums[i] == 1) count++;
        else{
            count = i - prev_zero_idx;
            prev_zero_idx = i;
        }
        if(count > max_count){
            max_count = count;
            max_idx = prev_zero_idx;
        }
    }
    return max_idx;
}


//Time Complexity : O(n)
//Space Complexity : O(1)

