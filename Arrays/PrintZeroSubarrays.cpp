// Print all subarrays with 0 sum
// Given an integer array, print all subarrays with zero-sum.

vector<pair<int,int>> findSubarrays(vector<int>& nums){
    int n = nums.size();
    vector<pair<int, int>> res;
    unordered_map<int, vector<int>> m;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == 0){
            res.push_back(make_pair(0, i));
        }
        if(m.find(sum) != m.end()){
            vector<int> v = m[sum];
            for(auto it = v.begin(), it != v.end(); it++){
                res.push_back(make_pair(*it + 1, i));
            }
        }
        m[sum].push_back(i);
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

