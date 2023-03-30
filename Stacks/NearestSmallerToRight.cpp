// Actual Algorithm

vector<int> nsr(vector<int>& arr){
    int n = arr.size();
    vector<int> res;
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        if(st.empty()) res.push_back(-1);
        else if(!st.empty() && arr[i] > st.top()){
            res.push_back(st.top());
        }
        else if(!st.empty() && arr[i] <= st.top()){
            while(!st.empty() && arr[i] <= st.top()){
                st.pop();
            }
            if(st.empty()) res.push_back(-1);
            else res.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


// 1475. Final Prices With a Special Discount in a Shop
// You are given an integer array prices where prices[i] is the price of the ith item in a shop.
// There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.
// Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.


vector<int> finalPrices(vector<int>& prices){
    int n = prices.size();
    vector<int> res;
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        if(st.empty()) res.push_back(prices[i]);
        else if(!st.empty() && prices[i] >= st.top()){
            res.push_back(prices - st.top());
        }
        else if(!st.empty() && prices[i] < st.top()){
            while(!st.empty() && prices[i] < st.top()){
                st.pop();
            }
            if(st.empty()) res.push_back(prices[i]);
            else res.push_back(prices[i] - st.top());
        }
        st.push(prices[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


