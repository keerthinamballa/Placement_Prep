// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


int minSize(vector<int>& arr, int target){
    int n = arr.size();
    int left = 0, sum = 0;
    int min_len = INT_MAX;
    for(int right = 0; right < n; right++){
        sum += arr[right];
        while(sum >= target){
            min_len = min(min_len, right- left+1);
            sum -= arr[left];
            left++;
        }
    }
    return (min_len != INT_MAX)?min_len:0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

