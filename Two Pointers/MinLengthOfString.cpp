// 1750. Minimum Length of String After Deleting Similar Ends
// Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
// -> Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
// -> Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
// -> The prefix and the suffix should not intersect at any index.
// -> The characters from the prefix and suffix must be the same.
// -> Delete both the prefix and the suffix.
// Return the minimum length of s after performing the above operation any number of times (possibly zero times).

// APPROACH:
// The idea is to maintain two pointers left and right. We run a loop while left is less than right and the characters at both ends
// match. We skip all the similar elements on both ends by incrementing the left pointer and decrementing right pointer.
// In this way we can find out the string with minimum length with different ends.

int minLengthOfString(string s){
    int n = s.length();
    int left = 0, right = n-1;
    while(left < right && s[left] == s[right]){
        char ch = s[left];
        while(left <= right && s[left] == ch) left++;
        while(left < right && s[right] == ch) right--;
    }
    return right-left+1;
}

// T.C = O(N)




