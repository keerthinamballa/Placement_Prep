// 224. Basic Calculator
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


int calculate(string s){
    int n = s.length();
    stack<int> st;
    int sum = 0, sign = 1;
    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            int val = 0;
            while(i < n && isdigit(s[i])){
                val = val*10 + (s[i] - '0');
                i++;
            }
            i--;
            val = sign*val;
            sign = 1;
            sum += val;
        }
        else if(s[i] == '('){
            st.push(sum);
            st.push(sign);
            sum = 0;
            sign = 1;
        }
        else if(s[i] == ')'){
            sum *= st.top();
            st.pop();
            sum += st.top();
            st.pop();
        }
        else if(s[i] == '-'){
            sign *= -1;
        }
    }
    return sum;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


