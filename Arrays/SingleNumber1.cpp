// 260. Single Number III
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.


vector<int> singleElement(vector<int>& nums){
    unsigned int res = 0;
    for(int i: nums){
        res  = res^i;
    }
    int k = log2(res & -res);
    int x = 0, y = 0;
    for(int i : nums){
        if(i & (1 << k)){
            x = x^i;
        }
        else{
            y = y^i;
        }
    }
    return {x, y};
}

// Time complexity : O(n)
// Space Complexity : O(1)


