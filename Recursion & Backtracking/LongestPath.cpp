// Find the longest possible route in a matrix
// Given a rectangular path in the form of a binary matrix nxn, find the length of the longest possible route from source to destination by moving to only non-zero adjacent positions, i.e., We can form the route from positions having their value as 1. Note there should not be any cycles in the output path.

void solve(int i, int j, vector<vector<int>> &m, int n, int dist, int &res, int di[], int dj[]){
    if(i == n-1 && j == n-1) {
        res = max(res, dist);
        return;
    }

    m[i][j] = 2;
    for(int k=0;k < 8; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(ni >=0 && ni < n && nj >=0 && nj<n && m[ni][nj] == 1){
            solve(ni, nj, m, n, dist+1, res, di, dj);
        }
    }
    m[i][j] = 1;
}

int longestPath(vector<vector<int>> &m){
    int n = m.size();
    if(n == 0 || m[0][0] == 0 || m[n-1][n-1] == 0) return -1;
    int di[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dj[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int res = INT_MAX;
    solve(0, 0, m, n, 1, res, di, dj);
    if(res!= INT_MAX) return res;
    return -1;
}

// Time Complexity :  exponential

