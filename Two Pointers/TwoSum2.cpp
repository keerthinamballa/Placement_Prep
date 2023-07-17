// 167. Two Sum II - Input Array Is Sorted
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Your solution must use only constant extra space.

// BRUTE FORCE SOLUTION:
// The idea is to run two loops. The outer loop 'i' runs from 0 to n-1 and the inner loop runs from i+1 to n-1.
// For every element at index i, find the element from index j whose sum will be equal to target. Since the array is sorted, this idea works fine.
// T.C = O(N^2)

// EFFICIENT SOLUTION:

// The idea is to use two pointers left and right. Initially, left is initialized to 0, and right is initialized to n-1.
// We run a while loop, while left is less than right, we compute the sum of elements present at left and right indices.
// If the sum is less than the required target, we increament the left pointer, the inyuition here is since the array is sorted we
// need to add a greater element to make the sum equal to target. similarly if the sum is greater than target, we decrement the right
// pointer. and when the sum is equal to target, we store the indices in an array and return it.

vector<int> twoSum(vector<int> &nums, int target){
    int n = nums.size();
    int left = 0, right = n-1;
    vector<int> res;
    while(left <= right){
        int sum = nums[left] + nums[right];
        if(sum < target) left++;
        else if(sum > target) right--;
        else{
            res.push_back(left+1, right+1);
            break;
        }
    }
    return res;
}

// T.C = O(N)
