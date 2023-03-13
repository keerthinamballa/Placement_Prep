// 242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


bool validAnagram(string s, string t){
    vector<int> count(256, 0);
    if(s.length() != t.length()) return false;
    for(int i=0; i<s.length(); i++){
        count[s[i]]++;
        count[t[i]]--;
    }
    for(int i=0; i<s.length(); i++){
        if(count[s[i]] != 0) return false;
    }
    return true;
}

// Time Complexity : O(n)
// Space Complexity : O(1)



