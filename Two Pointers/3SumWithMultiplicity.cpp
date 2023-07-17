// 923. 3Sum With Multiplicity
// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
// As the answer can be very large, return it modulo 109 + 7.

// BRUTEFORCE APPROACH:
// It is given here that arr[i] + arr[j] + arr[k] == target. where i < j < k.
// So we can run three loops, i = 0 to n, j = i+1 to n and k = j+1 to n.
// If any triplet forms a sum equal to target, we increment our result variable.
// At the end, we return the result variable.

// T.C = O(N^3)

// OPTIMIZED APPROACH : 

// The idea is to maintain an unordered_map which stores the frequency of the sum of a pair of intergers;
// We run a loop i = 0 to n, if we pick an element at any index, our taget reduces to target - arr[i].
// We use unordered_map to check if the sum of target - nums[i] is encountered before or not, and we add it's frequency to the result variable.
// At the same time we run a loop inside the outer loop to update the map with new sum.
//At the end we return the result variable.

int threeSumMultiplicity(vector<int> &nums, int target){
    int n = nums.size();
    unordered_map<int, int> m;
    int res = 0;
    int mod = (int)(1e9 + 7);
    for(int i=0; i<n; i++){
        res = (res + m[target - arr[i]])%mod;
        for(int j=0; j<i; j++){
            m[arr[i] + arr[j]]++;
        }
    }
    return res%mod;
}

// T.C = O(N^2)
// S.C = O(MAXSUM that is possible)


