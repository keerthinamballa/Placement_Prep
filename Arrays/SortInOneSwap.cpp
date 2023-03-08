// Check if array can be sorted with one swap
// Given an array containing N elements. Find if it is possible to sort it in non-decreasing order using atmost one swap.

bool sortByOne(vector<int>& nums){
    int n = nums.size();
    int first = 0, second = 0, count = 0;
    for(int i=1; i<n; i++){
        if(nums[i] < nums[i-1]){
            count++;
            if(first == 0) first = i;
            else second = i;
        }
    }
    if(count > 2) return false;
    if(count == 0) return true;
    if(count == 2){
        swap(nums[first-1], nums[second]);
    }
    if(count == 1){
        swap(nums[first-1], nums[first]);
    }
    for(int i=1; i<n; i++){
        if(nums[i] < nums[i-1]) return false;
    }
    return true;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


