// 42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// BRUTE FORCE APPROACH : 

// The idea is to find the next greater bar on left and right and find the minimum out of them and get the trapped water out of it.
// The effective height of water that can be stored at any index is min(height[left], height[right]) - height[i], multiplied by the width
// and add to the result variable and return the result variable at last.
// T.C = O(N^2)

// BETTER APPROACH:

// The idea is to maintain maxLeft and maxRight array that stores the max height of the bar that is present on the right or left of the that index.
// At the end traverse the heights array and get the max water stored at each level using the same procedure as above.

int trap(vector<int> &height){
    int n = height.size();
    vector<int> maxLeft(n);
    vector<int> maxRight(n);
    maxLeft[0] = height[0];
    for(int i=1; i<n; i++){
        maxLeft[i] = max(maxLeft[i-1], height[i]);
    }
    maxRight[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--){
        maxRight[i] = max(maxRight[i+1], height[i]);
    }

    int res = 0;
    for(int i=0; i<n; i++){
        res += min(maxLeft[i], maxRight[i]) - height[i];
    }
    return res;
}

// T.C = O(N)
// S.C = O(N)

// OPTIMIZED SOLUTION:

int trap(vector<int> &nums){
    int n = nums.size();
    int left = 0, right = n-1;
    int maxLeft = 0, maxRight = 0;
    int res = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] > maxLeft) maxLeft = height[left];
            else res += maxLeft - height[left];
            left++;
        }

        else{
            if(height[right] > maxRight) maxRight = height[right];
            else res += maxRight - height[right];
            right--;
        }
    }
    return res;
}

// T.C = O(N)
//S.C = O(1)

