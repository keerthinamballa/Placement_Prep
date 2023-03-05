// Maximum length Bitonic Subarray
// Given an array Arr[0 … N-1] containing N positive integers, a subarray Arr[i … j] is bitonic if there is a k with i <= k <= j such that A[i] <= Arr[i+1] <= ... <= Arr[k] >= Arr[k+1] >= ... A[j – 1] >= A[j]. Write a function that takes an array and array length as arguments and returns the length of the maximum length bitonic subarray.

int longestBitonic(vector<int>& nums){
    int n = nums.size();
    vector<int> inc(n);
    vector<int> dec(n);
    inc[0] = 1;
    dec[n-1] = 1;
    for(int i=1; i<n; i++){
        inc[i] = (nums[i] > nums[i-1]) ? inc[i-1]+1:1;
    }
    for(int i=n-2; i>=0; i--){
        dec[i] = (arr[i] > arr[i+1]) ? dec[i+1]+1:1;
    }

    int max_len = inc[0]+dec[0]-1;
    for(int i=1; i<n; i++){
        if(inc[i]+dec[i]-1 > max_len){
            max_len = inc[i]+dec[i]-1;
        }
    }
    return max_len;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


