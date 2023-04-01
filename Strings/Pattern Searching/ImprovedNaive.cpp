// Improved naive approach valid only when there are distinct characters in pattern

vector<int> patSearch(string txt, string pat){
    int n = txt.length(), m = pat.length();
    vector<int> res;
    for(int i=0; i<=n-m; ){
        int j;
        for(j=0; j<m; j++){
            if(pat[j] != txt[i+j]) break;
        }
        if(j==m) res.push_back(i);
        i(j == 0) i++;
        else i = i+j;
    }
    return res;
}

// Time Complexity : O((n-m+1)*m)
// Space Complexity : O(1)
