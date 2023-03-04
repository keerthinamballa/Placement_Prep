// Subarray with 0 sum
// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

bool zeroSubarray(vector<int>& nums){
    int n = nums.size();
    unordered_set<int> s;
    int sum = 0;
    for(int i==0; i<n; i++){
        sum += nums[i];
        if(sum == 0) return true;
        if(s.find(sum) != s.end()){
            return true;
        }
        s.insert(sum);
    }
    return false;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
