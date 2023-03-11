Find all triplets in a sorted array that forms Geometric Progression

vector<vector<int>> geometricTriplets(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> res;
    if(n < 3) return res;
    for(int i=1; i<n-1; i++){
        int j = i-1, k = i+1;
        while(j >=0 && k < n){
            while(nums[i]%nums[j] == 0 && nums[k]%nums[i] == 0 && nums[i]/nums[j] == nums[k]/nums[i]){
                res.push_back({nums[i], nums[j], nums[k]});
                j--; k++;
            }
            if(nums[i]%nums[j] == 0 && nums[k]%nums[i] == 0){
                if(nums[i]/nums[j] < nums[k]/nums[i]){
                    j--;
                }
                else k++;
            }
            else if(nums[i]%nums[j] == 0){
                k++;
            }
            else j--;
        }
        return res;

    }
}

// Time Complexity : O(n^2)
// Space Complexity : O(1)


