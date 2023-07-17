// 11. Container With Most Water
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// BRUTE FORCE:

int maxArea(vector<int> &height){
    int n = height.size();
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int area = (j-i)*min(height[i], height[j]);
            res = max(res, area);
        }
    }
    return res;
}

// T.C = O(n^2)

// USING TWO POINTERS.

int maxArea(vector<int> &height){
    int n = height.size();
    int left = 0, right = n-1;
    int res = 0;
    while(left < right){
        int area = (right -left) * min(height[right], height[left]);
        res = max(res, area);
        if(height[left] <= height[right]) left++;
        else right--;
    }
    return res;
}

// T.C = O(N)
