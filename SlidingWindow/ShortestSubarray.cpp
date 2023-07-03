// 862. Shortest Subarray with Sum at Least K
// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1
// A subarray is a contiguous part of an array.

// What makes this question different is it includes negative values. If all the elements are positive, the cummulative sum graph id monotonically inceasing.
// In case when there are negative elements, the cummulative graph is not monotonically increasing. In case of negative intergers in the array,
// we cannot directly apply the sliding window approach using two pointers "left" and "right". In that case, we will use a deque data structure.

int shortestSubarray(int k, vector<int> &nums){
    int n = nums.size();
    deque<pair<long long, long long>> dq;
    long long sum = 0, smallest = INT_MAX;
    for(long long i=0; i<n; i++){
        sum += nums[i];
        if(sum >= k){
            smallest = min(smallest, i+1);
        }

        pair<long long, long long> curr = {INT_MIN, INT_MIN};

        while(!dq.empty() && sum - dq.front().second){
            curr = dq.front();
            dq.pop_front();
        }

        if(curr.second != INT_MIN){
            smallest = min(smallest, i-curr.first);
        }

        while(!dq.empty() && sum < dq.back().second){
            dq.pop_back();
        }

        dq.push_back({i, sum});
    }

    if(smallest == INT_MAX) return -1;
    return smallest;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


