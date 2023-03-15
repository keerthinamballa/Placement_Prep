// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


bool isIsomorphic(string s, string t){
    if(s.length() != t.length()) return false;
    unordered_map<char, char> m;
    unordered_set<char> k;
    for(int i=0; i<s.length(); i++){
        if(m.find(s[i]) != m.end()){
            if(m[s[i]] != t[i]) return false;
        }
        else{
            if(k.find(t[i]) != k.end()) return false;
            m[s[i]] = t[i];
            k.insert(t[i]);
        }
    }
    return true;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

