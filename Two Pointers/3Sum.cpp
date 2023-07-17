// 15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// BRUTE FORCE:

vector<vector<int>> 3sum(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> res;
    set<vector<int>> s;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    for(auto x : s){
        res.push_back(x);
    }
    return res;
}

// T.C = O(N)


// BETTER APPROACH:

vector<vector<int>> 3sum(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> res;
    set<vector<int>> s;
    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int sum = -(nums[i] + nums[j]);
            if(hashset.find(sum) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], sum};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
        }
    }
    for(auto x : s){
        res.push_back(x);
    }
    return res;
}

// OPTIMIZED SOLUTION:

vector<vector<int>> 3sum(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i=0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1; k = n-1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                res.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return res;
}

// T.C = O(n^2log(n))


