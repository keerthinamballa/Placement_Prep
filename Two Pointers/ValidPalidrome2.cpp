// 680. Valid Palindrome II
// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// APPROACH:

// Here it is mentioned that we can delete atmost one character, which means if the given string is palindrome by itself, we do not
// need to delete any character. But if the given string is not a palindrome, we can delete one character to make it a palindrome.
// But even after deleting one character, if the string is not a palindrome, we return false.
// The idea is to maintain two pointers, say left and right. We traverse the string using these two pointers while(left <= right),
// at any point if the character at left index and right index do not match, we have two options.
// Either delete left character or delete right character.
// The task is to choose the character to delete which makes the resulting string a palindrome.
// We try out both ways and check if the resulting string is palindrome or not.
// If in either way we cannot get a palindrome, return false, else return true.

bool validPalindrome(string s){
    int n = s.length();
    int left = 0, right = n-1;
    while(left <= right){
        if(s[left] != s[right]){
            return isPalindrome(left+1, right, s) || isPlindrome(left, right-1, s);
        }
        left++;
        right--;
    }
    return true;
}

bool isPalindrome(int left, int right, string s){
    while(left <= right){
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// T.C = O(N)
