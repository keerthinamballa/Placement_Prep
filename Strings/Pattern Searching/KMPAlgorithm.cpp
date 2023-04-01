// KMP Pattern Searching Algorithm

vector<int> getLPS(string s){
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[len]){
            lps[i] = ++len;
        }
        else if(len > 0){
            len = lps[len - 1];
            --i;
        }
    }
    return lps;
}

vector<int> KMPSearch(string txt, string pat){
    vector<int> res;
    int n = txt.size(), m = pat.size();
    vector<int> lps = getLPS(pat);
    int i=0, j=0;
    while((n-i) <= (m-j)){
        if(pat[j] == txt[i]){
            j++;
            i++;
        }
        if(j == m){
            res.push_back(i-j);
            j = lps[j-1];
        }
        else if(i < n && pat[j] != txt[i]){
            if(j != 0) j = lps[j-1];
            else i = i+1;
        }
    }
    return res;
}


// Time Complexity : O(n)
// Space Complexity : O(n)
