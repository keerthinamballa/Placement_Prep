//Find a triplet that sum to a given value
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == target


vector<vector<int>> triplets(vector<int>& nums, int target){
    int n = nums.size();
    int l, r;
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    vector<vector<int>> res;
    for(int i=0; i<n; i++){
        l = i+1, r = n-1;
        while(l < r){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum == target){
                s.insert({nums[i], nums[l], nums[r]});
                l++; r--;
            }
            else if(sum < target) l++;
            else r--;
        }
    }
    for(auto t: s) res.push_back(t);
    return res;
}

// Time Complexity : O(n^2)
// Space Complexity: O(n)


