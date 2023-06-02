// Find the total number of unique paths in a maze from source to destination
// Find the total number of unique paths that the robot can take in a given maze to reach a given destination from a given source.

void solve(int i, int j, vector<vector<int>> &m, int n, int &count, int di[], int dj[]){
    if(i == n-1 && j == n-1){
        count++;
        return;
    }

    m[i][j] = 2;
    for(int k=0; k<4; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(ni >=0 && ni < n && nj>=0 && nj<n && m[ni][nj] == 1){
            solve(ni, nj, m, n, count, di, dj);
        }
    }
    m[i][j] = 1;
}

int countPaths(vector<vector<int>> &m){
    int n = m.size();
    if(n == 0 || m[0][0] == 0 || m[n-1][n-1] == 0) return 0;
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    int count = 0;
    solve(0, 0, m, n, count, di, dj);
    return count;
}


// Time Complexity : exponential

