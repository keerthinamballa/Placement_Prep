// Naive Pattern Searching Algorithm

vector<int> patSearching(string txt, string pat){
    vector<int> res;
    int n = txt.length(), m = pat.length();
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(pat[j] != txt[i+j]) break;
        }
        if(j == m) res.push_back(i);
    }
    return res;
}

// Time Complexity : O((n-m+1)*m)
// Space Complexity : O(1)


