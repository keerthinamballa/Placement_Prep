// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value

int getFirst(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > target) high = mid - 1;
        else if(nums[mid] < target) low = mid+1;
        else{
            if(mid == 0 || nums[mid-1] != nums[mid]) return mid;
            else high = mid-1;
        }
    }
    return -1;
}


int getLast(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > target) high = mid - 1;
        else if(nums[mid] < target) low = mid+1;
        else{
            if(mid == nums.size() - 1 || nums[mid+1] != nums[mid]) return mid;
            else low = mid+1;
        }
    }
    return -1;
}


vector<int> range(vector<int>& nums, int target){
    int first = getFirst(nums, target);
    if(first == -1) return {-1, -1};
    int last = getLast(nums, target);
    return {first, last};
}

// Time Complexity : O(log n)
// Space Complexity : O(1)

