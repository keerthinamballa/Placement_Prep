// 424. Longest Repeating Character Replacement
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

int characterReplacement(int k, string s){
    int n = s.length();
    int left = 0, right = 0;
    int maxFreq = 0, res = 0;
    vector<int> freq(26, 0);
    while(right < n){
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right]-'A']);
        if(right-left+1-maxFreq > k){
            freq[s[left]-'A']--;
            left++;
        }
        res = mx(res, right-left+1);
        right++;
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(26) ~ O(1)

