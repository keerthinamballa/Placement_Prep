// Rabin Karp Pattern Searching Algorithm

#define d 256
vector<int> search(string txt, string pat, int q){
    vector<int> res;
    int n = txt.length(), m = pat.length();
    int i, j;
    int p=0, t=0, h=1;
    for(int i=0; i<m-1; i++){
        h = (h*d)%q;
    }
    for(int i=0; i<m; i++){
        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;
    }

    for(int i=0; i<= n-m; i++){
        if(p == t){
            for(j = 0; j<m; j++){
                if(txt[i+j] != pat[j]) break;
            }
            if(j == m) res.push_back(i);
        }
        if(i < n-m){
            t = (d*(t - txt[i]*h) + txt[i+m]) % q;
            if(t < 0) t = t+q;
        }
    }
    return res;
}

// Time Complexity : O((n-m+1)*m) (But better than naive approach)
// Space Complexity : O(1)

