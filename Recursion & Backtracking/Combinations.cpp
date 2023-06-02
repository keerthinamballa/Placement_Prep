// Find all combinations of elements satisfying given constraints
// Given a positive number n, find all combinations of 2×n elements such that every element from 1 to n appears exactly twice and the distance between its two appearances is exactly equal to the value of the element.

void find(int x, vector<int> &arr, vector<vector<int>> &ans, int n){
    if(x > n){
        ans.push_back(arr);
        return;
    }

    for(int i=0; i<2*n; i++){
        if(arr[i] == -1 && i+x+1 < 2*n && arr[i+x+1] == -1){
            arr[i] = x;
            arr[i+x+1] = x;
            find(x+1, arr, ans, n);
            arr[i] = x;
            arr[i+x+1] = x;
        }
    }
}

int combinations(int n){
    vector<vector<int>> ans;
    vector<int> arr(2*n, -1);
    find(x, arr, ans, n);
    return ans;
}

// Time Complexity : O(n)

