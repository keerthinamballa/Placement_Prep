// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


//USING RECURSION


void solve(string s, int index, string op, vector<string>& res, string phone[]){
    if(index >= s.length()){
        res.push_back(op);
        return;
    }
    int n = s[index] - '0';
    string val = phone[n];
    for(int i=0; i<val.length(); i++){
        op.push_back(val[i]);
        solve(s,index+1, op, res, phone);
        op.pop_back();
    }
}

vector<string> letterCombinations(string s){
    int n = s.length();
    vector<string> res;
    if(n == 0) return res;
    string phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index;
    solve(s, index, "", res, phone);
    return res;
}

Time Complexity : O(3^n);
Space Complexity : O(3^n)



