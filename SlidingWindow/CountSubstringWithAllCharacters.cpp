// 1358. Number of Substrings Containing All Three Characters
// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

int countSubstrings(string s){
    int n = s.length();
    int left = 0, right = 0, res = 0;
    unordered_map<char, int> m;
    while(right < n){
        m[s[right]]++;
        while(m['a'] && m['b'] && m['c']){
            res += n-end;
            m[s[left]]--;
            left++;
        }
        right++;
    }
    return res
}

// T.C = O(N)
// S.C = O(1)

