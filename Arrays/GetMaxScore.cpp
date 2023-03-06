// 1537. Get the Maximum Score
// You are given two sorted arrays of distinct integers nums1 and nums2.
// A valid path is defined as follows:
// ->Choose array nums1 or nums2 to traverse (from index-0).
// ->Traverse the current array from left to right.
// ->If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
// The score is defined as the sum of uniques values in a valid path.
// Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 109 + 7.


int maxScore(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size(), m = nums2.size();
    int i=0, j=0;
    long sum1 = 0, sum2 = 0, res = 0, mod = 1e9 + 7;
    while(i < n && j < m){
        if(nums1[i] < nums2[j]) sum1 += nums1[i++];
        else if(nums2[j] < nums1[i]) sum += nums2[j++];
        else{
            res += max(sum1, sum2) + nums1[i];
            sum1 = 0;
            sum2 = 0;
            i++; j++;
        }
    }
    while(i < n) sum1 += nums1[i++];
    while(j < m) sum2 += nums2[j++];
    res += max(sum1, sum2);
    return res % mod;
}


// Time Complexity : O(n)
// Space Complexity : O(1)


