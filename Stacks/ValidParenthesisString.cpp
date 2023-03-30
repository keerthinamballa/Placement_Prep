// 678. Valid Parenthesis String
// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// 1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// 2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
// 3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// 4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


bool checkValidString(string s){
    int cmax = 0, cmin = 0;
    for(char c : s){
        if(c == '('){
            cmax++;
            cmin++;
        }
        else if(c == ')'){
            cmax--;
            cmin--;
        }
        else if(c == '*'){
            cmax++;
            cmin--;
        }
        if(cmax < 0) return false;
        cmin = max(cmin, 0);
    }
    return cmin==0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


