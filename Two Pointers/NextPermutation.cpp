// 31. Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// -> For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// BRUTE FORCE:

// One wqay to solve this problem could be to generate all permutations in lexicographically increasing order and store in a data structure say for example
// an array or vector and search for the given permutation in it and return the next permutation.

// But it is given that it shpuld be done inplace and it does not prove to be efficient as generating all permutations take N! and 
// traversing them again to find the given permutation.

// EFFICIENT APPROACH:

void nextPermutation(vector<int> &nums){
    int n = nums.size();
    int k, l;
    for(k = n-2; k>=0; k--){
        if(nums[k] < nums[k+1]) break;
    }
    if(k < 0) reverse(nums.begin(), nums.end());
    else{
        for(l = n-1; l > k; l--){
            if(nums[l] > nums[k]) break;
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin()+k+!, nums.end());
    }
}

// The idea or intuition behind it is that we can perform swap operation at the index where nums[i] < nums[i+1]. If nums[i] > nums[i+1] for
// every index then that will be lexicographically largest among all permutation. So to find the next greater permutation, we need to
// find the first breaking point from the end of the given permutation let's call the index i (breaking point index). Now we will have
// to replace it with the next bigger element on it's right. Again to find the next permuation we need to swap with slightly greater
// element on the right. swap them and reverse the sub array on the right of breaking point index.



