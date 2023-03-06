// Max Sum Subarray of size K
// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

long maxSumSubarray(vector<int>& arr, int k){
    int n = nums.size();
    int i = 0, j= 0;
    long sum = 0, max_sum = 0;
    while(j < n){
        sum += arr[j];
        if(j-i+1 < k) j++;
        else if(j-i+1 == k){
            max_sum = max(max_sum, sum);
            sum -= arr[i];
            i++; j++;
        }
    }
    return max_sum;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

