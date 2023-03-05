// 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

void moveZeros(vector<int>& nums){
    int n = nums.size();
    int k = 0;
    for(int i=0; i<n; i++){
        if(nums[i] != 0){
            swap(nums[k],nums[i])
            k++;
        }
    }
}

// Time Complexity : O(n)
// Space Complexity : O(1)


