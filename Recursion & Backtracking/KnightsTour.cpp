// Print all possible Knight’s tours on a chessboard
// Given a chessboard, print all sequences of moves of a knight on a chessboard such that the knight visits every square only once.

void solve(int i, int j, int pos, vector<vector<int> &sol, int di[], int dj[], vector<vector<vector<int>>> &ans, int n){
    if(pos > n*n){
        ans.push_back(sol);
        return;
    }

    for(int k=0; k<8; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(ni >= 0 && nj >= 0 && ni < n && nj < n && sol[ni][nj] == 1){
            sol[ni][nj] = pos;
            solve(ni, nj, pos+1, sol, di, dj, ans, n);
            sol[ni][nj] = 0;
        }
    }
}

vector<vector<vector<int>>> knightsTour(int n){
    vector<vector<vector<int>>> ans;
    vector<vector<int>> sol(n, vector<int>(n, 0));
    int di[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dj[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
    sol[0][0] = 1;
    solve(0, 0, 2, sol, di, dj, ans, n);
    return ans;
}

// Time Complexity : exponential

