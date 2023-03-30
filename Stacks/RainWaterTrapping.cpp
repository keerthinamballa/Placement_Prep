// 42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

int trap(vector<int>& heights){
    int n = heights.size();
    int res = 0;
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()] < heights[i]){
            int pop_height = heights[st.top()];
            st.pop();
            if(st.empty()) break;
            int width = i - st.top() - 1;
            int min_height = min(heights[st.top()], heights[i]) - pop_height;
            res += min_height*width;
        }
        st.push(i);
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

