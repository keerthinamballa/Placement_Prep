// 97. Interleaving String
// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
// An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
// substrings respectively, such that:
// -> s = s1 + s2 + ... + sn
// -> t = t1 + t2 + ... + tm
// -> |n - m| <= 1
// -> The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

// Using memoization:

bool check(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& m){
    if(m[i][j] != -1) return m[i][j];
    if(i == s1.length() && j == s2.length() && k == s3.length()) return true;
    bool x = flase, y = false;
    if(i != s1.length()){
        if(s1[i] == s3[k]) x = check(s1, s2, s3, i+1, j, k+1, m);
    }
    if(j != s2.length()){
        if(s2[j] == s3[k]) y = check(s1, s2, s3, i, j+1, k+1, m);
    }
    return m[i][j] = x || y;
}


bool isInterleave(string s1, string s2, string s3){
    int a = s1.length(), b = s2.length(), c = s3.length();
    if(a+b != c) return false;
    vector<vector<int>> m(a+1, vector<int>(b+1, -1));
    return check(s1, s2, s3, 0, 0, 0, m);
}


// Using Tabulation:

bool isInterleave(string s1,string s2, string s3){
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    if(n1+n2 != n3) return false;
    vector<vector<bool>> dp(n1+1, vector<bool>(n2+1));
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(i == 0 && j == 0) dp[i][j] =true;
            else if(i == 0){
                dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
            }
            else if(j == 0){
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
            }
            else{
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
    }
    return dp[n1][n2];
}


// Time Complexity : O(n^2)
// Space Complexity : O(n^2)





