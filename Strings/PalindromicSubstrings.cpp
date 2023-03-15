// 647. Palindromic Substrings
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.


int countSubstrings(string s){
    int n = s.length();
    if(n < 2) return n;
    int low, high, ans = 0;
    for(int i = 0; i < n; i++){
        low = i-1, high = i+1;
        while(low >= 0 && high < n && s[low] == s[high]){
            low--;
            high++;
        }
        int len = high - low - 1;
        ans += (len+1)/2;
        low = i, high = i+1;
        while(low >= 0 && high < n && s[low] == s[high]){
            low--;
            high++;
        }
        int len = high - low - 1;
        ans += (len+1)/2;
    }
    return ans;
}


// Time Complexity : O(n^2)
// Space Complexity : O(1)


