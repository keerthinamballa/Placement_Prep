// Find all common elements present in each row of a matrix
// Given an M × N matrix, find all common elements present in every row.


vector<int> commonElements(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<int> res;
    unordered_map<int, int>map;
    for(int i=0;i <m; i++){
        map[mat[0][i]] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(map.find(mat[i][j]) != m.end() && map[mat[i][j]] == i){
                map[mat[i][j]] = i+1;
            }
        }
    }
    for(auto x: map){
        if(x.second == n){
            res.push_back(x.first);
        }
    }
    return res;
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)




