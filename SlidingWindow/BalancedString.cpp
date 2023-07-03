// 1234. Replace the Substring for Balanced String
// You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
// A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.

int minReplacements(string s){
    int n = s.length();
    int left = 0, right = 0, res = 0;
    unordered_map<char, int> m;
    for(auto it : s){
        m[it]++;
    }

    while(right < n){
        m[s[right]]--;
        while(left < n && m['Q'] && m['W'] && m['E'] && m['R']){
            res = min(res, right-left+1);
            m[s[left]]++;
            left++;
        }
        right++;
    }
    return res;
}

// T.C = O(N)
// S.C = O(N)


