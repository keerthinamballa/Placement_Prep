// Reverse array in groups
// Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

void reverseInGroups(vector<long long>& arr, int n, int k){
    for(int i = 0; i<n; i++){
        int left = i, right = min(i+k-1, n-1);
        while(left < right){
            swap(arr[left++], arr[right--]);
        }
    }
}

// Time Complexity : O(n)
// Space Complexity : O(1)


