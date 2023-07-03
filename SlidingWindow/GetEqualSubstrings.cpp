// 1208. Get Equal Substrings Within Budget
// You are given two strings s and t of the same length and an integer maxCost.
// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

int equalSubstring(string s, string t, int maxCost){
    int n = s.length();
    int left = 0, right = 0, res = 0, cost = 0;
    while(right < n){
        if(s[right] != t[right]){
            cost += abs(s[right] - t[right]);
        }
        while(cost > maxCost){
            cost -= abs(s[left] - t[left]);
            left++;
        }
        res = max(res, right-left+1);
        right++;
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(1)





