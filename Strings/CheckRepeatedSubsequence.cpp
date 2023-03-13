// Check if a repeated subsequence is present in a string or not
// Given a string, check if a repeated subsequence is present in it or not. The repeated subsequence should have a length of 2 or more.


bool isPalindrome(string s){
    int low = 0, high = s.length()-1;
    while(low < high){
        if(s[low] != s[high]) return false;
        low++; high--;
    }
    return true;
}

bool repeatingSequence(string str){
    int n = str.length();
    if(n == 0) return false;
    unordered_map<char, int> m;
    for(int i=0; i<n; i++){
        if(++m[str[i]] >= 3) return true;
    }
    string temp;
    for(int i=0; i<n; i++){
        if(m[str[i]] >= 2) temp += str[i];
    }
    return !isPalindrome(temp);
}


// Time Complexity : O(n)
// Space Complexity : O(n)

