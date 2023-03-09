// 532. K-diff Pairs in an Array
// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
// ->0 <= i, j < nums.length
// ->i != j
// ->nums[i] - nums[j] == k


int countPairs(vector<int>& nums, int k){
    int n = nums.size();
    unorderes_map<int, int> m;
    for(int num:nums){
        m[num]++;
    }
    int count = 0;
    for(auto x : m){
        if(k == 0){
            if(x.second >= 2) count++;
        }
        else if(m.find(x.first + k) != m.end()) count++;
    }
    return count;
}

// Time Complexity : O(n)
// Space Complexity : O(n)



