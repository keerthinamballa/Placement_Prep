// Duplicate Parenthesis
// Given a balanced expression that can contain opening and closing parenthesis, check if it contains any duplicate parenthesis or not.

bool hasDuplicate(string s){
    int n = s.length();
    stack<char> st;
    if(n <= 3) return false;
    for(int i=0; i<n; i++){
        if(s[i] != ')') st.push(s[i]);
        else{
            if(st.top() == '(') return true;
            while(!st.empty() && st.top() != '(') st.pop();
            st.pop();
        }
    }
    return false;
}

// Time Complexity : O(n)
// Space Complexity : O(n) 
