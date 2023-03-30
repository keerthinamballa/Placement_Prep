// 84. Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


int maxArea(vector<int>& heights){
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;
    for(int i=0; i<=n; i++){
        int currHeight = (i == n) ? 0 : heights[i];
        while(!st.empty() && currHeight < heights[i]){
            int top = st.top();
            st.pop();
            int width = (st.empty()) ? i : i - st.top() - 1;
            maxArea = max(maxArea, heights[i]*width);
        }
        st.push(i);
    }
    return maxArea;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

