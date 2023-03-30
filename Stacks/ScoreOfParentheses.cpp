// 856. Score of Parentheses
// Given a balanced parentheses string s, return the score of the string.
// The score of a balanced parentheses string is based on the following rule:
// -> "()" has score 1.
// -> AB has score A + B, where A and B are balanced parentheses strings.
// -> (A) has score 2 * A, where A is a balanced parentheses string.
 

int scoreOfParentheses(string s){
    int score = 0;
    stack<int> st;
    for(char c : s){
        if(c == '('){
            st.push(score);
            score = 0;
        }
        else{
            score = st.top() + max(2*score, 1);
            st.pop();
        }
    }
    return score;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


