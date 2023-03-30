// 227. Basic Calculator II
// Given a string s which represents an expression, evaluate this expression and return its value. 
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


int calculate(string s){
    int n = s.length();
    stack<int> st;
    char sign = '+';
    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            int val = 0;
            while(i < n && isdigit(s[i])){
                val = val*10 + (s[i] - '0');
                i++;
            }
            i--;
            if(sign == '+') st.push(val);
            else if(sign == '-') st.push(-val);
            else if(sign == '*'){
                int a = st.top();
                st.pop();
                int ans = a*val;
                st.push(ans);
            }
            else if(sign == '/'){
                int a = st.top();
                st.pop();
                int ans = a/val;
                st.push(ans);
            }
        }
        else if(s[i] != ' '){
            sign = s[i];
        }
    }
    int res = 0;
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
