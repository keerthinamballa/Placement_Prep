// 345. Reverse Vowels of a String
// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// The idea is to find vowels on either side of the string and keep swapping them.
// So we traverse in the left using left pointer. If the left pointer is not a vowel we increment it.
// We traverse on the right side using right pointer, If the right pointer does not point to a vowel, decrement.
// The momemt when both left and right pointers are vowels, we swap it and decrement right point pointer and increment left pointer
// to find such pairs further.

void reverseVowels(string s){
    int n = s.length();
    int left = 0, right = n-1;
    while(left < right){
        if(!isVowel(s[left])) left++;
        if(!isVowel(s[right])) right--;
        if(isVowel(s[left]) && isVowel(s[right])){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
}

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
    return false;
}

// T.C = O(N)

