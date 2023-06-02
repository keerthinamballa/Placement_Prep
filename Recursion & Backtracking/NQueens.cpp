// Print all possible solutions to N–Queens problem
// The N–queens puzzle is the problem of placing N chess queens on an N × N chessboard so that no two queens threaten each other. Thus, the solution requires that no two queens share the same row, column, or diagonal.

bool isSafe(int row, int col, vector<string> &board, int n){
    int r = row, c = col;

    while(row >=0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> & board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> nQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string(n, '.');
    for(int i=0; i<n; i++){
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}

// Time Complexity: exponential
// Space Complexity : O(n)

