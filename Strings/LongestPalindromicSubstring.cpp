// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.


string expand(string str, int low, int high){
    while(low >= 0 && high < str.length() && (str[low] == str[high])){
        low--; high++;
    }
    return str.substr(low+1, high-low-1);
}


string longestPalindrome(string s){
    int n = s.length();
    int curr_len, max_len = 0;
    string curr_str,max_str = "";
    for(int i=0; i<n; i++){
        curr_str = expand(s, i, i);
        curr_len = curr_str.length();
        if(curr_len > max_len){
            max_len = curr_len;
            max_str = curr_str;
        } 

        curr_str = expand(s, i, i+1);
        curr_len = curr_str.length();
        if(curr_len > max_len){
            max_len = curr_len;
            max_str = curr_str;
        }
    }
    return max_str;
}


// Time Complexity : O(n^2)
// Space Complexity : O(n)

