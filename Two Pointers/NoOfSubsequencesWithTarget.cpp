// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// You are given an array of integers nums and an integer target.
// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target.
// Since the answer may be too large, return it modulo 109 + 7.

// BRUTE FORCE:
// The idea is to generate all non emepty sub sequences from the array, compute the sum of max_element and min_element and check if it
// is less than or equal to target. Atlast we return the result variable.
// T.C = O(N^2)

// EFFICIENT APPROACH:
// The idea is to sort the array. Sorting the array may change the order of elements in sub sequences but it does not affect the number
// of sub sequence. So once we sort it, we maintains two pointers left (initialized to 0) and right (initialized to n-1). We simply follow the two sum approach.
// At any point, if sum of elements at left and right pointers is greater than target, we decrement the right pointer to get a sum
// which is less than or equal to target. If the sum is less than or equal to target, we need to find the number of sub sequences that
// can be formed by elements in the bounds of left and right. This is given by 2^(right-left), We add this to the result variable. And return result
// variable at last.

int noOfSubsequences(vector<int> &nums, int target){
    int n = nums.size();
    vector<int> pow2(n);
    int mod = (int)(1e9 + 7);
    pow2[0] = 1;
    for(int i=1; i<n; i++){
        pow2[i] = (pow2[i-1] * 2)%mod;
    }
    sort(nums.begin(), nums.end());
    int left = 0, right = n-1, res = 0;
    while(left <= right){
        if(nums[left]+nums[right] <= target){
            res = (res + pow2[right-left])%mod;
            left++;
        }
        else right--;
    }
    return res;
}

// T.C = O(N)



