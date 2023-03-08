// 152. Maximum Product Subarray
// Given an integer array nums, find a 
// subarray that has the largest product, and return the product.

int maxProduct(vector<int>& nums){
    int n = nums.size();
    int curr_max = nums[0], curr_min = nums[0], max_product = nums[0];
    for(int i=1; i<n; i++){
        int temp = curr_max;
        curr_max = max(nums[i],max(nums[i]*curr_max, nums[i]*curr_min));
        curr_min = max(nums[i], min(nums[i]*curr_min, nums[i]*temp));
        max_product = max(max_product, curr_max);
    }
    return max_product;
}


// Time Complexity : O(n)
// Space Complexity : O(1)




