// 905. Sort Array By Parity
// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.

//BRUTE FORCE:

// One way to solve this could be to run two loops. The outer loop runs from 0 to n(length of the array). If any element of the array is odd
// we run the inner loop from i+1 to n, to find an even number and swap them both.
// This is continued till the end and finally we will have an array sorted by parity.

// The time cmplexity is O(N^2)

// OPTIMIZED SOLUTION:

// It is give that the elements of the array can be in any order and even parity elements should appear first and then the odd parity elements.
// So, we can use the two-pointers approach. 
// Declare two pointers left to 0 and right to n-1. And maintain a result array.
// Now start traversing the array from left to right. If the current element is even, insert it in the left side of the result array and increment
// the left pointer, if the elements is of odd parity insert it on the right and decrement the right pointer.
// Atlast return the result array.

vector<int> sortByParity(vector<int> &nums){
    int n = nums.size();
    int left = 0, right = n-1;
    vector<int> res(n);
    for(int i=0; i<n; i++){
        if(nums[i] % 2 == 0){
            res[left++] = nums[i];
        }
        else{
            res[right--] = nums[i];
        }
    }
    return res;
}

// T.C = O(N)


