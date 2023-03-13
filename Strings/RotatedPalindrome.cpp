// Check if a string is a rotated palindrome or not
// Given a string, check if it is a rotated palindrome or not.


bool expand(string& str, int low, int high, int k){
    while(low >= 0 && high < str.length() && str[low] == str[high]){
        if(high - low + 1 == k) return true;
    }
    return false;
}


bool longestPalindrome(string str, int k){
    for(int i=0; i<str.length()-1; i++){
        if(expand(str, i, i, k) || expand(str, i, i+1, k)) return true;
    }
    return false;
}


bool rotatedPalindrome(string s){
    int n = s.length();
    return longestPalindrome(s + s, n);
}


// Time Complexity : O(n^2)
// Space Complexity : O(1)


