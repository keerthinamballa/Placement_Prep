// 1464. Maximum Product of Two Elements in an Array
// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).


int maxProduct(vector<int>& nums){
    int n = nums.size();
    int max1 = nums[0], max2 = INT_MIN;
    int min1 = nums[0], min2 = INT_MAX;
    for(int i=1; i<n; i++){
        if(nums[i] > max1){
            max2 = max1;
            max1 = nums[i];
        }
        else if(nums[i] > max2){
            max2 = nums[i];
        }
        if(nums[i] < min1){
            min2 = min1;
            min1 = nums[i];
        }
        else if(nums[i] < min2){
            min2 = nums[i];
        }
    } 
    return max((max1*max2), (min1*min2));
}

// Time Complexity : O(n)
// Space Complexity : O(1)


