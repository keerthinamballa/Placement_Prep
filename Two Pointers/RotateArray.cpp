// 189. Rotate Array
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// BRUTE FORCE SOLUTION:

// The idea is we can rotate an array by 1 one place by shifting the elements to the right by one place.
// We can run the loop k times to shift k elements to the right.

void rotateByOne(vector<int> &nums){
    int n = nums.size();
    int temp = nums[n-1];
    for(int i=1; i<n; i++){
        nums[i] = nums[i-1] 
    }
    nums[0] = temp;
}

void rotateByK(vector<int> &nums, int k){
    int n = nums.size();
    k = k%n;
    for(int i=0; i<k; i++){
        rotateByOne(nums);
    }
}

// T.C = O(N*K)

// BETTER SOLUTION:

// The idea is to use a temporary array where we store the elements in rotated form and finally copy the temporary array to
// original nums array. This can be achieved by shifting first n-k elements by k steps to the right and storing the rest of the elements in the beginning
// We run a loop from 0 to n-k, temp[i+k] = nums[i]//shifts first n-k elements by k positions.
// Next we store the elements from n-k to end of the array in the front of the temporary array.
// Finally we copy all the elements back to original nums array.

void rotate(vector<int> &nums, int k){
    int n = nums.size();
    k = k%n;
    for(int i=0; i<n-k; i++){
        temp[i+k] = nums[i];
    }
    for(int i-n-k; i<n; i++){
        int idx = (i+k)%n;
        temp[idx] = nums[i];
    }
    for(int i=0; i<n; i++){
        nums[i] = temp[i];
    }
}

// EFFICIENT SOLUTION:

// Note thet here we are rotating the array to the right.
// Consider an array [1, 2, 3, 4, 5] and saay k = 2;
// The result array would be [4, 5, 1, 2, 3].
// The algorithm is simple.
// First reverse the entire array, [5, 4, 3, 2, 1]
// Then reverse first k elements. [4, 5, 3, 2, 1]
// Then reverse the next n-k elements. [4, 5, 1, 2, 3].
// By this process we can achieve the result.
// Note for left rotation, we follow exact reverse of this.

void reverse(int left, int right, vector<int> &nums){
    while(left < right){
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

void rotate(vector<int> &nums, int k){
    int n = nums.size();
    k = k%n;
    reverse(0, n-1, nums);
    reverse(0, k-1, nums);
    reverse(k, n-1, nums);
}

// T.C = O(N)


