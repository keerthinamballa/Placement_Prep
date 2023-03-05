// Merge two arrays by satisfying given constraints
// Given two sorted arrays X[] and Y[] of size m and n each where m >= n and X[] has exactly n vacant cells, merge elements of Y[] in their correct position in array X[], i.e., merge (X, Y) by keeping the sorted order.

// The idea is to rearrange and move non-empty elements in X[] and then sort with Y[]

void rearrange&Merge (vector<int>& x, vector<int>& y){
    int m = x.size(), n = y.size();
    if(m == 0) return;
    int k = 0;
    for(int i=0; i<m; i++){
        if(x[i] != 0){
            x[k++] = x[i];
        }
    }
    merge(x, y, k, n)
}

void merge(vector<int>& x, vector<int>& y, int m, int n){
    int i = m-1, j = n-1;
    int k = m+n-1;
    while(i >= 0 && j >= 0){
        if(y[j] >= x[i]) x[k--] = y[j--];
        else x[k--] = x[i--];
    }
    while(j >= 0) x[k--] = y[j--];
}

