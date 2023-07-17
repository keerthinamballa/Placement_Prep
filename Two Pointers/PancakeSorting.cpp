// 969. Pancake Sorting
// Given an array of integers arr, sort the array by performing a series of pancake flips.
// In one pancake flip we do the following steps:
// -> Choose an integer k where 1 <= k <= arr.length.
// -> Reverse the sub-array arr[0...k-1] (0-indexed).
// For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
// Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.

// APPROACH:
// One way to do this can be to find the max element in the array, first reverse the array from the index of max element so that
// max element comes to the beginning and then reverse it to get it into the correct place.
// Do this for all the numbers and every time you push the index chosen for reversing or flipping into the result array.
// Atlast return the result array.

vector<int> pancakeSorting(vector<int> &nums){
    int n = nums.size();
    int largest = n;
    vector<int> res;
    for(int i=0; i<n; i++){
        int idx = find(nums, largest);
        reverse(nums.begin(), nums.begin()+idx+1);
        reverse(nums.begin(), nums.begin()+largest);
        res.push_back(idx + 1);
        res.push_back(largest);
        largest--;
    }
    return res;
}

// T.C = O(N^2)



