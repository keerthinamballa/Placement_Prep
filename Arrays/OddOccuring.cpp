// Find the odd occurring element in an array in a single traversal
// Given an integer array, duplicates are present in it in a way that all duplicates appear an even number of times except one which appears an odd number of times. Find that odd appearing element in linear time and without using any extra memory.


int oddElement(vector<int>& nums){
    int n = nums.size();
    int x = 0;
    for(auto a : nums){
        x ^= a;
    }
    return x;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


