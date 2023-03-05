// Longest Sub-Array with Sum K
// Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

int maxSubarray(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int, int> m;
    int sum = 0;
    int max_len = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == k) max_len = i+1;
        if(m.find(sum) == m.end()){
            m[sum] = i;
        }
        if(m.find(sum -k) != m.end()){
            max_len = max(max_len, i - m[sum-k]);
        }
    }
    return max_len;
}

//Time Complexity : O(n)
//Space Complexity : O(n)
