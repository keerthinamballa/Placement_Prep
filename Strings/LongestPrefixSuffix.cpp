// 1392. Longest Happy Prefix
// A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

string longestPrefix(string s){
    int n = s.length();
    vector<int> lps(n);
    int len = 0;
    for(int i=1; i<len; i++){
        if(s[i] == s[len]){
            lps[i] = ++len;
        }
        else if(len > 0){
            len = lps[len-1];
            --i;
        }
    }
    return s.substr(0, len);
}

// Time Complexity : O(n)
// Space Complexity : O(n)

