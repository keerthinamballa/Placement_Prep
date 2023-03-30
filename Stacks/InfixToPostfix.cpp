// Infix to Postfix
// Given an infix expression in the form of string str. Convert this infix expression to postfix expression.
// -> Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
// -> Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
// Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 


int prec(char a){
    if(a == '^') return 3;
    else if(a == '*' || a == '/') return 2;
    else if(a == '+' || a == '-') return 1;
    else return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string res;
    for(char c : s){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c<='Z') || (c >= '0' && c <= '9')){
            res+=c;
        }
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(st.top() != ')'){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(c) <= prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
