Longest Span in two Binary Arrays
Given two binary arrays arr1[] and arr2[] of same size N. Find length of the longest common span [i, j] where j>=i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j].

int longestSpan(vector<bool>& nums1, vector<bool>& nums2){
    int n = nums1.size();
    int sum1 = 0, sum2 = 0;
    int res  = 0;
    m[0] = -1;
    unordered_map<int, int> m;
    for(int i = 0; i<n; i++){
        sum1 += nums1[i];
        sum2 += nums2[i];
        int diff = sum1 - sum2;
        if(diff == 0) res = i;
        if(m.find(diff) == m.end()){
            m[diff] = i;
        }
        else if(m.find(diff) != m.end()){
            res = max(res, i-m[diff]);
        }
    }
    return res;
}


// Time Complexity : O(n)
// Space Complexity : O(n)


