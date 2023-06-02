// Find all permutations of a string in C++

void find(int ind, string s, vector<string> &ans){
    if(ind == s.length()){
        ans.push_back(s);
        return;
    }

    for(int i=ind; i<s.length(); i++){
        swap(s[ind], s[i]);
        find(ind+1, s, ans);
        swap(s[ind], s[i]);
    }
}

vector<string> permutations(string s){
    vector<string> ans;
    find(0, s, ans);
    return ans;
}

// Time complexity : exponential
