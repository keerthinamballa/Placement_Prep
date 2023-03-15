// 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).


double medianOfSorted(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size() > nums2.size()) return medianOfSorted(nums2, nums1);
    int start = 0, end = nums1.size();
    while(start <= end){
        int div1 = start + (end-start)/2;
        int div2 = (nums1.size() + nums2.size() + 1)/2;
        int l1 = (div1 == 0) ? INT_MIN : nums1[div1 - 1];
        int l2 = (div2 == 0) ? INT_MIN : nums2[div2 - 1];
        int r1 = (div1 == nums1.size()) ? INT_MAX : nums1[div1];
        int r2 = (div2 == nums2.size()) ? INT_MAX : nums2[div2];

        if(l1 <= r2 && l2 <= r1){
            if((nums1.size() + nums2.size()) & 1)
                return (double) max(l1,l2);
            else
                return double(max(l1,l2) + min(r1,r2))/2;
        }
        else if(l1 > r2) end = div1-1;
        else start = div1+1;
    }
    return -1.0;
}

// Time Complexity : O(log(min(m,n)))
// Space Complexity : O(1)


 