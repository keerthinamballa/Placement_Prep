// 18. 4Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// -> 0 <= a, b, c, d < n
// -> a, b, c, and d are distinct. 
// -> nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.


vector<vector<int>> fourSum(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<int>> res;
    if(n < 4) return res;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-3; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j<n-2; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int l = j+1, r = n-1;
            while(l < r){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                if(sum < target) l++;
                else if(sum > target) r--;
                else{
                    res.push_back({nums[i] , nums[j], nums[l], nums[r]});
                    l++; r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }
            }
        }
    }
    return res;
}

// Time Complexity : O(n^3)
// Space Complexity : O(1)


