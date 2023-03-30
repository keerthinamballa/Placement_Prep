// Stock span problem
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
// The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.


vector<int> stockSpan(vector<int>& price){
    int n = price.size();
    vector<int> res;
    stack<int> s;
    res.push_back(1);
    s.push(0);
    for(int i=1; i<n; i++){
        while(!s.empty() && price[s.top()] <= price[i]){
            s.pop();
        }
        int k = (s.empty()) ? i+1 : i - s.top();
        res.push_back(k);
        s.push(i);
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

