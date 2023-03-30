// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// -> Open brackets must be closed by the same type of brackets.
// -> Open brackets must be closed in the correct order.
// -> Every close bracket has a corresponding open bracket of the same type.
 

bool matching(char a, char b){
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool validParentheses(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else{
            if(st.empty()) return false;
            else if(!matching(st.top(), s[i])) return false;
            st.pop();
        }
    }
    return st.empty();
}

// Time Complexity : O(n)
// Space Complexity : O(n)
