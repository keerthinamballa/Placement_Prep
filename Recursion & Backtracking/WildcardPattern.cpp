// Find all binary strings that can be formed from a wildcard pattern
// Given a binary pattern containing ? wildcard character at a few positions, find all possible combinations of binary strings that can be formed by replacing the wildcard character by either 0 or 1.

void find(int ind, string s, vector<string> &ans){
    if(ind == s.length()){
        ans.puah_back(s);
        return;
    }

    if(s[ind] == '?'){
        for(int k=0; k<2; k++){
            s[ind] = k+ '0';
            find(ind+1, s, ans);
            s[ind] = '?';
        }
    }
    else{
        find(ind+1, s, ans);
    }
}

vector<string> wildcardPattern(string s){
    vector<string> ans;
    find(0, s, ans);
    return ans;
}

// Time Complexity : O(2^n);
// Space Complexity : O(n)
