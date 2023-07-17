// 26. Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// -> Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// -> Return k.

// BRUTE FORCE:

int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    set<int> s;
    for(auto num:nums){
        s.insert(num);
    }
    return s.size();
}

// T.C = O(N)
// S.C = O(N)

// OPTIMIZED SOLUTION:

int removeDuplictes(vector<int> &nums){
    int n = nums.size();
    int idx = 0;
    for(int i=1; i<n; i++){
        if(nums[i] != nums[idx]){
            nums[idx+1] = nums[i];
            idx++;
        }
    }
    return idx+1;
}

// T.C = O(N)
// S.C = O(1)



