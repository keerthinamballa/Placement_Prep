// Print continuous subarray with maximum sum
// Given an integer array, find and print a contiguous subarray with the maximum sum in it.

vector<int> maxSubarray(vector<int>& nums){
    int sum = 0, res = INT_MIN;
    int start = 0, end = 0;
    int beg = 0;
    for(int num: nums){
        sum += num;
        if(sum < num){
            beg = i;
            sum = num;
        }
        if(res < sum){
            res = sum;
            start = beg;
            end = i;
        }
    }
    return {start, end};
}

// Time Complexity : O(n)
// Space Complexity : O(1)


