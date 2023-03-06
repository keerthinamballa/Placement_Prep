// 42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

int trap(vector<int>& height){
    int n = height.size();
    int res = 0;
    int left = 0, right = n-1;
    int maxLeft = height[left], maxRight = height[right];
    while(left < right){
        if(height[left] <= height[right]){
            left++;
            maxLeft = max(maxLeft, height[left]);
            res += maxLeft - height[left];
        }
        else{
            right--;
            maxRight = max(maxRight, height[right]);
            res += maxRight - height[right];
        }
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(1)



