// 169. Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Moore's Voting Algorithm

int majorityElement(vector<int>& nums){
    int n = nums.size();
    int count = 0, ans = 0;
    for(auto num: nums){
        if(count == 0) ans = num;
        if(num == ans) count++;
        else count--;
    }
    return ans;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


