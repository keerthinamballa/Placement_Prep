// Evaluation of Postfix Expression
// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

int evaluatePostfix(string s){
    stack<int> st;
    for(char c : s){
        if(c >= '0' && c <= '9'){
            st.push(c - '0');
        }
        else{
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if(c == '+'){
                st.push(y+x);
            }
            else if(c == '-'){
                st.push(y-x);
            }
            else if(c == '*'){
                st.push(y*x);
            }
            else if(c == '/'){
                st.push(y/x);
            }
        }
    }
    return st.top();
}

// Time Complexity : O(n)
// Space Complexity : O(n)
