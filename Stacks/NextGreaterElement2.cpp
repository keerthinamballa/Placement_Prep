// 503. Next Greater Element II
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.


vector<int> nextGreater(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> res;
    for(int i=n-2; i>=0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        st.push(nums[i]);
    }
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(st.empty()) res.push_back(-1);
        else res.push_back(st.top());
        st.push(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


