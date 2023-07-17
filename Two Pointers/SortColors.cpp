// 75. Sort Colors
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// BRUTE FORCE:

// The idea is to use any sorting algorithm, efficient ones would be merge sort or quick sort. 
// Quick sort is in-place and efficient where we partition the array upon a pivot and place all the elements lesser than that on the left of
// it and all the elements greater on the right. This would take a time complexity O(NlogN) and no extra space.

// EFFICIENT APPROACH:

// The idea is to use Dutch National Flag Algorithm where we basically maintain three pointers left, right, mid and it is basically used to sort
// an array with three distinct elements. The approach would be to initialize left and mid to extreme left i.e; index 0 initially and right pointer
// to extreme right i.e; n-1 where n is the length of the array.
// We traverse the elements of the array when mid <= right, and here it is given the three distinct elements are 0, 1, 2.
// On sorting the array we find all the occurences of 0 in the beginning, all occurences of 1 after that and all occurences of 2 at the end.
// Accordingly if we find the current element is 0, we swap it with element at left index and increment left pointer.
// If the current element is 1, we simply increment mid pointer
// and similar is the case with 2.

void sort(vector<int> &nums){
    int n = nums.size();
    int left = 0, mid = 0, right = n-1;
    while(mid <= right){
        if(nums[mid] == 0){
            swap(nums[left], nums[mid]);
            left++;
            mid++;
        }

        else if(nums[mid] == 1) mid++;
        else{
            swap(nums[right], nums[mid]);
            right--;
        }
    }
}


// T.C = O(N)



